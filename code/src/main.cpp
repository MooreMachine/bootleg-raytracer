#include <iostream>
#include <cmath>

#include "aliasing.h"
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
    const int samples_per_pixel = 100;

	// Camera
    Camera cam;

	// Render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            Color pixel_color(0, 0, 0)
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + RandomDouble()) / (image_width-1);
                auto v = (j + RandomDouble()) / (image_height-1);

                Ray r = cam.GetRay(u, v);
                pixel_color += RayColor(r, world);
            }
        }
    }

    std::cerr << "\nDone.\n";
    return 0;
}
