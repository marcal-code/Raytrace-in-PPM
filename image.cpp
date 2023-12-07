
#include "image.hpp"

#include "util.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Image::Image(uint32_t width, uint32_t height, std::string name)
    : image_w(width), image_h(height), image(height, std::vector<util::Color>(width)),
      fileName(name + ".ppm") {}

void Image::putPixel(uint32_t x, uint32_t y, util::Color color) {

    if (x > image_w - 1 || y > image_h - 1 || x < 0 || y < 0) {

        std::cerr << "out of bound pixel allocation: "
                  << "( x:" << x << " , y:" << y << " )" << "\n";
        return;
    }

    // color.print();
    image[y][x] = color;
}

int Image::writePPM() const {

    std::ofstream imgFile(fileName);
    if (!imgFile.is_open()) {

        std::cerr << "No such imgFile opened: imgFile in Image::writePPM";
        return -1;
    }

    imgFile << "P3 " << image_w << " " << image_h << "\n255\n";

    for (const auto &row : image) {

        for (const auto &color : row) {

            imgFile << (int)color.r << " " << (int)color.g << " "
                    << (int)color.b << " ";
        }

        imgFile << "\n";
    }

    return 0;
}

uint32_t Image::getImageWidth() const {
    return image_w;
}

uint32_t Image::getImageHeight() const {
    return image_h;
}