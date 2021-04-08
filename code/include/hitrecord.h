#pragma once

#include "ray.h"

struct HitRecord
{
	Point3 p;
	Vector3 normal;
	double t;
};
