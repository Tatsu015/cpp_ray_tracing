#include "metal.h"

Metal::Metal(const Color &albedo, const double fizzy) : albedo_(albedo), fizzy_(fizzy > 1 ? 1 : fizzy)
{
}

Metal::~Metal()
{
}

bool Metal::scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    Vec3 scatter_dir = reflect(unit_vector(r_in.dir()), rec.normal());
    scattered = Ray(rec.p(), scatter_dir + fizzy_ * random_in_unit_sphere());
    attenuation = albedo_;
    return true;
}

Vec3 Metal::reflect(const Vec3 &v, const Vec3 &n) const
{
    return v - 2 * dot(v, n) * n;
}