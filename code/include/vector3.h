#pragma once

#ifndef VECTOR3_H
#define VECTOR3_H
#include <ostream>

class Vector3 {
public:
	double e[3];
public:
	Vector3();
	Vector3(double x, double y, double z);

	double x();
	double y();
	double z();

	Vector3 operator-() const;
	double operator[](int i) const;
	double& operator[](int i);

	Vector3& operator+=(const Vector3& v);
	Vector3& operator*=(const double t);
	Vector3& operator/=(const double t);

	double Length() const;
	double LengthSquared() const;
};

using Point3 = Vector3;
using Color = Vector3;

inline std::ostream& operator<<(std::ostream& out, const Vector3& v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Vector3 operator+(const Vector3& u, const Vector3& v) {
	return Vector3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline Vector3 operator-(const Vector3& u, const Vector3& v) {
	return Vector3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline Vector3 operator*(const Vector3& u, const Vector3& v) {
	return Vector3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline Vector3 operator*(double t, const Vector3& v) {
	return Vector3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vector3 operator/(double t, const Vector3& v) {
	return (1 / t) * v;
}

inline double Dot(const Vector3& u, const Vector3& v) {
	return (u.e[0] * v.e[0]) + (u.e[1] * v.e[1]) + (u.e[2] * v.e[2]);
}

inline Vector3 Cross(const Vector3& u, const Vector3& v)
{
	return Vector3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
		           u.e[2] * v.e[0] - u.e[0] * v.e[2], 
		           u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline Vector3 UnitVector(const Vector3& v)
{
	return v.Length() / v;
}

#endif