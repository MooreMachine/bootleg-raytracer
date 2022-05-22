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

bool HalfBQuadraticFormula::NearestRootInRange(double t_min, double t_max,double& root) {
    root = Root1();
    if (root < t_min || t_max < root) {
        root = Root2();
        if (root < t_min || t_max < root) {
            return false;
        }
    }
    return true;
}

double HalfBQuadraticFormula::Root1() {
    return (-h - getSqrtDiscriminant()) / a;
}

double HalfBQuadraticFormula::Root2() {
    return (-h + getSqrtDiscriminant()) / a;
}
