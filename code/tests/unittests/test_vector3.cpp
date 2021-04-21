#include "vector3.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <string>

using namespace testing;

TEST(TestVector3, RandomWhenNoParametersComponentIsMoreThanZeroUpToOOne) {
    auto result = Vector3::Random();
    ASSERT_THAT(result.e, Each(AllOf(Ge(0), Lt(1))));
}
