#pragma once

#include "utils.h"
#include "vector3.h"

#include <iostream>

void GammaCorrection(Color& pixel_color, int samples_per_pixel) {
    // Divide the color by the number of samples and gamma-correct for gamma=2.0.
    auto scale = 1.0 / samples_per_pixel;
    for (auto& color_channel : pixel_color.e) {
        color_channel = sqrt(scale * color_channel);
    }
}

void To8BitColor(Color& pixel_color) {
    // Translate to [0, 255] values for each color component
    for (auto& color_channel : pixel_color.e) {
        color_channel = 256 * Clamp(color_channel, 0.0, 0.999);
    }
}

inline void WriteColor(std::ostream &out, Color pixel_color, int samples_per_pixel) {
    GammaCorrection(pixel_color, samples_per_pixel);
    To8BitColor(pixel_color);

	out << static_cast<int>(pixel_color.x()) << ' '
		<< static_cast<int>(pixel_color.y()) << ' '
		<< static_cast<int>(pixel_color.z()) << '\n';
}
