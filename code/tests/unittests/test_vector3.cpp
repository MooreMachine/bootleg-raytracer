#include "vector3.h"

#include "gmock/gmock.h"

#include <stdexcept>
#include <tuple>

using namespace testing;

class Vector3Test : public Test {
protected:
    Vector3 test_vector;

    void SetUp() override {
        test_vector = Vector3(1.0, 1.0, 1.0);
    }
};

TEST_F(Vector3Test, OutOperatorWhenPassingAStreamAndVector3OutputsTheVector3Content) {
    std::string expected_value = "1 1 1";
    std::stringstream actual_stream;

    actual_stream << test_vector;

    ASSERT_EQ(actual_stream.str(), expected_value);
}

TEST_F(Vector3Test, PlusOperatorWhenAddingUpTwoVector3ReturnsTheSumOfBothValues) {
    Vector3 expected_vector(2.0, 2.0, 2.0);

    Vector3 actualVector = test_vector + test_vector;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expected_vector.e));
}

TEST_F(Vector3Test, PlusEqualOperatorWhenAddingUpAVector3ReturnsTheSumOfBothValues) {
    Vector3 expected_vector(2.0, 2.0, 2.0);
    Vector3 actual_vector = test_vector;

    actual_vector += test_vector;

    ASSERT_THAT(actual_vector.e, ElementsAreArray(expected_vector.e));
}

TEST_F(Vector3Test, MinusOperatorWhenSubtractingTwoVector3ReturnsTheSubtractionOfBothValues) {
    Vector3 expected_vector(0.0, 0.0, 0.0);

    Vector3 actualVector = test_vector-test_vector;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expected_vector.e));
}

TEST_F(Vector3Test, MinusOperatorWhenNoParamsReturnsInvertedVector3) {
    Vector3 expected_vector(-1.0, -1.0, -1.0);

    Vector3 actualVector = -test_vector;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expected_vector.e));
}

TEST_F(Vector3Test, MultiplyOperatorWhenMultiplyingTwoVector3ReturnsMultiplicationOfBothValues) {
    Vector3 expected_vector(2.0, 2.0, 2.0);

    Vector3 actual_vector = test_vector * Vector3(2.0, 2.0, 2.0);

    ASSERT_THAT(actual_vector.e, ElementsAreArray(expected_vector.e));
}

TEST_F(Vector3Test, MultiplyOperatorWhenMultiplyingADoubleAndVector3ReturnsMultiplicationOfBothValues) {
    Vector3 expected_vector(2.0, 2.0, 2.0);

    Vector3 actual_vector = 2.0 * test_vector;

    ASSERT_THAT(actual_vector.e, ElementsAreArray(expected_vector.e));
}

TEST_F(Vector3Test, MultiplyEqualOperatorWhenMultiplyingADoubleReturnsMultiplicationOfBothValues) {
    Vector3 expected_vector(2.0, 2.0, 2.0);
    Vector3 actual_vector = test_vector;

    actual_vector *= 2.0;

    ASSERT_THAT(actual_vector.e, ElementsAreArray(expected_vector.e));
}

TEST_F(Vector3Test, DivideOperatorWhenDividingAVector3AndDoubleReturnsDivisionOfBothValues) {
    Vector3 expected_vector(0.5, 0.5, 0.5);

    Vector3 actual_vector = test_vector / 2.0;

    ASSERT_THAT(actual_vector.e, ElementsAreArray(expected_vector.e));
}

TEST_F(Vector3Test, DivideEqualsOperatorWhenDividingADoubleReturnsDivisionOfBothValues) {
    Vector3 expected_vector(0.5, 0.5, 0.5);
    Vector3 actual_vector = test_vector;

    actual_vector /= 2.0;

    ASSERT_THAT(actual_vector.e, ElementsAreArray(expected_vector.e));
}

TEST_F(Vector3Test, DotWhenPassingTwoVector3ReturnsDotProductOfBothVectors) {
    double expectedValue = 3.0;

    double actualValue = Dot(test_vector, test_vector);

    ASSERT_THAT(actualValue, expectedValue);
}

TEST_F(Vector3Test, CrossWhenPassingTwoVector3ReturnsCrossProductOfBothVectors) {
    Vector3 expected_vector(0.0, 0.0, 1.0);

    Vector3 actual_vector = Cross(Vector3(1.0, 0.0, 0.0), Vector3(0.0, 1.0, 0.0));

    ASSERT_THAT(actual_vector.e, ElementsAreArray(expected_vector.e));
}

