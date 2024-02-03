
#include "geometry.hpp"
#include "image.hpp"
#include "renderer.hpp"
#include "scene.hpp"

int main(int argc, char **argv) {

    (void)argc;
    (void)argv;

    Image image(1000, 1000, "image");

    util::Vec3 light_dir = util::Vec3::normalize(util::Vec3(0.3f, 0.45f, 1.0f));

    std::vector<Geometry::Sphere> spheres = {
        // { util::Vec3(-0.11f, -0.22f, 0.0f), 0.02f , util::Color(0.18f, 0.18f, 0.18f) },
        // { util::Vec3(0.82f , 0.76f , 0.0f), 0.03f , util::Color(0.12f, 0.18f, 0.27f) },
        // { util::Vec3(-0.65f , -0.39f , 0.0f), 0.1f, util::Color(0.0f, 1.0f, 1.0f) },
        // { util::Vec3(0.10f , 0.06f , 0.0f), 0.03f, util::Color(0.12f, 0.58f, 0.6f) },
        { util::Vec3(0.42f , 0.32f , 0.0f), 0.3f , util::Color(1.0f, 0.0f, 1.0f) },
        { util::Vec3(0.0f, 0.32f, 0.0f), 0.22f , util::Color(0.0f, 1.0f, 1.0f) },
        { util::Vec3(-0.43f , 0.3f , 0.0f), 0.25f, util::Color(1.0f, 1.0f, 1.0f) },
        { util::Vec3(0.00f , 0.00f , 0.0f), 0.35f, util::Color(1.0f, 1.0f, 0.0f) },
    };

    Scene scene(light_dir, spheres);

    Renderer renderer(&image, scene);
    renderer.render();

    image.writePPM();
    return 0;
}
