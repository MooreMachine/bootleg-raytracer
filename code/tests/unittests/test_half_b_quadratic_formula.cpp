#include "half_b_quadratic_formula.h"

#include "gmock/gmock.h"

using namespace testing;

class QuadraticFormulaTest : public Test {
protected:
    double a = 1;
    double h = 1;
};

TEST_F(QuadraticFormulaTest, GetDiscriminant__ReturnsLessThan0){
    auto qf = HalfBQuadraticFormula(a, h, 2);

    ASSERT_LT(qf.getDiscriminant(), 0);
}

TEST_F(QuadraticFormulaTest, GetDiscriminant__ReturnsMoreThan0){
    auto qf = HalfBQuadraticFormula(a, h, 0);

    ASSERT_GT(qf.getDiscriminant(), 0);
}

TEST_F(QuadraticFormulaTest, GetDiscriminant__Returns0){
    auto qf = HalfBQuadraticFormula(a, h, 1);

    ASSERT_EQ(qf.getDiscriminant(), 0);
}
