#include "hittablelist.h"

#include "gmock/gmock.h"

using namespace testing;


class HittableListTest : public ::testing::Test {
protected:
    HitRecord record;
    Vector3 ray_origin = Vector3(0, 0, 0);
    Vector3 forward_direction = Vector3(0, 0, 1);
    Ray ray;

    void SetUp() override {
        record = HitRecord();
        record.t = 1.0;
        ray = Ray(ray_origin, forward_direction);
    }
};

class HittableMock : public Hittable {
public:
    bool will_hit = false;

    explicit HittableMock(bool will_hit) : will_hit(will_hit) {}

    bool Hit(const Ray &ray, double t_min, double t_max, HitRecord &record) const override {
        record.t = 0.0;
        return will_hit;
    }
};

TEST_F(HittableListTest, ClearWhenNoParamsClearsTheListOfHittableObjects) {
    HittableMock hittable_mock(true);
    std::shared_ptr<Hittable> hittable = std::make_shared<HittableMock>(hittable_mock);
    HittableList list(hittable);

    list.Clear();

    ASSERT_THAT(list.objects.size(), 0);
}

TEST_F(HittableListTest, AddWhenPassingAHittableObjectAddsReferenceToList) {
    HittableMock hittable_mock(true);
    std::shared_ptr<Hittable> hittable = std::make_shared<HittableMock>(hittable_mock);
    HittableList list;

    list.Add(hittable);

    ASSERT_THAT(list.objects.size(), 1);
}

TEST_F(HittableListTest, HitIfRayCollidesWithObjectReturnsTrue) {
    HittableMock hittable_mock(true);
    std::shared_ptr<Hittable> hittable = std::make_shared<HittableMock>(hittable_mock);
    HittableList list(hittable);

    bool actual_hit = list.Hit(ray, 0.0, 0.0, record);

    ASSERT_TRUE(actual_hit);
}

TEST_F(HittableListTest, HitIfRayCollidesWithObjectUpdatesHitRecord) {
    HittableMock hittable_mock(true);
    std::shared_ptr<Hittable> hittable = std::make_shared<HittableMock>(hittable_mock);
    HittableList list(hittable);
    HitRecord actual_record = record;

    bool actual_hit = list.Hit(ray, 0.0, 0.0, actual_record);

    ASSERT_TRUE(actual_hit);
    ASSERT_NE(actual_record.t, record.t);
}

TEST_F(HittableListTest, HitIfRayDoesNotCollideWithObjectReturnsFalse) {
    HittableMock hittable_mock(false);
    std::shared_ptr<Hittable> hittable = std::make_shared<HittableMock>(hittable_mock);
    HittableList list(hittable);

    bool actual_hit = list.Hit(ray,0.0, 0.0, record);

    ASSERT_FALSE(actual_hit);
}
