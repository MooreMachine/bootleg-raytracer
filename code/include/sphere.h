#pragma once

#include "hittable.h"
#include "vector3.h"

class Sphere : public Hittable {
public:
	Point3 center;
	double radius;
	
	Sphere() {}
	Sphere(const Point3 center, const double radius) : center(center), radius(radius) {}

	virtual bool Hit(const Ray& ray, double t_min, double t_max, HitRecord& record) const override;

private:
    bool RayHitsObject(double discriminant) const;
};
