#include "metal.h"

Metal::Metal(const Color &albedo) : albedo_(albedo)
{
}

Metal::~Metal()
{
}

bool Metal::scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    Vec3 scatter_dir = reflect(unit_vector(r_in.dir()), rec.normal());
    scattered = Ray(rec.p(), scatter_dir);
    attenuation = albedo_;
    return true;
}

Vec3 Metal::reflect(const Vec3 &v, const Vec3 &n) const
{
    return v - 2 * dot(v, n) * n;
}