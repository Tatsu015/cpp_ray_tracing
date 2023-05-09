#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray
{
public:
    Point3 org = {0, 0, 0};
    Vec3 dir = {0, 0, 0};

public:
    Ray();
    Ray(const Point3 &org, const Vec3 &dir);
    ~Ray();

    Point3 at(const double t) const;
};

Ray::Ray(/* args */)
{
}

Ray::~Ray()
{
}

#endif