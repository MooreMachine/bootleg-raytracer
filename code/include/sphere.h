#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vector3.h"

class Sphere : public Hittable {
public:
	Point3 center;
	double radius;
	
	Sphere() {}
	Sphere(Point3 center, double radius) : center(center), radius(radius) {};

	virtual bool hit(const Ray& ray, double t_min, double t_max, HitRecord& record) const override;
};

#endif
