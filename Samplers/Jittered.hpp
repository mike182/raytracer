#ifndef __JITTERED_HPP__
#define __JITTERED_HPP__

#include "Sampler.hpp"

class Jittered : public Sampler {
public:
    Jittered(void);
    Jittered(const int num_samples);
    Jittered(const int num_samples, const int m);
    Jittered(const Jittered & js);
    virtual Jittered* clone(void) const;
    virtual ~Jittered(void);

    Jittered & operator=(const Jittered & rhs);

private:
    virtual void generate_samples(void);
};

#endif // __JITTERED_HPP__
