#pragma once

#include "util.hpp"

#include <cmath>

namespace Geometry {

struct Ray {

    // Equation for a point on ray: P(x,y,z) = O(x,y,z) + D(x,y,z) * t

    Ray(util::Vec3 origin, util::Vec3 direction)
        : origin(origin), direction(util::Vec3::normalize(direction)) {}

    util::Vec3  origin;
    util::Vec3  direction;
};

struct Sphere {

    // Equation for a sphere: (x - h)^2 + (y - k)^2 + (z - l)^2 = r^2

    // (h,k,l) are the coordinates of the center of the sphere.
    // r is the radius of the sphere.

    Sphere(util::Vec3 center, float radius, util::Color material);

    float intersects(const Ray &ray);

    util::Vec3 center;
    float radius;
    util::Color material;
};

};