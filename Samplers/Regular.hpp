#ifndef __REGULAR_HPP__
#define __REGULAR_HPP__

#include "Sampler.hpp"

class Regular : public Sampler {
public:
    Regular(void);
    Regular(const int num_samples);
    Regular(const Regular& sp);
    virtual Regular* clone(void) const;
    virtual ~Regular(void);

    Regular& operator=(const Regular& rhs);

// private:
    virtual void generate_samples(void);
};

#endif // __REGULAR_HPP__
