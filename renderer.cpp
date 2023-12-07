
#include "renderer.hpp"

#include "geometry.hpp"
#include "image.hpp"
#include "util.hpp"

#include <memory>

void Renderer::render() {

    float aspect_ratio = (float)image->getImageWidth() /
                         (float)image->getImageHeight();

    for (size_t i = 0; i < image->getImageHeight(); i++) {

        for (size_t j = 0; j < image->getImageWidth(); j++) {

            // making the coords to be from 0 to 1
            util::Vec2 coord((float)j / (float)image->getImageWidth(),
                             (float)i / (float)image->getImageHeight());

            // making the screen to be from -1 to 1
            coord.x = coord.x * 2.0f - 1.0f;
            coord.y = coord.y * 2.0f - 1.0f;

            // in case the screen is not perfect square
            coord.y = coord.y / aspect_ratio;

            util::Color c = util::Color::convertRGB(evalPixel(coord));

            image->putPixel(j, i, c);
        }
    }
}

util::Color Renderer::evalPixel(util::Vec2 coord) {

    // Camera facing the scene
    Geometry::Ray ray(util::Vec3(0.0f, 0.0f, -1.0f),
                      util::Vec3(coord.x, coord.y, 1.0f));

    Geometry::Sphere sphere(util::Vec3(0.0f, 0.0f, 0.0f), 0.5f,
                             util::Color(0.60f, 0.2f, 0.93f));

    util::Vec3 light_dir =
        util::Vec3::normalize(util::Vec3(-1.0f, -1.0f, -1.0f));

    float hit_dist = sphere.intersects(ray);

    if (hit_dist != -1.0f) {

        util::Vec3 hit_point = ray.origin + ray.direction * hit_dist;
        util::Vec3 hit_point_normal = util::Vec3::normalize(hit_point);

        // dot product gives angle between two vectors by |a|*|b|*cos(angle)
        // here a and b are normalized so float f -> cos(angle)
        float f = util::Vec3::dot(hit_point_normal, light_dir);

        util::Color color = sphere.material * f;

        return util::Color(color);
    } 

    return util::Color(0.0f, 0.0f, 0.0f);
}
