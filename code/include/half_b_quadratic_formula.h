#pragma once

#include "vector3.h"
#include "ray.h"

class HalfBQuadraticFormula {
public:
    HalfBQuadraticFormula(double a, double h, double c) : a(a), h(h), c(c) {}
    double getDiscriminant();
private:
    double a;
    double h;
    double c;
};