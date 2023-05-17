#include "color.h"
#include "mathutil.h"

void write_color(std::ostream &out, Color pixcel_sum_color, const int sample_per_pixcel)
{
    double r = pixcel_sum_color.x();
    double g = pixcel_sum_color.y();
    double b = pixcel_sum_color.z();

    const double scale = 1.0 / sample_per_pixcel;

    // gamma correction
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    out << static_cast<int>(256 * clamp(r, 0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0, 0.999)) << '\n';
}