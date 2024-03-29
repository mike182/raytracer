#include "Regular.hpp"

Regular::Regular(void)
    : Sampler()
{
}

Regular::Regular(const int num_samples)
    : Sampler(num_samples)
{
    generate_samples();
}

Regular::Regular(const Regular& sp)
    : Sampler(sp)
{
    generate_samples();
}

Regular::~Regular(void) {
}

Regular* Regular::clone(void) const {
    return new Regular(*this);
}

Regular& Regular::operator=(const Regular& rhs) {
    if (this == &rhs)
        return *this;
    Sampler::operator=(rhs);
    return *this;
}

void Regular::generate_samples(void) {
    int n = (int) sqrt((float)num_samples);

    for (int j = 0; j < num_sets; j++)
        for (int p = 0; p < n; p++)
            for (int q = 0; q < n; q++)
                samples.push_back(Point2D((q + 0.5) / n, (p + 0.5) / n));
}
