#include "World.hpp"

#include <iostream>

int main(void) {
    World w;

    w.build();
    if (w.build_info())
        return EXIT_FAILURE;
    w.camera_ptr->render_scene(w);
    return EXIT_SUCCESS;
}
