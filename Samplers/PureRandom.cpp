#include "PureRandom.hpp"

PureRandom::PureRandom(void)
    : Sampler()
{
}

PureRandom::PureRandom(const int num_samples)
    : Sampler(num_samples)
{
    generate_samples();
}

PureRandom::PureRandom(const PureRandom& sp)
    : Sampler(sp)
{
    generate_samples();
}

PureRandom::~PureRandom(void) {
}

PureRandom* PureRandom::clone(void) const {
    return new PureRandom(*this);
}

PureRandom& PureRandom::operator=(const PureRandom& rhs) {
    if (this == &rhs)
        return *this;
    Sampler::operator=(rhs);
    return *this;
}

void PureRandom::generate_samples(void) {
    for (int p = 0; p < num_sets; p++)
        for (int q = 0; q < num_samples; q++)
            samples.push_back(Point2D(rand_float(), rand_float()));
}
