#include "sphere.h"

#include "hitrecord.h"
#include "ray.h"
#include "vector3.h"

#include "gmock/gmock.h"

using namespace testing;

class SphereTest : public Test {
protected:
    Sphere sphere;

    void SetUp() override {
        Point3 center { 0, 0, 0 };
        double radius = 3;
        sphere = Sphere(center, radius);
    }
};

TEST_F(SphereTest, HitRayZAxisMin0Max1ReturnsFalse) {
    Point3 origin { 2, 2, 2 };
    Vector3 direction { 0, 0, -1 };
    Ray ray {origin, direction};
    double min = 0;
    double max = 1;
    HitRecord record{};

    bool is_hit = sphere.Hit(ray, min, max, record);

    ASSERT_EQ(is_hit, false);
}
