#include "aliasing.h"
#include <gtest/gtest.h>

TEST(TestAntialiasing, TestCameraConstructor) {
    Camera c{};

    ASSERT_DOUBLE_EQ(c.aspect_ratio, 16.0/9.0);
    ASSERT_DOUBLE_EQ(c.viewport_height, 2.0);
    ASSERT_DOUBLE_EQ(c.viewport_width, c.aspect_ratio * c.viewport_height);
    ASSERT_DOUBLE_EQ(c.focal_length, 1.0);
}

// TEST(TestAntialiasing, TESTGetRay) {
//     Camera c{};
//     double u = 1.0;

//     ASSERT_EQ(get_ray(u,u), )
// }