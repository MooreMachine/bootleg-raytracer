# pragma once

#include "hitrecord.h"
#include "ray.h"

class Hittable {
public:
	virtual bool Hit(const Ray& ray, double t_min, double t_max, HitRecord& record) const = 0;
};
