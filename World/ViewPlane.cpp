#include "ViewPlane.hpp"

#include <iostream>

ViewPlane::ViewPlane(void)
    :  hres(400), vres(400),
    s(1.0), num_samples(1),
    gamma(1.0), inv_gamma(1.0),
    show_out_of_gamut(false)
       // :  hres(vp.hres), vres(vp.vres), s(vp.s), num_samples(vp.num_samples) { }
{
}

ViewPlane::ViewPlane(const ViewPlane& vp)
    :  hres(vp.hres),
    vres(vp.vres),
    s(vp.s),
    num_samples(vp.num_samples),
    gamma(vp.gamma),
    inv_gamma(vp.inv_gamma),
    show_out_of_gamut(vp.show_out_of_gamut)
       // :  hres(vp.hres), vres(vp.vres), s(vp.s), num_samples(vp.num_samples)
{
}

ViewPlane::~ViewPlane(void)
{
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
    std::cout << "ViewPlane: resolution set to " << x << ", " << y << std::endl;
}

void ViewPlane::set_pixel_size(const float size) {
    this->s = size;
    std::cout << "ViewPlane: pixe_size set to " << s << std::endl;
}

void ViewPlane::set_samples(const int n) {
    this->num_samples = n;
    std::cout << "ViewPlane: num_samples set to " << num_samples << std::endl;
}

void ViewPlane::set_gamma(const float g) {
    this->gamma = g;
    std::cout << "ViewPlane: gamma set to " << gamma << std::endl;
    std::cout << "ViewPlane: inv_gamma set to " << inv_gamma << std::endl;
}

void ViewPlane::set_gamut_display(const bool show) {
    this->show_out_of_gamut = show;
    std::cout << "ViewPlane: show_out_of_gamut set to " << std::boolalpha << show_out_of_gamut << std::endl;
}
