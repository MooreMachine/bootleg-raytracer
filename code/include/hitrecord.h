#pragma once

#include "ray.h"

struct hit_record
{
	Point3 p;
	Vector3 normal;
	double t;
};
