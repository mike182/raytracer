#include "World.hpp"

#include <iostream>

int main(void) {
    World w;

    w.build();
    w.render_scene();
    // if (w.tracer_ptr == nullptr) {
    //     std::cout << "main: " << "tacer_ptr is null" << std::endl;
    //     return EXIT_FAILURE;
    // }
    // w.camera_ptr->render_scene(w);
    return EXIT_SUCCESS;
}
