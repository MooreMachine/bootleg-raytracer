#include "vector3.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <string>

using namespace testing;

MATCHER_P2(IsBetweenLeftClosedRange, a, b, std::string(negation ? "isn't" : "is") + " in the interval [" + PrintToString(a) + ", " + PrintToString(b) + ")") {
    return a <= arg && arg < b;
}

TEST(TestVector3, RandomWhenNoParametersXIsMoreThanZeroUpToOOne) {
    auto result = Vector3::Random();
    ASSERT_THAT(result.x(), IsBetweenLeftClosedRange(0, 1));
}

TEST(TestVector3, RandomWhenNoParametersYIsMoreThanZeroUpToOOne) {
    auto result = Vector3::Random();
    ASSERT_THAT(result.y(), IsBetweenLeftClosedRange(0, 1));
}

TEST(TestVector3, RandomWhenNoParametersZIsMoreThanZeroUpToOOne) {
    auto result = Vector3::Random();
    ASSERT_THAT(result.z(), IsBetweenLeftClosedRange(0, 1));
}
