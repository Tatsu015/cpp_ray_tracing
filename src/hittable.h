#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct HitRecord
{
    Point3 p;
    Vec3 normal;
    double t;
};

class Hittable
{
public:
    explicit Hittable() {}
    virtual ~Hittable() {}
    virtual bool hit(const Ray &r, const double t_min, const double t_max, HitRecord &rec) = 0;
};

#endif