#pragma once

#include "vector3.h"

#include <iostream>

inline void WriteColor(std::ostream &out, Color pixel_color) {
	out << static_cast<int>(255.999 * pixel_color.x()) << ' '
		<< static_cast<int>(255.999 * pixel_color.y()) << ' '
		<< static_cast<int>(255.999 * pixel_color.z()) << '\n';
}
