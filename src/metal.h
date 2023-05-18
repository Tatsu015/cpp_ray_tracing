#ifndef METAL_H
#define METAL_H

#include "material.h"

class Metal : public Material
{
private:
    Color albedo_;

public:
    Metal(const Color &albedo);
    ~Metal();

    virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const;

private:
    Vec3 reflect(const Vec3 &v, const Vec3 &n) const;
};

#endif
