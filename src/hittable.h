#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class HitRecord
{
public:
    Point3 p_;
    Vec3 normal_;
    double t;
    bool front_face_;

public:
    inline void judje_face_normal(const Ray &r, const Vec3 &outward_normal)
    {
        front_face_ = dot(r.dir_, outward_normal) < 0;
        normal_ = front_face_ ? outward_normal : -outward_normal;
    }
};

class Hittable
{
public:
    explicit Hittable() {}
    virtual ~Hittable() {}
    virtual bool hit(const Ray &r, const double t_min, const double t_max, HitRecord &rec) = 0;
};

#endif