#include "ray.h"

Point3 Ray::get_origin() const
{
	return origin;
}

Vector3 Ray::get_direction() const
{
	return direction;
}

Point3 Ray::At(double t) const
{
	return origin + t * direction;
}

