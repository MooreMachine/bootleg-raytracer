#include "hittablelist.h"

#include "gmock/gmock.h"

using namespace testing;

class HittableListTest : public ::testing::Test {

};

class HittableMock : public Hittable {
public:
    bool will_hit = false;

    HittableMock(bool will_hit) : will_hit(will_hit) {}

    bool Hit(const Ray &ray, double t_min, double t_max, HitRecord &record) const override {
        return will_hit;
    }
};

TEST_F(HittableListTest, ClearWhenNoParamsClearsTheListOfHittableObjects){
    HittableMock hittableMock(true);
    std::shared_ptr<Hittable> hittable = std::make_shared<HittableMock>(hittableMock);
    HittableList list(hittable);

    list.Clear();

    ASSERT_THAT(list.objects.size(), 0);
}

TEST_F(HittableListTest, AddWhenPassingAHittableObjectAddsReferenceToList){
    HittableMock hittableMock(true);
    std::shared_ptr<Hittable> hittable = std::make_shared<HittableMock>(hittableMock);
    HittableList list;

    list.Add(hittable);

    ASSERT_THAT(list.objects.size(), 1);
}

TEST_F(HittableListTest, HitIfRayCollidesWithObjectReturnsTrue){
    HitRecord record;
    HittableMock hittableMock(true);
    std::shared_ptr<Hittable> hittable = std::make_shared<HittableMock>(hittableMock);
    HittableList list(hittable);

    bool actualhit = list.Hit(Ray(Point3(0, 0, 0), Vector3(0, 0, 0)), 0, 0, record);

    ASSERT_TRUE(actualhit);
}

TEST_F(HittableListTest, HitIfRayDoesNotCollideWithObjectReturnsFalse){
    HitRecord record;
    HittableMock hittableMock(false);
    std::shared_ptr<Hittable> hittable = std::make_shared<HittableMock>(hittableMock);
    HittableList list(hittable);

    bool actualhit = list.Hit(Ray(Point3(0, 0, 0), Vector3(0, 0, 0)), 0, 0, record);

    ASSERT_FALSE(actualhit);
}