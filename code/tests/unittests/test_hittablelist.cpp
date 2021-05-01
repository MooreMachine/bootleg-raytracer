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
        ray = Ray(ray_origin, forward_direction);
    }
};

class HittableMock : public Hittable {
public:
    bool will_hit = false;

    explicit HittableMock(bool will_hit) : will_hit(will_hit) {}

    bool Hit(const Ray &ray, double t_min, double t_max, HitRecord &record) const override {
        return will_hit;
    }
};

std::shared_ptr<Hittable> GetHittableObject(bool will_hit)
{
    HittableMock hittable_mock(will_hit);
    return std::make_shared<HittableMock>(hittable_mock);
}

TEST_F(HittableListTest, ClearWhenNoParamsClearsTheListOfHittableObjects) {
    std::shared_ptr<Hittable> hittable = GetHittableObject(true);
    HittableList list(hittable);

    list.Clear();

    ASSERT_THAT(list.objects.size(), 0);
}

TEST_F(HittableListTest, AddWhenPassingAHittableObjectAddsReferenceToList) {
    std::shared_ptr<Hittable> hittable = GetHittableObject(true);
    HittableList list;

    list.Add(hittable);

    ASSERT_THAT(list.objects.size(), 1);
}

TEST_F(HittableListTest, HitIfRayCollidesWithObjectReturnsTrue) {
    std::shared_ptr<Hittable> hittable = GetHittableObject(true);
    HittableList list(hittable);

    bool actual_hit = list.Hit(ray, 0.0, 0.0, record);

    ASSERT_TRUE(actual_hit);
}

TEST_F(HittableListTest, HitIfRayCollidesWithObjectUpdatesHitRecord) {
    std::shared_ptr<Hittable> hittable = GetHittableObject(true);
    HittableList list(hittable);
    HitRecord actual_record = record;

    list.Hit(ray, 0.0, 0.0, actual_record);

    ASSERT_NE(&actual_record, &record);
}

TEST_F(HittableListTest, HitIfRayDoesNotCollideWithObjectReturnsFalse) {
    std::shared_ptr<Hittable> hittable = GetHittableObject(false);
    HittableList list(hittable);

    bool actual_hit = list.Hit(ray,0.0, 0.0, record);

    ASSERT_FALSE(actual_hit);
}
