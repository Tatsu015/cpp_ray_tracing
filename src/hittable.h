#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class HitRecord
{
private:
    Point3 p_ = Point3(0, 0, 0);
    Vec3 normal_ = Vec3(0, 0, 0);
    double t_ = 0;
    bool front_face_ = true;

public:
    inline void judje_face_normal(const Ray &r, const Vec3 &outward_normal)
    {
        front_face_ = dot(r.dir(), outward_normal) < 0;
        normal_ = front_face_ ? outward_normal : -outward_normal;
    }

    double t() const { return t_; }
    void setT(const double t) { t_ = t; }
    Vec3 p() const { return p_; }
    void setP(const Vec3 p) { p_ = p; }
    Vec3 normal() const { return normal_; }
};

class Hittable
{
public:
    explicit Hittable() {}
    virtual ~Hittable() {}
    virtual bool hit(const Ray &r, const double t_min, const double t_max, HitRecord &rec) const = 0;
};

#endif