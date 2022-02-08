#ifndef __HAMMERSLEY_HPP__
#define __HAMMERSLEY_HPP__

#include "Sampler.hpp"

class Hammersley : public Sampler {
public:
    Hammersley(void);
    Hammersley(const int num_samples);
    Hammersley(const Hammersley& sp);
    virtual Hammersley* clone(void) const;
    virtual ~Hammersley(void);

    Hammersley& operator=(const Hammersley& rhs);

    double phi(int i);

// private:
    virtual void generate_samples(void);
};

#endif // __HAMMERSLEY_HPP__
