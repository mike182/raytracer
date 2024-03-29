#ifndef __VIEWPLANE_HPP__
#define __VIEWPLANE_HPP__

#include "Sampler.hpp"

class ViewPlane {
public:
    ViewPlane(void);
    ViewPlane(const ViewPlane& vp);
    virtual ~ViewPlane(void);

    ViewPlane& operator=(const ViewPlane& rhs);

    void set_hres(int hres);
    void set_vres(int vres);
    void set_resolution(int hres, int vres);
    void set_pixel_size(const float size);
    void set_samples(const int n);
    void set_sampler(Sampler* sp);
    void set_max_depth(const int d);

    void set_gamma(const float g);
    void set_gamut_display(const bool show);

public:
    int hres;
    int vres;
    float s;
    int num_samples;
    Sampler* sampler_ptr;

    float gamma;
    float inv_gamma;
    bool show_out_of_gamut;

    int max_depth;
};

#endif // __VIEWPLANE_HPP__
