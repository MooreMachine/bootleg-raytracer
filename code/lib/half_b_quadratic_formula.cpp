#include "half_b_quadratic_formula.h"

double HalfBQuadraticFormula::getDiscriminant() {
    return std::pow(h, 2) - (a * c);
}