#include <iostream>

#include "rtweekend.h"
#include "hittablelist.h"
#include "color.h"
#include "sphere.h"

Color RayColor(const Ray& ray, const Hittable& world) {
    HitRecord record;
    if(world.Hit(ray, 0, infinity, record)) {
        return 0.5 * (record.normal + Color(1, 1, 1));
    }

    Vector3 unit_direction = UnitVector(ray.getDirection());
    const double t = 0.5 * (unit_direction.y() + 1.0);

	// Linear interpolation
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main() {
    // Image
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

	// World
    HittableList world;
    shared_ptr<Hittable> obj1 = make_shared<Sphere>(Point3(0, 0, -1), 0.5);
    shared_ptr<Hittable> obj2 = make_shared<Sphere>(Point3(0, -100.5, -1), 100);
    world.Add(obj1);
    world.Add(obj2);

	// Camera
    const double viewport_height = 2.0;
    const double viewport_width = aspect_ratio * viewport_height;
    const double focal_length = 1.0;

    const auto origin = Point3(0, 0, 0);
    const auto horizontal = Vector3(viewport_width, 0, 0);
    const auto vertical = Vector3(0, viewport_height, 0);
    const Vector3 lower_left_corner = origin - (2/horizontal) - (2/vertical) - Vector3(0, 0, focal_length);

	// Render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            Color pixel_color = RayColor(r, world);
            WriteColor(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
    return 0;
}
