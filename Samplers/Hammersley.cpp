#include "Hammersley.hpp"

Hammersley::Hammersley(void)
    : Sampler()
{
}

Hammersley::Hammersley(const int num_samples)
    : Sampler(num_samples)
{
    generate_samples();
}

Hammersley::Hammersley(const Hammersley& sp)
    : Sampler(sp)
{
    generate_samples();
}

Hammersley::~Hammersley(void) {
}

Hammersley* Hammersley::clone(void) const {
    return new Hammersley(*this);
}

Hammersley& Hammersley::operator=(const Hammersley& rhs) {
    if (this == &rhs)
        return *this;
    Sampler::operator=(rhs);
    return *this;
}

void Hammersley::generate_samples(void) {
    for (int p = 0; p < num_sets; p++)
        for (int j = 0; j < num_samples; j++) {
            Point2D pv((float) j / (float) num_samples, (float) phi(j));
            samples.push_back(pv);
        }
}

double Hammersley::phi(int i) {
    double x = 0.0;
    double f = 0.5;

    while (i) {
        x += f * (double) (i % 2);
        i /= 2;
        f *= 0.5;
    }
    return x;
}
