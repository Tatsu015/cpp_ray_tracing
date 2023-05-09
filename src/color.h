#ifndef COLOR_H
#define COLOR_H

#include <iostream>

#include "vec3.h"

void write_color(std::ostream &out, Color pixcel_color)
{
    out << static_cast<int>(255.999 * pixcel_color.x()) << ' ' << static_cast<int>(255.999 * pixcel_color.y()) << ' ' << static_cast<int>(255.999 * pixcel_color.z()) << '\n';
}

#endif
