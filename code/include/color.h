#pragma once

#include "vector3.h"

#include <iostream>

void GammaCorrection(Color& pixel_color, int samples_per_pixel) {
    // Divide the color by the number of samples and gamma-correct for gamma=2.0.
    auto scale = 1.0 / samples_per_pixel;
    for (auto& i : pixel_color.e) {
        i = sqrt(scale * i);
    }
}

inline void WriteColor(std::ostream &out, Color pixel_color) {
	out << static_cast<int>(255.999 * pixel_color.x()) << ' '
		<< static_cast<int>(255.999 * pixel_color.y()) << ' '
		<< static_cast<int>(255.999 * pixel_color.z()) << '\n';
}
