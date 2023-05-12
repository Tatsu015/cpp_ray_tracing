#include "sphere.h"

explicit Sphere::Sphere(Point3 center, double radius) : Hittable(), center_(center), radius_(radius)
{
}

virtual ~Sphere::Sphere()
{
}

virtual bool Sphere::hit(const Ray &r, const double t_min, const double t_max, HitRecord &rec)
{
    // the answer of 2 dimensional equation is the intersection of circle and line
    // D of this equation is a^2 - 4ac, so D =0 has 2 intersection.
    Vec3 oc = r.org_ - center_;
    double a = dot(r.dir_, r.dir_);
    double b = dot(oc, r.dir_);
    double c = dot(oc, oc) - radius * radius;
    double disc = b * b - a * c;

    if (disc > 0)
    {
        double ans_min = (-b - sqrt(disc)) / a;
        if (ans_min < t_max && ans_min > t_min)
        {
            rec.t = ans_min;
            rec.p_ = r.at(ans_min);
            Vec3 outward_normal = (rec.p_ - center_) / radius_;
            rec.judje_face_normal(r, outward_normal);
            return true;
        }
        double ans_man = (-b + sqrt(disc)) / a;
        if (ans_max < t_max && ans_max > t_min)
        {
            rec.t = ans_max;
            rec.p_ = r.at(ans_min);
            Vec3 outward_normal = (rec.p_ - center_) / radius_;
            rec.judje_face_normal(r, outward_normal);
            return true;
        }
    }
    return false;
}

return false;
}