#include "half_b_quadratic_formula.h"

#include <cerrno>
#include <system_error>

double HalfBQuadraticFormula::getDiscriminant() {
    return discriminant;
}

double HalfBQuadraticFormula::getSqrtDiscriminant() {
    if (discriminant < 0) {
        throw std::system_error(EDOM, std::generic_category());
    }

    return sqrt(discriminant);
}
