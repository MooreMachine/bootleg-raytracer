#include "vector3.h"

#include <cmath>
#include <iostream>

Vector3::Vector3() : e{ 0, 0, 0 } {}
Vector3::Vector3(double x, double y, double z) : e{ x, y, z } {}

double Vector3::x() {
	return e[0];
}

double Vector3::y() {
	return e[1];
}

double Vector3::z() {
	return e[2];
}


Vector3 Vector3::operator-() const {
	return Vector3(-e[0], -e[1], -e[2]);
}

double Vector3::operator[](int i) const {
	return e[i];
}

double& Vector3::operator[](int i) {
	return e[i];
}

Vector3& Vector3::operator+=(const Vector3& v)
{
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}

Vector3& Vector3::operator*=(const double t)
{
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

Vector3& Vector3::operator/=(const double t)
{
	return *this *= 1 / t;
}


double Vector3::Length() const {
	return std::sqrt(LengthSquared());
}

double Vector3::LengthSquared() const {
	return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

Vector3 RandomInUnitSphere() {
	auto p = Vector3::Random(-1, 1);
	while (p.LengthSquared() >= 1) {
		p = Vector3::Random(-1, 1);
	}
	return p;
}
