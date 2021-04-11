#include <iostream>

#include "aliasing.h"
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
    const int samples_per_pixel = 100;

	// World
    HittableList world;
    shared_ptr<Hittable> obj1 = make_shared<Sphere>(Point3(0, 0, -1), 0.5);
    shared_ptr<Hittable> obj2 = make_shared<Sphere>(Point3(0, -100.5, -1), 100);
    world.Add(obj1);
    world.Add(obj2);

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
            WriteColor(std::cout, pixel_color, samples_per_pixel);
        }
    }

    std::cerr << "\nDone.\n";
    return 0;
}
