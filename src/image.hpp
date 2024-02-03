#pragma once

#include "util.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Image {

  public:

    Image(size_t width, size_t height, std::string name);

    void putPixel(size_t x, size_t y, util::Color c);

    int writePPM() const;

    size_t getImageWidth() const;
    size_t getImageHeight() const;

  private:

    uint32_t image_w, image_h;
    std::string file_name;
    std::vector<std::vector<util::Color>> image;
};
