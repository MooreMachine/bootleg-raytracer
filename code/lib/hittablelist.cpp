#include "hittablelist.h"

HittableList::HittableList(const std::shared_ptr<Hittable>& object) {
	Add(object);
}

void HittableList::Clear() {
	objects.clear();
}

void HittableList::Add(const std::shared_ptr<Hittable>& object) {
	objects.emplace_back(object);
}

bool HittableList::Hit(const Ray& ray, double t_min, double t_max, HitRecord& record) const {
	HitRecord temp_record;
	bool hit_anything = false;
	double closest_so_far = t_max;

	for (const auto& object : objects) {
		if (object -> Hit(ray, t_min, closest_so_far, temp_record)) {
			hit_anything = true;
			closest_so_far = temp_record.t;
			record = temp_record;
		}
	}

	return hit_anything;
}
