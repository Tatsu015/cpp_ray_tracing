#include "lambertian.h"

Lambertian::Lambertian(const Color &albedo) : albedo_(albedo)
{
}

Lambertian::~Lambertian()
{
}

bool Lambertian::scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    Vec3 scatter_dir = rec.normal() + random_unit_vector();
    scattered = Ray(rec.p(), scatter_dir);
    attenuation = albedo_;
    return true;
}