#include "ViewPlane.hpp"

ViewPlane::ViewPlane(void)
    :  hres(400), vres(400) { }
    // :  hres(vp.hres), vres(vp.vres), s(vp.s), num_samples(vp.num_samples) { }

ViewPlane::ViewPlane(const ViewPlane & vp)
    :  hres(vp.hres), vres(vp.vres) { }
    // :  hres(vp.hres), vres(vp.vres), s(vp.s), num_samples(vp.num_samples) { }

ViewPlane::~ViewPlane(void)
{
}

ViewPlane & ViewPlane::operator=(const ViewPlane & rhs) {
    if (this == &rhs)
        return *this;

    hres = rhs.hres;
    vres = rhs.vres;
    // s = rhs.s;
    // num_samples = rhs.num_samples;

    return *this;
}

void ViewPlane::set_hres(int x) {
    hres = x;
}

void ViewPlane::set_vres(int y) {
    vres = y;
}

void ViewPlane::set_resolution(int x, int y) {
    hres = x;
    vres = y;
}

void ViewPlane::set_pixel_size(const float size) {
    this->s = size;
}

void ViewPlane::set_samples(const int n) {
    this->num_samples = n;
}

//  void ViewPlane::set_gamma(const float g) {
//      this->gamma = g;
//  }

//  void ViewPlane::set_gamut_display(const bool show) {
//      this->show_out_of_gamut = show;
//  }


