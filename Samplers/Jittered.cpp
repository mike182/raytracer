#include "Jittered.hpp"

Jittered::Jittered(void)
    : Sampler()
{
}

Jittered::Jittered(const int num_samples)
    : Sampler(num_samples)
{
    generate_samples();
}

Jittered::Jittered(const int num_samples, const int m)
    : Sampler(num_samples, m)
{
    generate_samples();
}

Jittered::Jittered(const Jittered& sp)
    : Sampler(sp)
{
    generate_samples();
}

Jittered::~Jittered(void) {
}

Jittered* Jittered::clone(void) const {
    return new Jittered(*this);
}

Jittered& Jittered::operator=(const Jittered& rhs) {
    if (this == &rhs)
        return *this;
    Sampler::operator=(rhs);
    return *this;
}

void Jittered::generate_samples(void) {
    int n = (int) sqrt((float)num_samples);

    for (int p = 0; p < num_sets; p++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                Point2D sp((k + rand_float()) / n, (j + rand_float()) / n);
                samples.push_back(sp);
            }
}
