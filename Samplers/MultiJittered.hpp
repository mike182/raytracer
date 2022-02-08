#ifndef __MULTIJITTERED_HPP__
#define __MULTIJITTERED_HPP__

#include "Sampler.hpp"

class MultiJittered : public Sampler {
public:
    MultiJittered(void);
    MultiJittered(const int num_samples);
    MultiJittered(const int num_samples, const int m);
    MultiJittered(const MultiJittered& sp);
    virtual MultiJittered* clone(void) const;
    virtual ~MultiJittered(void);

    MultiJittered& operator=(const MultiJittered& rhs);

// private:
    virtual void generate_samples(void);
};

#endif // __MULTIJITTERED_HPP__
