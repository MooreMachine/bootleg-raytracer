#pragma once

#ifndef RAY_H
#define RAY_H
#include "vector3.h"

class ray
{
public:
	Point3 origin;
	Vector3 direction;

	ray() {}
	ray(const Point3& origin, const Vector3& direction) : origin(origin), direction(direction) {}

	Point3 get_origin() const;
	Vector3 get_direction() const;

	Point3 At(double t) const;
};

#endif