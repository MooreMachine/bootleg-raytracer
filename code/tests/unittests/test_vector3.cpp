#include "vector3.h"

#include "gmock/gmock.h"

using namespace testing;

class Vector3Test : public ::testing::Test {
protected:
    Vector3 test_vector;

    void SetUp() override {
        test_vector = Vector3(1, 1, 1);
    }
};

TEST_F(Vector3Test, MinusOperatorOperatorWhenNoParams3ReturnsInvertedVector3)
{
    Vector3 expectedVector(-1, -1, -1);

    Vector3 actualVector = -test_vector;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}

TEST_F(Vector3Test, MinusOperatorWhenSubstractingTwoVector3ReturnsTheSubstractionOfBothValues)
{
    Vector3 expectedVector(0, 0, 0);

    Vector3 actualVector = test_vector-test_vector;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}

TEST_F(Vector3Test, PlusOperatorWhenAddingUpTwoVector3ReturnsTheSumOfBothValues)
{
    Vector3 expectedVector(2, 2, 2);

    Vector3 actualVector = test_vector + test_vector;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}

TEST_F(Vector3Test, PlusEqualOperatorWhenAddingUpAVector3ReturnsTheSumOfBothValues)
{
    Vector3 expectedVector(2, 2, 2);
    Vector3 actualVector = test_vector;

    actualVector += test_vector;

    ASSERT_THAT(actualVector.e, ElementsAreArray(expectedVector.e));
}