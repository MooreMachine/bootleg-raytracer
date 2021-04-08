# pragma once

#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "hitrecord.h"

class Hittable {
public:
	virtual bool hit(const Ray& ray, double t_min, double t_max, HitRecord& record) const = 0;
};

#endif
