#include "World.hpp"
#include "Graphics.hpp"
#include <iostream>

// #define HAS_SDL

// move this to static init()
#ifdef HAS_SDL
#include "GuiSDL.hpp"
#else
#include "ImgPNG.hpp"
// #include "ImgJPEG.hpp"
#endif

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
    World w;

    w.build();

    if (argc == 2 && (std::string)argv[argc-1] == "-v")
        if (w.build_info())
            return EXIT_FAILURE;

// move this to static init()
#ifdef HAS_SDL
    w.gfx_ptr = new GuiSDL(w.vp.hres, w.vp.vres);
#else
    w.gfx_ptr = new ImgPNG(w.vp.hres, w.vp.vres);
    // w.gfx_ptr = new ImgJPEG(w.vp.hres, w.vp.vres);
#endif
    w.gfx_ptr->init();
    w.camera_ptr->render_scene(w);
    w.gfx_ptr->end();
    return EXIT_SUCCESS;
}
