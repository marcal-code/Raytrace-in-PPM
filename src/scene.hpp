#pragma once

#include "geometry.hpp"
#include "util.hpp"

#include <vector>

class Scene {

  public:

    Scene(util::Vec3 light_dir, std::vector<Geometry::Sphere> spheres)
	: light_dir(light_dir), spheres(spheres) {}

    util::Vec3 light_dir;
    std::vector<Geometry::Sphere> spheres;
};
