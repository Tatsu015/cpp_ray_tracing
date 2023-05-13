#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <vector>
#include <memory>

#include "hittable.h"

class HittableList : public : Hittable
{
public:
    std::vector<shared_ptr<hittable>> objects;

public:
    HittableList();
    ~HittableList();
};

HittableList::HittableList(/* args */)
{
}

HittableList::~HittableList()
{
}

#endif
