#ifndef HITTABLE_H
#define HITTABLE_H

#include <memory>

#include "ray.h"

class Material;

class HitRecord
{
private:
    Point3 p_ = Point3(0, 0, 0);
    Vec3 normal_ = Vec3(0, 0, 0);
    double t_ = 0;
    bool front_face_ = true;
    std::shared_ptr<Material> material_;

public:
    inline void judje_face_normal(const Ray &r, const Vec3 &outward_normal)
    {
        front_face_ = dot(r.dir(), outward_normal) < 0;
        normal_ = front_face_ ? outward_normal : -outward_normal;
    }

    Vec3 p() const { return p_; }
    void set_p(const Vec3 p) { p_ = p; }

    Vec3 normal() const { return normal_; }

    double t() const { return t_; }
    void set_t(const double t) { t_ = t; }

    bool front_face() const { return front_face_; }

    std::shared_ptr<Material> material() const { return material_; }
    void set_material(std::shared_ptr<Material> material) { material_ = material; }
};

class Hittable
{
public:
    explicit Hittable() {}
    virtual ~Hittable() {}
    virtual bool hit(const Ray &r, const double t_min, const double t_max, HitRecord &rec) const = 0;
};

#endif