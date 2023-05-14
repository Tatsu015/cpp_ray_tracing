#include "hittable_list.h"

HittableList::HittableList()
{
}

HittableList::HittableList(std::shared_ptr<Hittable> object)
{
    add(object);
}

HittableList::~HittableList()
{
}

void HittableList::add(std::shared_ptr<Hittable> object)
{
    objects_.push_back(object);
}

void HittableList::clear()
{
    objects_.clear();
}

bool HittableList::hit(const Ray &r, const double t_min, const double t_max, HitRecord &rec) const
{

    HitRecord tmp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;

    for (auto o : objects_)
    {
        if (o->hit(r, t_min, closest_so_far, tmp_rec))
        {
            hit_anything = true;
            closest_so_far = tmp_rec.t;
            rec = tmp_rec;
        }
    }

    return hit_anything;
}