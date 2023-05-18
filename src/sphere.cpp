#include "sphere.h"

#include <cmath>

Sphere::Sphere(Point3 center, double radius, std::shared_ptr<Material> material) : Hittable(), center_(center), radius_(radius), material_(material)
{
}

Sphere::~Sphere()
{
}

bool Sphere::hit(const Ray &r, const double t_min, const double t_max, HitRecord &rec) const
{
    // the answer of 2 dimensional equation is the intersection of circle and line
    // D of this equation is a^2 - 4ac, so D =0 has 2 intersection.
    Vec3 oc = r.org() - center_;
    double a = dot(r.dir(), r.dir());
    double b = dot(oc, r.dir());
    double c = dot(oc, oc) - radius_ * radius_;
    double disc = b * b - a * c;

    if (disc > 0)
    {
        double ans_min = (-b - sqrt(disc)) / a;
        if (ans_min < t_max && ans_min > t_min)
        {
            rec.set_t(ans_min);
            rec.set_p(r.at(ans_min));
            Vec3 outward_normal = (rec.p() - center_) / radius_;
            rec.judje_face_normal(r, outward_normal);
            rec.set_material(material_);
            return true;
        }
        double ans_max = (-b + sqrt(disc)) / a;
        if (ans_max < t_max && ans_max > t_min)
        {
            rec.set_t(ans_max);
            rec.set_p(r.at(ans_min));
            Vec3 outward_normal = (rec.p() - center_) / radius_;
            rec.judje_face_normal(r, outward_normal);
            rec.set_material(material_);
            return true;
        }
    }
    return false;
}
