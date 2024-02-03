
#include "image.hpp"

#include "util.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Image::Image(size_t width, size_t height, std::string name)
    : image_w(width), image_h(height), file_name(name + ".ppm"),
      image(height, std::vector<util::Color>(width)) {}

void Image::putPixel(size_t x, size_t y, util::Color color) {

    if (x > image_w - 1 || y > image_h - 1) {

        std::cerr << "out of bound pixel allocation: "
                  << "( x:" << x << " , y:" << y << " )" << "\n";
        return;
    }

    image[y][x] = color;
}

int Image::writePPM() const {

    std::ofstream img_file(file_name);
    if (!img_file.is_open()) {

        std::cerr << "Couldnt not open " << file_name << " in Image::writePPM";
        return -1;
    }

    img_file << "P3 " << image_w << " " << image_h << "\n255\n";

    for (const auto &row : image) {

        for (const auto &color : row) {

            img_file << (int)color.r << " " << (int)color.g << " "
                    << (int)color.b << " ";
        }

        img_file << "\n";
    }

    return 0;
}

size_t Image::getImageWidth() const {
    return image_w;
}

size_t Image::getImageHeight() const {
    return image_h;
}
