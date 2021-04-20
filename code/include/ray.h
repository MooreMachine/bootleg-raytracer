#pragma once

#include "vector3.h"

class Ray {
private:
	Point3 origin;
	Vector3 direction;
public:
	Ray() {}
	Ray(const Point3& origin, const Vector3& direction) : origin(origin), direction(direction) {}

	Point3 getOrigin() const;
	Vector3 getDirection() const;

	Point3 At(double t) const;
};
