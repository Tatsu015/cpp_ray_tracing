#include <iostream>

int main(int argc, char const *argv[])
{
    const int IMAGE_WIDTH = 256;
    const int IMAGE_HEIGHT = 256;

    std::cout << "P3\n"
              << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n"
              << "255\n"
              << std::endl;

    for (int i = 0; i < IMAGE_HEIGHT - 1; i++)
    {
        for (int j = 0; j < IMAGE_WIDTH - 1; j++)
        {
            auto r = double(i) / (IMAGE_WIDTH - 1);
            auto g = double(j) / (IMAGE_HEIGHT - 1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
        }
    }

    return 0;
}
