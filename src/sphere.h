#ifndef SPHERE_H
#define SPHERE_H

#include <memory>

#include "hittable.h"

class Sphere : public Hittable
{
private:
    Point3 center_;
    double radius_;
    std::shared_ptr<Material> material_;

public:
    Sphere(Point3 center, double radius, std::shared_ptr<Material> material);
    virtual ~Sphere();
    virtual bool hit(const Ray &r, const double t_min, const double t_max, HitRecord &rec) const;
};

#endif