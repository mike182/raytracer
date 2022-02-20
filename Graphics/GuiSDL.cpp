#include "GuiSDL.hpp"

GuiSDL::GuiSDL(void)
    : Graphics(),
    window_ptr(nullptr),
    renderer_ptr(nullptr)
{
    window_ptr = SDL_CreateWindow(
        "rt - SDL",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        400, 400,
        0);
    renderer_ptr = SDL_CreateRenderer(window_ptr, -1, SDL_RENDERER_SOFTWARE);
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        // exit ?
    }
    SDL_SetRenderDrawColor(renderer_ptr, 0, 0, 0, 0);
    SDL_RenderClear(renderer_ptr);
    SDL_RenderPresent(renderer_ptr);
}

GuiSDL::GuiSDL(const int w, const int h)
    : Graphics(w, h),
    window_ptr(nullptr),
    renderer_ptr(nullptr)
{
    window_ptr = SDL_CreateWindow(
        "rt - SDL",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width, height,
        0);
    renderer_ptr = SDL_CreateRenderer(window_ptr, -1, SDL_RENDERER_SOFTWARE);
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        // exit ?
    }
    SDL_SetRenderDrawColor(renderer_ptr, 0, 0, 0, 0);
    SDL_RenderClear(renderer_ptr);
    SDL_RenderPresent(renderer_ptr);
}

GuiSDL::~GuiSDL(void) {
}

void GuiSDL::init() {
}

void GuiSDL::display(int x, int y, float r, float g, float b) {
    SDL_SetRenderDrawColor(renderer_ptr, r, g, b, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(renderer_ptr, x, y);
    // SDL_RenderClear(renderer_ptr);
    // SDL_RenderPresent(renderer_ptr);
}

void GuiSDL::render_line() {
    SDL_RenderPresent(renderer_ptr);
}

void GuiSDL::get_event() {
    if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
        exit(EXIT_FAILURE);
}

void GuiSDL::end() {
    while (true) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
    SDL_DestroyRenderer(renderer_ptr);
    SDL_DestroyWindow(window_ptr);
    SDL_Quit();
}
