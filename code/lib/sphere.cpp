#include <cmath>

#include "sphere.h"


bool Sphere::Hit(const Ray& ray, double t_min, double t_max, HitRecord& record) const
{
    const Vector3 origin_center = ray.getOrigin() - center;
    const double a = ray.getDirection().LengthSquared();
    const double b = Dot(origin_center, ray.getDirection());
    const double c = origin_center.LengthSquared() - std::pow(radius, 2);
	
    const double discriminant = std::pow(b, 2) - (a * c);
    if (discriminant < 0) return false;
    const double squared_discriminant = sqrt(discriminant);

	// Find the nearest root that lies in the acceptable range.
    double root = (-b - squared_discriminant) / a;
	if (root < t_min || t_max < root) {
		root = (-b + squared_discriminant) / a;
		if (root < t_min || t_max < root) {
			return false;
		}
	}

	record.t = root;
	record.p = ray.At(record.t);
    const Vector3 outward_normal = (record.p - center) / radius;
	record.set_face_normal(ray, outward_normal);
	
	return true;
}
