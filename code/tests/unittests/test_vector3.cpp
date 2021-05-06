#include "vector3.h"

#include "gmock/gmock.h"

#include <tuple>

using namespace testing;

class Vector3Test : public ::testing::Test {
protected:
    Vector3 test_vector;

    void SetUp() override {
        test_vector = Vector3(1.0, 1.0, 1.0);
    }
};

class Vector3ParameterizedTest : public ::testing::TestWithParam<std::tuple<int, double>> {
protected:
    Vector3 test_vector_456 { 4.0, 5.0, 6.0 } ;
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

TEST_P(Vector3ParameterizedTest, BracketOperatorWhenPassingAnIndexReturnsDoubleInThatPosition) {
    int index = std::get<0>(GetParam());
    double expected_value = std::get<1>(GetParam());

    double actual_value = test_vector_456[index];

    ASSERT_EQ(actual_value, expected_value);
}

TEST_P(Vector3ParameterizedTest, BracketOperatorWhenPassingAnIndexReturnsDoubleReferenceInThatPosition) {
    int index = std::get<0>(GetParam());
    double* expected_value = std::addressof(test_vector_456.e[index]);

    double* actual_value = std::addressof(test_vector_456[index]);

    ASSERT_EQ(actual_value, expected_value);
}

INSTANTIATE_TEST_CASE_P(
    Vector3BracketOperators,
    Vector3ParameterizedTest,
    ::testing::Values(
        std::make_tuple(0, 4.0), // first -> index, second -> value
        std::make_tuple(1, 5.0),
        std::make_tuple(2, 6.0)
    ));
