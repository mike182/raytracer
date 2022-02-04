#include "World.hpp"

#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
    World w;

    w.build();
    if (argc == 2 && (std::string)argv[argc-1] == "-v")
        if (w.build_info())
            return EXIT_FAILURE;
    w.camera_ptr->render_scene(w);
    return EXIT_SUCCESS;
}
