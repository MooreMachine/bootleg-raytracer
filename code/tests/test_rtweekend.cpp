#include <rtweekend.h>
#include <gtest/gtest.h>

TEST(TestUtils, TestPi) {
    ASSERT_EQ(pi, 3.1415926535897932385);
}

TEST(TestUtils, TestDegreesToRadians) {
    double test_value = 180 / pi;
    ASSERT_DOUBLE_EQ(degrees_to_radians(test_value), 1);
}
