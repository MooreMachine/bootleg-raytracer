#include "sphere.h"

#include "hitrecord.h"
#include "ray.h"
#include "vector3.h"

#include "gmock/gmock.h"

using namespace testing;

class SphereTest : public Test {
protected:
    const Point3 origin { 2, 2, 2 };
    const Vector3 direction { 0, 0, -1 };
    const Ray ray { origin, direction };
    Sphere sphere;

    void SetUp() override {
        Point3 center { 0, 0, 0 };
        double radius = 3;
        sphere = Sphere(center, radius);
    }
};

TEST_F(SphereTest, HitRayZAxisMin0Max1ReturnsTrue) {
    double min = 0;
    double max = 1;
    HitRecord record{};

    bool is_hit = sphere.Hit(ray, min, max, record);

    ASSERT_EQ(is_hit, true);
}

TEST_F(SphereTest, HitRayZAxisMin0Max05ReturnsFalse) {
    double min = 0;
    double max = 0.5;
    HitRecord record {};

    bool is_hit = sphere.Hit(ray, min, max, record);

    ASSERT_EQ(is_hit, false);
}

TEST_F(SphereTest, HitIfRayDidNotHitReturnsFalse) {
    Point3 center { 0, 0, 0 };
    double radius = 4;
    sphere = Sphere(center, radius);
    HitRecord record {};

    bool is_hit = sphere.Hit(ray, 0, 1, record);

    ASSERT_EQ(is_hit, false);
}
