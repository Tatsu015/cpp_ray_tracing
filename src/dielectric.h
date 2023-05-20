#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "material.h"

class Dielectric : public Material
{
private:
    double refrective_index_;

public:
    Dielectric(const double refrective_index);
    ~Dielectric();

    virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const;

private:
    Vec3 refract(const Vec3 &uv, const Vec3 &n, const double eta_in_over_eta_out) const;
};

#endif
