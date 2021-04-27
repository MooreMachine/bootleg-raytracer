#pragma once

#include "rtweekend.h"

class Camera {
    public: 
        Camera();
        Ray GetRay(double u, double v) const;

    private:
        Point3 origin;
        Point3 lower_left_corner;
        Vector3 horizontal;
        Vector3 vertical;
};
