#pragma once

#include "util.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Image {

  public:

    Image(uint32_t width, uint32_t height, std::string name);

    void putPixel(uint32_t x, uint32_t y, util::Color c);

    int writePPM() const;

    uint32_t getImageWidth() const;
    uint32_t getImageHeight() const;

  private:

    uint32_t image_w, image_h;
    std::string fileName;
    std::vector<std::vector<util::Color>> image;
};