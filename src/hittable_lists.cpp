#include "hittable_list.h"

HittableList::HittableList(std::shared_ptr<Hittable> object)
{
}

HittableList::~HittableList()
{
}

void HittableList::add(std::shared_ptr<Hittable> object)
{
}

void HittableList::clear()
{
}

bool Hittable::hit(const Ray &r, const double t_min, const double t_max, HitRecord &rec) const
{
    return true;
}