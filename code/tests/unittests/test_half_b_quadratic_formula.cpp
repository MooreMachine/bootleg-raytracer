#include "half_b_quadratic_formula.h"

#include "gmock/gmock.h"

using namespace testing;

class QuadraticFormulaTest : public Test {
protected:
    void SetUp() override {
        //qf = HalfBQuadraticFormula(0, 0, 0);
    }
};

TEST_F(QuadraticFormulaTest, GetDiscriminant__ReturnsLessThan0){
    auto qf = HalfBQuadraticFormula(0, 0, 0);

    ASSERT_LT(qf.getDiscriminant(), 0);
}

TEST_F(QuadraticFormulaTest, GetDiscriminant__ReturnsMoreThan0){
    ASSERT_THAT(true, false);
}

TEST_F(QuadraticFormulaTest, GetDiscriminant__Returns0){
    ASSERT_THAT(true, false);
}
