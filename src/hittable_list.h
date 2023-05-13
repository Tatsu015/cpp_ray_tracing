#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <vector>
#include <memory>

#include "hittable.h"

class HittableList : public : Hittable
{
public:
    std::vector<std::shared_ptr<Hittable>> objects;

public:
    HittableList();
    ~HittableList();

    void add(std::shared_ptr<Hittable> object);
    void clear();

    bool hit(const Ray &r, const double t_min, const double t_max, HitRecord &rec) const;
};

#endif
