#pragma once

#ifndef RAY_H
#define RAY_H
#include "vector3.h"

class Ray {
public:
	Point3 origin;
	Vector3 direction;

	Ray() {}
	Ray(const Point3& origin, const Vector3& direction) : origin(origin), direction(direction) {}

	Point3 getOrigin() const;
	Vector3 getDirection() const;

	Point3 At(double t) const;
};

#endif