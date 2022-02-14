#include "ViewPlane.hpp"
#include "Regular.hpp"
#include "PureRandom.hpp"
#include "NRooks.hpp"
#include "Jittered.hpp"
#include "MultiJittered.hpp"
#include "Hammersley.hpp"
#include <iostream>

ViewPlane::ViewPlane(void)
    : hres(400),
    vres(400),
    s(1.0),
    num_samples(1),
    sampler_ptr(nullptr),
    gamma(1.0),
    inv_gamma(1.0),
    show_out_of_gamut(false),
    max_depth(0)
{
}

ViewPlane::ViewPlane(const ViewPlane& vp)
    : hres(vp.hres),
    vres(vp.vres),
    s(vp.s),
    num_samples(vp.num_samples),
    sampler_ptr(vp.sampler_ptr),
    gamma(vp.gamma),
    inv_gamma(vp.inv_gamma),
    show_out_of_gamut(vp.show_out_of_gamut),
    max_depth(vp.max_depth)
{
}

ViewPlane::~ViewPlane(void) {
}

ViewPlane& ViewPlane::operator=(const ViewPlane& rhs) {
    if (this == &rhs)
        return *this;

    hres = rhs.hres;
    vres = rhs.vres;
    s = rhs.s;
    num_samples = rhs.num_samples;
    gamma = rhs.gamma;
    inv_gamma = rhs.inv_gamma;
    show_out_of_gamut = rhs.show_out_of_gamut;
    max_depth = rhs.max_depth;
    return *this;
}

void ViewPlane::set_hres(int x) {
    hres = x;
    std::cout << "ViewPlane: h_res set to " << x << std::endl;
}

void ViewPlane::set_vres(int y) {
    vres = y;
    std::cout << "ViewPlane: v_res set to " << y << std::endl;
}

void ViewPlane::set_resolution(int x, int y) {
    hres = x;
    vres = y;
    std::cout << "ViewPlane: h_res set to " << x << std::endl;
    std::cout << "ViewPlane: v_res set to " << y << std::endl;
}

void ViewPlane::set_pixel_size(const float size) {
    s = size;
    std::cout << "ViewPlane: pixe_size set to " << s << std::endl;
}

void ViewPlane::set_samples(const int n) {
    num_samples = n;
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    if (num_samples > 1)
        sampler_ptr = new MultiJittered(num_samples);
    else
        sampler_ptr = new Regular(1);
}

void ViewPlane::set_sampler(Sampler* sp) {
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    num_samples = sp->get_num_samples();
    sampler_ptr = sp;
}

void ViewPlane::set_max_depth(const int d) {
    max_depth = d;
    std::cout << "ViewPlane: max_depth set to " << max_depth << std::endl;
}

void ViewPlane::set_gamma(const float g) {
    gamma = g;
    std::cout << "ViewPlane: gamma set to " << gamma << std::endl;
    std::cout << "ViewPlane: inv_gamma set to " << inv_gamma << std::endl;
}

void ViewPlane::set_gamut_display(const bool show) {
    show_out_of_gamut = show;
    std::cout << "ViewPlane: show_out_of_gamut set to " << std::boolalpha << show_out_of_gamut << std::endl;
}
