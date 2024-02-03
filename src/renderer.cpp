
#include "renderer.hpp"

#include "geometry.hpp"
#include "image.hpp"
#include "util.hpp"

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

    // virtual camera position
    util::Vec3 camera_pos(0.0f, 0.0f, -5.0f);

    // the FOV 
    float focal_point = 1.0f;

    // the ray from the focal point towards the scene
    util::Vec3 ray_dir(coord.x, coord.y, focal_point);

    // figures out what need to be rendered without streching image
    ray_dir = util::Vec3::normalize(ray_dir - camera_pos);

    // the actual camera when the calculation are done regarding FOV
    Geometry::Ray camera(camera_pos, ray_dir);

    // Geometry::Ray camera(util::Vec3(0.0f, 0.0f, -1.0f),
    //                      util::Vec3(coord.x, coord.y, 1.0f));

    for (auto &sphere : scene.spheres) {

        float hit_dist = sphere.intersects(camera);

        if (hit_dist != -1.0f) {

            util::Vec3 hit_point = camera.origin + camera.direction * hit_dist;
            util::Vec3 hit_point_normal = util::Vec3::normalize(hit_point - sphere.center);

            // dot product gives angle between two vectors by |a|*|b|*cos(angle)
            // here a and b are normalized so float f -> cos(angle)
            float f = util::Vec3::dot(hit_point_normal, scene.light_dir * -1);

            // Note: the light direction will be opposite
            // to what is specified because the angle in cos(a)
            // util::Color color = (hit_point * 1.5f)* f;
            // util::Color color = (hit_point + util::Vec3(1.0f, 1.0f, 1.0f) / 2) * f;
            util::Color color = sphere.material * f;

            return util::Color(color);
        }
        
    }

    return util::Color(coord.x, coord.y, 0.5f);
    // return util::Color(0.0f, 0.0f, 0.0f);
}
