#include "Sampler.hpp"
#include "Constants.h"
#include <algorithm>

Sampler::Sampler(void)
    : num_samples(1),
    num_sets(83),
    count(0),
    jump(0)
{
    samples.reserve(num_samples * num_sets);
    setup_shuffled_indices();
}

Sampler::Sampler(const int ns)
    : num_samples(ns),
    num_sets(83),
    count(0),
    jump(0)
{
    samples.reserve(num_samples * num_sets);
    setup_shuffled_indices();
}

Sampler::Sampler(const int ns, const int n_sets)
    : num_samples(ns),
    num_sets(n_sets),
    count(0),
    jump(0)
{
    samples.reserve(num_samples * num_sets);
    setup_shuffled_indices();
}

Sampler::Sampler(const Sampler& s)
    : num_samples(s.num_samples),
    num_sets(s.num_sets),
    samples(s.samples),
    shuffled_indices(s.shuffled_indices),
    count(s.count),
    jump(s.jump)
{
}

Sampler::~Sampler(void) {
    samples.clear();
}

Sampler& Sampler::operator= (const Sampler& rhs) {
    if (this == &rhs)
        return (*this);
    num_samples = rhs.num_samples;
    num_sets = rhs.num_sets;
    samples = rhs.samples;
    shuffled_indices = rhs.shuffled_indices;
    count = rhs.count;
    jump = rhs.jump;
    return (*this);
}

void Sampler::set_num_sets(const int np) {
    num_sets = np;
}

int Sampler::get_num_samples(void) {
    return num_samples;
}

void Sampler::shuffle_x_coordinates(void) {
    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i <  num_samples - 1; i++) {
            int target = rand_int() % num_samples + p * num_samples;
            float temp = samples[i + p * num_samples + 1].x;
            samples[i + p * num_samples + 1].x = samples[target].x;
            samples[target].x = temp;
        }
}

void Sampler::shuffle_y_coordinates(void) {
    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i <  num_samples - 1; i++) {
            int target = rand_int() % num_samples + p * num_samples;
            float temp = samples[i + p * num_samples + 1].y;
            samples[i + p * num_samples + 1].y = samples[target].y;
            samples[target].y = temp;
        }
}

void Sampler::setup_shuffled_indices(void) {
    shuffled_indices.reserve(num_samples * num_sets);
    std::vector<int> indices;

    for (int j = 0; j < num_samples; j++)
        indices.push_back(j);
    for (int p = 0; p < num_sets; p++) {
        random_shuffle(indices.begin(), indices.end());
        for (int j = 0; j < num_samples; j++)
            shuffled_indices.push_back(indices[j]);
    }
}

Point2D Sampler::sample_unit_square(void) {
    if (count % num_samples == 0) // start of a new pixel
        jump = (rand_int() % num_sets) * num_samples; // random index jump initialised to zero in constructor
    return samples[jump + shuffled_indices[jump + count++ % num_samples]];
}

// the first revised version in Listing in Listing 5.8
// Point2D Sampler::sample_unit_square(void) {
//     if (count % num_samples == 0) // start of a new pixel
//         jump = (rand_int() % num_sets) * num_samples; // random index jump initialised to zero in constructor
//     return samples[jump + count++ % num_samples];
// }

// the original version in Listing 5.7
// Point2D Sampler::sample_unit_square(void) {
//     return samples[count++ % (num_samples * num_sets)];
// }
