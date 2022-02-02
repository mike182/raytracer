#ifndef __PURERANDOM_HPP__
#define __PURERANDOM_HPP__

#include "Sampler.hpp"

class PureRandom : public Sampler {
public:
    PureRandom(void);
    PureRandom(const int num_samples);
    PureRandom(const PureRandom& sp);
    virtual PureRandom* clone(void) const;
    virtual ~PureRandom(void);

    PureRandom& operator=(const PureRandom& rhs);

// private:
    virtual void generate_samples(void);
};

#endif // __PURERANDOM_HPP__
