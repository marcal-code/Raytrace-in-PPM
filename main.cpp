
#include "image.hpp"
#include "renderer.hpp"

int main(int argc, char *argv[]) {

    Image image(1400, 1000, "sphere");
    // the ppm of name sphere.ppm should be generated!!

    Renderer renderer(&image);
    renderer.render();    

    image.writePPM();

    return 0;
}
