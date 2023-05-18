#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "vec3.h"
#include "material.h"

class Lambertian : public Material
{
private:
    Color albedo_;

public:
    Lambertian(const Color &albedo);
    ~Lambertian();

    virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const;
};

#endif
