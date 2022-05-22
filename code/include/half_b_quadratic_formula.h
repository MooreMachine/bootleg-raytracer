#pragma once

#include <cmath>

class HalfBQuadraticFormula {
public:
    HalfBQuadraticFormula(double a, double h, double c) : a(a), h(h), c(c) {
        discriminant = std::pow(h, 2) - (a * c);
    }
    double getDiscriminant();
    double getSqrtDiscriminant(); // this only works if the discriminant is non-negative
private:
    double a;
    double h;
    double c;
    double discriminant;
    double sqrt_discriminant;
};