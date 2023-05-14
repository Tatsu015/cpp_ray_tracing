#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

class Sphere : public Hittable
{
private:
    Point3 center_;
    double radius_;

public:
    Sphere(Point3 center, double radius);
    virtual ~Sphere();
    virtual bool hit(const Ray &r, const double t_min, const double t_max, HitRecord &rec) const;
};

#endif