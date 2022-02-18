#ifndef __GUISDL_HPP__
#define __GUISDL_HPP__

#include "Graphics.hpp"
#include "SDL.h"

class GuiSDL : public Graphics {
public:
    GuiSDL(void);
    GuiSDL(const int width, const int height);
    GuiSDL(const GuiSDL& copy) = delete;
    virtual ~GuiSDL(void);

    GuiSDL& operator=(const GuiSDL& rhs) = delete;

    virtual void init();
    virtual void display(const int x, const int y, const float r, const float g, const float b);
    virtual void render_line();
    virtual void end();

public:
    SDL_Window* window_ptr;
    SDL_Renderer* renderer_ptr;
    SDL_Event event;
};

#endif // __GUISDL_HPP__
