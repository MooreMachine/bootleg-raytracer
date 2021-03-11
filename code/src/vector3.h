#pragma once

#ifndef VECTOR3_H
#define VECTOR3_H

class vector3 {
public:
	double e[3];
public:
	vector3();
	vector3(double x, double y, double z);

	double x();
	double y();
	double z();

	vector3 operator-() const;
	double operator[](int i) const;
	double& operator[](int i);

	vector3& operator +=(const vector3& v);
	vector3& operator*=(const double t);
	vector3& operator/=(const double t);

	double length() const;
	double length_squared() const;
};

using point3 = vector3;
using color = vector3;

#endif