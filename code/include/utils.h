#pragma once

#include <cmath>
#include <limits>
#include <memory>
#include <random>
#include <stdexcept>

// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double DegreesToRadians(double degrees) {
    return degrees * pi / 180.0;
}

inline double RandomDouble() {
    // Returns a random real in [0, 1)
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double RandomDouble(double min, double max) {
    // Returns a random real in [min, max)
    if (min < max) {
        return min + (max - min) * RandomDouble();
    } else {
        throw std::invalid_argument("min must be smaller than max");
    }
}

inline double Clamp(double x, double min, double max) {
    if (x < min) {
        return min;
    } else if (x > max) {
        return max;
    } else {
        return x;
    }
}
