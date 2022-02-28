#include "Graphics.hpp"
#include <cstdlib>

Graphics::Graphics(void)
    : width(400),
    height(400)
{
    buffer.reserve(400 * 400);
}

Graphics::Graphics(const int w, const int h)
    : width(w),
    height(h)
{
    buffer.reserve(width * height);
}

Graphics::~Graphics(void) {
}

void Graphics::init() {
// void Graphics::init(World * w_ptr) {
// #ifdef HAS_SDL
//     w_ptr->gfx_ptr = new GuiSDL(w.vp.hres, w.vp.vres);
// #else
//     w_ptr->gfx_ptr = new ImgPNG(w.vp.hres, w.vp.vres);
//     // w_ptr->gfx_ptr = new ImgJPEG(w.vp.hres, w.vp.vres);
// #endif
}

void Graphics::display([[maybe_unused]]int x, [[maybe_unused]]int y, [[maybe_unused]]float r, [[maybe_unused]]float g, [[maybe_unused]]float b) {
}

void Graphics::render_line() {
}

void Graphics::get_event() {
}

void Graphics::end() {
}
