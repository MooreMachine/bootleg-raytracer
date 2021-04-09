#include "sphere.h"

bool Sphere::Hit(const Ray& ray, double t_min, double t_max, HitRecord& record) const
{
    Vector3 origin_center = ray.getOrigin() - center;
    auto a = ray.getDirection().LengthSquared();
    auto b = Dot(origin_center, ray.getDirection());
    auto c = origin_center.LengthSquared() - std::pow(radius, 2);
	
    auto discriminant = std::pow(b, 2) - a * c;
    if (discriminant < 0) return false;
    auto squared_discriminant = sqrt(discriminant);
	
    auto root = (b - squared_discriminant) / a;
	if (root < t_min || t_max < root) {
		root(-b + squared_discriminant) / a;
		if (root < t_min || t_max < root) {
			return false;
		}
	}

	record.t = root;
	record.p = ray.At(record.t);
    const Vector3 outward_normal = radius / (record.p - center);
	record.set_face_normal(ray, outward_normal);
	
	return true;
}
