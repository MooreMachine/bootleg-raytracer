#include "vector3.h"

#include "gmock/gmock.h"

using namespace testing;

class Vector3Test : public ::testing::Test {
protected:
    Vector3 test_vector;

    void SetUp() override {
        test_vector = Vector3(1.0, 1.0, 1.0);
    }
};

TEST_F(Vector3Test, MinusOperatorOperatorWhenNoParamsReturnsInvertedVector3) {
    Vector3 expectedVector(-1.0, -1.0, -1.0);

    Vector3 actualVector = -test_vector;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}

TEST_F(Vector3Test, MinusOperatorWhenSubstractingTwoVector3ReturnsTheSubstractionOfBothValues) {
    Vector3 expectedVector(0.0, 0.0, 0.0);

    Vector3 actualVector = test_vector-test_vector;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}

TEST_F(Vector3Test, PlusOperatorWhenAddingUpTwoVector3ReturnsTheSumOfBothValues) {
    Vector3 expectedVector(2.0, 2.0, 2.0);

    Vector3 actualVector = test_vector + test_vector;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}

TEST_F(Vector3Test, PlusEqualOperatorWhenAddingUpAVector3ReturnsTheSumOfBothValues) {
    Vector3 expectedVector(2.0, 2.0, 2.0);
    Vector3 actualVector = test_vector;

    actualVector += test_vector;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}

TEST_F(Vector3Test, MultiplyOperatorWhenMultiplyingTwoVector3ReturnsMultiplicationOfBothValues) {
    Vector3 expectedVector(2.0, 2.0, 2.0);

    Vector3 actualVector = test_vector * Vector3(2.0, 2.0, 2.0);

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}

TEST_F(Vector3Test, MultiplyOperatorWhenMultiplyingADoubleAndVector3ReturnsMultiplicationOfBothValues) {
    Vector3 expectedVector(2.0, 2.0, 2.0);

    Vector3 actualVector = 2.0 * test_vector;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}

TEST_F(Vector3Test, MultiplyEqualOperatorWhenMultiplyingADoubleReturnsMultiplicationOfBothValues) {
    Vector3 expectedVector(2.0, 2.0, 2.0);
    Vector3 actualVector = test_vector;

    actualVector *= 2.0;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}

TEST_F(Vector3Test, DivideOpertatorWhenDividingAVector3AndDoubleReturnsDivisionOfBothValues) {
    Vector3 expectedVector(0.5, 0.5, 0.5);

    Vector3 actualVector = test_vector / 2.0;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}

TEST_F(Vector3Test, DivideEqualsOpertatorWhenDividingADoubleReturnsDivisionOfBothValues) {
    Vector3 expectedVector(0.5, 0.5, 0.5);
    Vector3 actualVector = test_vector;

    actualVector /= 2.0;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}



TEST_F(Vector3Test, LengthWhenNoParamsReturnsSquareRootOfTheVectorsLengthSquared)
{
    double expectedValue = std::sqrt(3.0);

    double actualValue = test_vector.Length();

    ASSERT_THAT(actualValue, expectedValue);
}

TEST_F(Vector3Test, LengthSquaredWhenNoParamsReturnsLengthSquaredValueOfTheVector)
{
    double expectedValue = 3.0;

    double actualValue = test_vector.LengthSquared();

    ASSERT_THAT(actualValue, expectedValue);
}

TEST_F(Vector3Test, DotWhenPassingTwoVector3ReturnsDotProductOfBothVectors)
{
    double expectedValue = 3.0;

    double actualValue = Dot(test_vector, test_vector);

    ASSERT_THAT(actualValue, expectedValue);
}

TEST_F(Vector3Test, CrossWhenPassingTwoVector3ReturnsCrossProductOfBothVectors)
{
    Vector3 expectedVector(0.0, 0.0, 1.0);

    Vector3 actualVector = Cross(Vector3(1.0, 0.0, 0.0), Vector3(0.0, 1.0, 0.0));

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}

TEST_F(Vector3Test, UnitVectorWhenPassingAVector3ReturnsItsUnitVector)
{
    Vector3 expectedVector(0.0, 1.0, 0.0);

    Vector3 actualVector = UnitVector(Vector3(0.0, 1.0, 0.0));

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}
