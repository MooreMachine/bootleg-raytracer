#pragma once

#include "ray.h"

struct HitRecord
{
	Point3 p;
	Vector3 normal;
	double t;
	bool front_face;

	inline void set_face_normal(const Ray& ray, const Vector3& outward_normal) {
		front_face = Dot(ray.getDirection(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};
