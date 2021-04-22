#include "vector3.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <stdexcept>
#include <tuple>

using namespace testing;

class Vector3Test : public TestWithParam<std::tuple<double, double>> {
protected:
    Vector3 vector_generator;
};

TEST(Vector3Test, RandomWhenNoParametersComponentIsMoreThanZeroUpToOOne) {
    auto result = Vector3::Random();
    ASSERT_THAT(result.e, Each(AllOf(Ge(0), Lt(1))));
}

TEST(Vector3Test, RandomWhenBadMinMaxThrowError) {
    auto min = 2;
    auto max = 1;
    ASSERT_THROW(Vector3::Random(min, max), std::invalid_argument);
}

TEST(Vector3Test, RandomWhenGoodMinMaxThrowNoError) {
    auto min = 1;
    auto max = 2;
    ASSERT_NO_THROW(Vector3::Random(min, max));
}

TEST_P(Vector3Test, RandomWhenMinMaxComponentIsMoreThanMinUpToMax) {
    auto min = std::get<0>(GetParam());
    auto max = std::get<1>(GetParam());
    auto result = vector_generator.Random(min, max);
    ASSERT_THAT(result.e, Each(AllOf(Ge(min), Lt(max))));
}

INSTANTIATE_TEST_CASE_P(
    Vector3RandomMinMaxTests,
    Vector3Test,
    Values(
        std::make_tuple(-2, -1),
        std::make_tuple(1, 2),
        std::make_tuple(10.5, 2000.1),
        std::make_tuple(1, 10000000000)
    ));

TEST(Vector3Test, RandomInUnitSphereNoParametersVectorIsInsideUnitSphere) {
    auto result = RandomInUnitSphere();
    ASSERT_LT(result.LengthSquared(), 1);
}
