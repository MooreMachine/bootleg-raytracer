#include "utils.h"

#include <gtest/gtest.h>

TEST(TestUtils, TestPi) {
    ASSERT_EQ(pi, 3.1415926535897932385);
}

TEST(TestUtils, TestDegreesToRadians) {
    double test_value = 180 / pi;
    ASSERT_DOUBLE_EQ(DegreesToRadians(test_value), 1);
}

TEST(TestUtils, TestRandomDoubleZeroToOne) {
    // Verify that RandomDouble returns a number greater or equal to zero
    ASSERT_GE(RandomDouble(), 0);
    // Verify that RandomDouble returns a number smaller than one
    ASSERT_LT(RandomDouble(), 1);
}

TEST(TestUtils, TestRandomDoubleMinToMax) {
    double min = 10;
    double max = 20;
    // Verify that RandomDouble returns a number greater or equal to min
    ASSERT_GE(RandomDouble(min, max), min);
    // Verify that RandomDouble returns a number smaller than max
    ASSERT_LT(RandomDouble(min, max), max);
}

TEST(TestUtils, TestClampMin) {
    double x = 5;
    double min = 10;
    double max = 20;
    ASSERT_EQ(Clamp(x, min, max), min);
}

TEST(TestUtils, TestClampMax) {
    double x = 25;
    double min = 10;
    double max = 20;
    ASSERT_EQ(Clamp(x, min, max), max);
}

TEST(TestUtils, TestClampBetween) {
    double x = 15;
    double min = 10;
    double max = 20;
    ASSERT_EQ(Clamp(x, min, max), x);
}
