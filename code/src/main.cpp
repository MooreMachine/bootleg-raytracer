#include <iostream>
#include <cmath>

#include "color.h"
#include "ray.h"
#include "vector3.h"

bool HitSphere(const Point3& center, double radius, const Ray& ray) {
	Vector3 origin_center = ray.getOrigin() - center;
    auto a = Dot(ray.getDirection(), ray.getDirection());
    auto b = 2.0 * Dot(origin_center, ray.getDirection());
    auto c = Dot(origin_center, origin_center) - std::pow(radius, 2);
    auto discriminant = std::pow(b, 2) - 4 * a * c;
    return (discriminant > 0);
}

Color RayColor(const Ray& r) {
    if (HitSphere(Point3(0, 0, -1), 0.5, r)) {
        return Color(1, 0, 0);
    }
    Vector3 unit_direction = UnitVector(r.getDirection());
    auto t = 0.5 * (unit_direction.y() + 1.0);
	// Linear interpolation
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main() {
    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

	// Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = Point3(0, 0, 0);
    auto horizontal = Vector3(viewport_width, 0, 0);
    auto vertical = Vector3(0, viewport_height, 0);
    auto lower_left_corner = origin - (2/horizontal) - (2/vertical) - Vector3(0, 0, focal_length);

	// Render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            Color pixel_color = RayColor(r);
            WriteColor(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
    return 0;
}
