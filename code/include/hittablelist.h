#pragma once

#include "hittable.h"

#include <memory>
#include <vector>

class HittableList : public Hittable {
public:
	std::vector<std::shared_ptr<Hittable>> objects;

	HittableList() {}
	HittableList(std::shared_ptr<Hittable>& object);

	void Clear();
	void Add(std::shared_ptr<Hittable>& object);
	virtual bool Hit(const Ray& ray, double t_min, double t_max, HitRecord& record) const override;
};
