#ifndef __SAMPLER_HPP__
#define __SAMPLER_HPP__

#include "Point2D.hpp"
#include "Point3D.hpp"
#include "Maths.h"
#include <vector>
#include <cmath>

class Sampler {
public:
    Sampler(void);
    Sampler(const int num);
    Sampler(const int num, const int num_sets);
    Sampler(const Sampler& s);
    virtual Sampler* clone(void) const = 0;
    virtual ~Sampler(void);

    Sampler& operator= (const Sampler& rhs);

    virtual void generate_samples(void) = 0;
    void set_num_sets(const int np);
    int get_num_samples(void);
    void shuffle_x_coordinates(void);
    void shuffle_y_coordinates(void);
    void setup_shuffled_indices(void);

    Point2D sample_unit_square(void);

protected:
    int num_samples;
    int num_sets;
    std::vector<Point2D> samples;
    std::vector<int> shuffled_indices;
    unsigned long count;
    int jump;
};

#endif // __SAMPLER_HPP__
