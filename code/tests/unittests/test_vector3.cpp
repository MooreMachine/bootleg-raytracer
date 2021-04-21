#include "vector3.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <string>

using namespace testing;

MATCHER_P2(IsBetweenLeftClosedRange, a, b, std::string(negation ? "isn't" : "is") + " in the interval [" + PrintToString(a) + ", " + PrintToString(b) + ")") {
    return a <= arg && arg < b;
}

TEST(TestVector3, RandomWhenNoParametersComponentIsMoreThanZeroUpToOOne) {
    auto result = Vector3::Random();
    ASSERT_THAT(result.e, Each(IsBetweenLeftClosedRange(0, 1)));
}
