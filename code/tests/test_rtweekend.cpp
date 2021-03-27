#include <rtweekend.h>
#include <gtest/gtest.h>

TEST(TestUtils, TestPi) {
    ASSERT_EQ(pi, 3.1415926535897932385);
}

TEST(TestUtils, TestDegreesToRadians) {
    double test_value = 180 / pi;
    ASSERT_DOUBLE_EQ(degrees_to_radians(test_value), 1);
}

TEST(TestUtils, TestRandomDoubleZeroToOne) {
    // Verify that random_double returns a number greater or equal to zero
    ASSERT_GE(random_double(), 0);
    // Verify that random_double returns a number smaller than one
    ASSERT_LT(random_double(), 1);
}

TEST(TestUtils, TestRandomDoubleMinToMax) {
    double min = 10;
    double max = 20;
    // Verify that random_double returns a number greater or equal to min
    ASSERT_GE(random_double(min, max), min);
    // Verify that random_double returns a number smaller than max
    ASSERT_LT(random_double(min, max), max);
}

TEST(TestUtils, TestClampMin) {
    double x = 5;
    double min = 10;
    double max = 20;
    ASSERT_EQ(clamp(x, min, max), min);
}

TEST(TestUtils, TestClampMax) {
    double x = 25;
    double min = 10;
    double max = 20;
    ASSERT_EQ(clamp(x, min, max), max);
}

TEST(TestUtils, TestClampBetween) {
    double x = 15;
    double min = 10;
    double max = 20;
    ASSERT_EQ(clamp(x, min, max), x);
}
