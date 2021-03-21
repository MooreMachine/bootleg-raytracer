#include "ray.h"

Point3 Ray::getOrigin() const {
	return origin;
}

Vector3 Ray::getDirection() const {
	return direction;
}

Point3 Ray::At(double t) const {
	return origin + t * direction;
}

