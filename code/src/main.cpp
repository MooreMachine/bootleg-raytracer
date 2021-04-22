#include "color.h"
#include "hittablelist.h"
#include "ray.h"
#include "sphere.h"
#include "utils.h"
#include "vector3.h"

#include <iostream>

Color RayColor(const Ray& ray, const Hittable& world, int depth) {
    HitRecord record;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0) {
        return Color(0, 0, 0);
    }

    if(world.Hit(ray, 0, infinity, record)) {
        Point3 target = record.p + record.normal + RandomInUnitSphere();
        return 0.5 * RayColor(Ray(record.p, target - record.p), world, depth - 1);
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

    const int samples_per_pixel = 100;
    const int max_depth = 50;

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
    const Vector3 lower_left_corner = origin - (horizontal/2) - (vertical/2) - Vector3(0, 0, focal_length);

	// Render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            Color pixel_color = RayColor(r, world, max_depth);
            WriteColor(std::cout, pixel_color, samples_per_pixel);
        }
    }

    std::cerr << "\nDone.\n";
    return 0;
}
