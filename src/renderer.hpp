#pragma once

#include "geometry.hpp"
#include "image.hpp"
#include "util.hpp"

class Renderer {

    // TODO: the renderer should take a scene that has all the components in it

  public:

    Renderer(Image *image)
      :image(image) {}

    void render();
    util::Color evalPixel(util::Vec2 coord);

  private:

    Image *image;
};