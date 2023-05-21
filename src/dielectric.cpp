#include "dielectric.h"

Dielectric::Dielectric(const double refrective_index) : refrective_index_(refrective_index)
{
}

Dielectric::~Dielectric()
{
}

bool Dielectric::scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    double eta_in_over_eta_out = 0;
    attenuation = Color(1, 1, 1);
    if (rec.front_face())
    {
        eta_in_over_eta_out = 1 / refrective_index_;
    }
    else
    {
        eta_in_over_eta_out = refrective_index_;
    }

    Vec3 unit_dir = unit_vector(r_in.dir());
    const double cos_theta = fmin(dot(-unit_dir, rec.normal()), 1);
    const double sin_theta = sqrt(1 - cos_theta * cos_theta);

    if (eta_in_over_eta_out * sin_theta > 1.0)
    {
        Vec3 reflected = reflect(unit_dir, rec.normal());
        scattered = Ray(rec.p(), reflected);
        return true;
    }

    double reflect_prob = schlick(cos_theta, eta_in_over_eta_out);
    if (random_double() > reflect_prob)
    {
        Vec3 reflected = reflect(unit_dir, rec.normal());
        scattered = Ray(rec.p(), reflected);
        return true;
    }

    Vec3 refracted = refract(unit_dir, rec.normal(), eta_in_over_eta_out);
    scattered = Ray(rec.p(), refracted);

    return true;
}

Vec3 Dielectric::refract(const Vec3 &uv, const Vec3 &n, const double eta_in_over_eta_out) const
{
    double cos_theta = dot(-uv, n);
    Vec3 r_parallel = eta_in_over_eta_out * (uv + cos_theta * n);
    Vec3 r_perpendicular = -sqrt(1 - r_parallel.length_squared()) * n;

    return r_parallel + r_perpendicular;
}

Vec3 Dielectric::reflect(const Vec3 &v, const Vec3 &n) const
{
    return v - 2 * dot(v, n) * n;
}

double Dielectric::schlick(const double cos_theta, double refrective_index) const
{
    double r0 = (1 - refrective_index) / (1 + refrective_index);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cos_theta), 5);
}