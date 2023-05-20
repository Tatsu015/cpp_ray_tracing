#include "dielectic.h"

Dielectric::Dielectric(const double refrective_index) : refrective_index_(refrective_index)
{
}

Dielectric::~Dielectric()
{
}

bool Dielectric::scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    double eta_in_over_eta_out = 0;
    if (rec.front_face())
    {
        eta_in_over_eta_out = 1 / refrective_index_;
    }
    else
    {
        eta_in_over_eta_out = refrective_index_;
    }

    Vec3 unit_dir = unit_vector(r_in.dir());
    Vec3 reflected = reflect(unit_dir, rec.normal(), eta_in_over_eta_out);

    scattered = Ray(rec.p(), reflected);

    return true;
}

Vec3 Dielectric::reflect(const Vec3 &uv, const Vec3 &n, const double eta_in_over_eta_out) const
{
    double cos_theta = dot(uv, n);
    Vec3 r_parallel = eta_in_over_eta_out * (uv + cos_theta * n);
    Vec3 r_perpendicular = -sqrt(1 - r_parallel.length_squared()) * n;

    return r_parallel + r_perpendicular;
}