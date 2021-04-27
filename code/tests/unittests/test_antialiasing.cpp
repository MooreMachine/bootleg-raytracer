#include "camera.h"

#include "vector3.h"

#include "gmock/gmock.h"

using namespace testing;

class CameraTest : public Test {
protected:
    double aspect_ratio = 16.0 / 9.0;
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    Point3 origin = Point3(0, 0, 0);
    Vector3 horizontal = Vector3(viewport_width, 0.0, 0.0);
    Vector3 vertical = Vector3(0.0, viewport_height, 0.0);
    Vector3 lower_left_corner = origin - (horizontal/2) - (vertical/2) - Vector3(0, 0, focal_length);

    Camera c;
    Ray ray;

    void SetUp() override {
        c = Camera();
        ray = c.GetRay(1, 1);
    }
};

TEST_F(CameraTest, GetRayAnyCameraOriginIsZero) {
    ASSERT_THAT(ray.getOrigin().e, ElementsAre(0, 0, 0));
}

TEST_F(CameraTest, GetRayMultiplyByUnitDirectionIs) {
    Vector3 direction = lower_left_corner + horizontal + vertical - origin;
    ASSERT_THAT(ray.getDirection().e, ElementsAreArray(direction.e));
}
