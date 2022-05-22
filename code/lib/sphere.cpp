#include "sphere.h"
#include "half_b_quadratic_formula.h"

#include <cmath>

bool Sphere::Hit(const Ray& ray, double t_min, double t_max, HitRecord& record) const
{
    /* The quadratic equation we are using for this method is a simplified version represented as:
     * (-h +- sqrt(h^2 - ac))/a
     * */
    const Vector3 origin_center = ray.getOrigin() - center;
    const double a = ray.getDirection().LengthSquared();
    const double h = Dot(origin_center, ray.getDirection());
    const double c = origin_center.LengthSquared() - std::pow(radius, 2);
	
    auto formula = HalfBQuadraticFormula(a, h, c);
    const double discriminant = formula.getDiscriminant();
    if (!RayHitsObject(discriminant)) return false;

	// Find the nearest root that lies in the acceptable range.
    double root{};
    if (!formula.NearestRootInRange(t_min, t_max, root)) return false;

	record.t = root;
	record.p = ray.At(record.t);
    const Vector3 outward_normal = (record.p - center) / radius;
    record.ComputeFaceNormalDirection(ray, outward_normal);
	
	return true;
}

bool Sphere::RayHitsObject(double discriminant) const {
    // if there are no real roots
    // the ray does not hit the sphere
    return discriminant >= 0;
}
