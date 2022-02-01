#ifndef __VIEWPLANE_HPP__
#define __VIEWPLANE_HPP__

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

    void set_gamma(const float g);
    void set_gamut_display(const bool show);

public:
    int hres;
    int vres;
    float s;
    int num_samples;

    float gamma;
    float inv_gamma;
    bool show_out_of_gamut;
};

#endif // __VIEWPLANE_HPP__
