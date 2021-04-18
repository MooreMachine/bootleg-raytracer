# pragma once

#include "ray.h"
#include "hitrecord.h"

class Hittable {
public:
	virtual bool Hit(const Ray& ray, double t_min, double t_max, HitRecord& record) const = 0;
};
