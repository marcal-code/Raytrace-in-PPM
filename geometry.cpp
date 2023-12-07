
#include "geometry.hpp"

#include "util.hpp"

#include <cmath>

namespace Geometry {

Sphere::Sphere(util::Vec3 center, float radius, util::Color material)
    : center(center), radius(radius), material(material) {}

float Sphere::intersects(const Ray &ray) {


    //  return the distance from the origin of the Ray to the point of contact.
    //  if any contact, otherwise returns -1

    //? if the origin of the ray is O(x,y,z) and Direction is D(x,y,z) then the
    //? quadratic equation showing the relation between the sphere and the ray is
    //? give as follows:

    // sphere at the origin (0, 0, 0)
    //! (Dx^2 + Dy^2 + Dz^2) + 2(OxDx + OyDy + OzDz)t + Ox^2 + Oy^2 + Oz^2 - r^2 = 0
    
    // where t is the distance from ray origin to hit point

    // comparing the above quadratic equation with ax^2 + bx + c = 0
    // we have,
    //! x = t
    //! a = (Dx^2 + Dy^2 + Dz^2)
    //! b = 2(OxDx + OyDy + OzDz)t
    //! c = Ox^2 + Oy^2 + Oz^2 - r^2 = 0

    util::Vec3 sphere_to_ray = ray.origin - center;

    //* float a = ray.direction.dot(ray.direction);
    float a = 1.0f; // since the ray direction is already normalized
    float b = 2.0f * util::Vec3::dot(ray.direction, ray.origin);
    float c = util::Vec3::dot(ray.origin, ray.origin) - radius * radius;

    // b^2 - 4ac
    float discriminant = b * b - 4.0f * a * c;

    if (discriminant >= 0) {

        // only calculating the closest hitpoint
        //(-b - root(b^2 - 4ac)) / 2
        float distance = (-b - std::sqrt(discriminant)) / (2 * a);
        return distance;
    }

    // not connection between ray and the sphere
    return -1.0f;
}

};