TEST_F(Vector3Test, UnitVectorWhenPassingAVector3ReturnsItsUnitVector) {
    Vector3 expected_vector(0.0, 1.0, 0.0);

    Vector3 actual_vector = UnitVector(Vector3(0.0, 1.0, 0.0));

    ASSERT_THAT(actual_vector.e, ElementsAreArray(expected_vector.e));
}

TEST_F(Vector3Test, LengthWhenNoParamsReturnsSquareRootOfTheVectorsLengthSquared) {
    double expectedValue = std::sqrt(3.0);

    double actualValue = test_vector.Length();

    ASSERT_THAT(actualValue, expectedValue);
}

TEST_F(Vector3Test, LengthSquaredWhenNoParamsReturnsLengthSquaredValueOfTheVector) {
    double expectedValue = 3.0;

    double actualValue = test_vector.LengthSquared();

    ASSERT_THAT(actualValue, expectedValue);
}

class Vector3BracketOperatorTest : public TestWithParam<std::tuple<int, double>> {
protected:
    Vector3 param_test_vector {4.0, 5.0, 6.0 } ;
};

TEST_P(Vector3BracketOperatorTest, BracketOperatorWhenPassingAnIndexReturnsDoubleInThatPosition) {
    int index = std::get<0>(GetParam());
    double expected_value = std::get<1>(GetParam());

    double actual_value = param_test_vector[index];

    ASSERT_EQ(actual_value, expected_value);
}

TEST_P(Vector3BracketOperatorTest, BracketOperatorWhenPassingAnIndexReturnsDoubleReferenceInThatPosition) {
    int index = std::get<0>(GetParam());
    double* expected_value = std::addressof(param_test_vector.e[index]);

    double* actual_value = std::addressof(param_test_vector[index]);

    ASSERT_EQ(actual_value, expected_value);
}

INSTANTIATE_TEST_SUITE_P(
    Vector3BracketOperatorValueComparison,
    Vector3BracketOperatorTest,
    Values(
        // first -> index, second -> value
        std::make_tuple(0, 4.0),
        std::make_tuple(1, 5.0),
        std::make_tuple(2, 6.0)
    ));

class Vector3RandomTest : public TestWithParam<std::tuple<double, double>> {
protected:
    Vector3 vector_generator;
};

TEST(Vector3RandomTest, RandomWhenNoParametersReturnsVectorWithValuesFromMoreThanZeroUpToOne) {

    auto result = Vector3::Random();

    ASSERT_THAT(result.e, Each(AllOf(Ge(0), Lt(1))));
}

TEST(Vector3RandomTest, RandomWhenMinGreaterThanMaxThrowsError) {
    auto min = 2;
    auto max = 1;

    ASSERT_THROW(Vector3::Random(min, max), std::invalid_argument);
}

TEST(Vector3RandomTest, RandomWhenMinLessThanMaxThrowsNoError) {
    auto min = 1;
    auto max = 2;

    ASSERT_NO_THROW(Vector3::Random(min, max));
}

TEST(Vector3RandomTest, RandomInUnitSphereNoParametersVectorIsInsideUnitSphere) {
    bool isInsideSphere = true;
    int numberOfTests = 1000;

    for (int i = 0; i < numberOfTests; i++) {
        auto result = RandomInUnitSphere();
        if (result.LengthSquared() >= 1) {
            isInsideSphere = false;
            break;
        }
    }

    ASSERT_TRUE(isInsideSphere);
}

TEST_P(Vector3RandomTest, RandomWhenPassingMinMaxParametersReturnsVectorWithinRange) {
    auto min = std::get<0>(GetParam());
    auto max = std::get<1>(GetParam());

    auto result = vector_generator.Random(min, max);

    ASSERT_THAT(result.e, Each(AllOf(Ge(min), Lt(max))));
}

INSTANTIATE_TEST_SUITE_P(
    Vector3RandomMinMaxTests,
    Vector3RandomTest,
    Values(
        std::make_tuple(-2, -1),
        std::make_tuple(1, 2),
        std::make_tuple(10.5, 2000.1),
        std::make_tuple(1, 10000000000)
    ));
