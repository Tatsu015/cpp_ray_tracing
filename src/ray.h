#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray
{
public:
    Point3 org_ = {0, 0, 0};
    Vec3 dir_ = {0, 0, 0};

public:
    Ray(const Point3 &org, const Vec3 &dir);
    ~Ray();

    Point3 at(const double t) const;
};

#endif