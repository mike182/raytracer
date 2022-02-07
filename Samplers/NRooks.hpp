#ifndef __NROOKS_HPP__
#define __NROOKS_HPP__

#include "Sampler.hpp"

class NRooks : public Sampler {
public:
    NRooks(void);
    NRooks(const int num_samples);
    NRooks(const int num_samples, const int m);
    NRooks(const NRooks& sp);
    virtual NRooks* clone(void) const;
    virtual ~NRooks(void);

    NRooks& operator=(const NRooks& rhs);

// private:
    virtual void generate_samples(void);
};

#endif // __NROOKS_HPP__
