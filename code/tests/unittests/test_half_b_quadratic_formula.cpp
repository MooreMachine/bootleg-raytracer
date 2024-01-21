#include "half_b_quadratic_formula.h"

#include "gmock/gmock.h"

using namespace testing;

class QuadraticFormulaTest : public Test {
protected:
    double a = 1;
    double h = 1;
};

TEST_F(QuadraticFormulaTest, GetDiscriminantReturnsLessThan0){
    auto qf = HalfBQuadraticFormula(a, h, 2);

    ASSERT_LT(qf.getDiscriminant(), 0);
}

TEST_F(QuadraticFormulaTest, GetDiscriminantReturns0){
    auto qf = HalfBQuadraticFormula(a, h, 1);

    ASSERT_EQ(qf.getDiscriminant(), 0);
}

TEST_F(QuadraticFormulaTest, GetDiscriminantReturnsMoreThan0){
    auto qf = HalfBQuadraticFormula(a, h, 0);

    ASSERT_GT(qf.getDiscriminant(), 0);
}

TEST_F(QuadraticFormulaTest, GetSqrtDiscriminantWhenNoRealRootsThrowsSystemError){
    auto qf = HalfBQuadraticFormula(a, h, 2);

    ASSERT_THROW(qf.getSqrtDiscriminant(), std::system_error);
}

TEST_F(QuadraticFormulaTest, GetSqrtDiscriminantReturns0){
    auto qf = HalfBQuadraticFormula(a, h, 1);

    ASSERT_EQ(qf.getSqrtDiscriminant(), 0);
}

TEST_F(QuadraticFormulaTest, GetSqrtDiscriminantReturnsMoreThan0){
    auto qf = HalfBQuadraticFormula(a, h, 0);

    ASSERT_GT(qf.getSqrtDiscriminant(), 0);
}

TEST_F(QuadraticFormulaTest, GetSqrtDiscriminantReturnsSqrtOfDiscriminant){
    auto qf = HalfBQuadraticFormula(a, 2, 0);

    ASSERT_EQ(qf.getSqrtDiscriminant(), 2);
}
