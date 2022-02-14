#ifndef __MATHS_H__
#define __MATHS_H__

#include "Constants.h"

// float min(float a, float b);
// float max(float a, float b);
double min(double a, double b);
double max(double a, double b);

int rand_int(void);
float rand_float(void);
void set_rand_seed(const int seed);
float rand_float(int l, float h); // for multi-jittered sampling
int rand_int(int l, int h); // for multi-jittered sampling

double clamp(const double x, const double min, const double max);

extern "C" {
int SolveQuadric(double c[3], double s[2]);
int SolveCubic(double c[4], double s[3]);
int SolveQuartic(double c[5], double s[4]);
} // extern "C"

//
inline double min(double a, double b) {
    return ((a < b) ? a : b);
}

inline double max(double a, double b) {
    return ((a > b) ? a : b);
}

inline int rand_int(void) {
    return(rand());
}

inline float rand_float(void) {
    return((float)rand_int() * invRAND_MAX);
}

inline void set_rand_seed(const int seed) {
    srand(seed);
}

// for multi-jittered sampling
inline float rand_float(int l, float h) {
    return (rand_float() * (h - l) + l);
}

// for multi-jittered sampling
inline int rand_int(int l, int h) {
    return ((int) (rand_float(0, h - l + 1) + l));
}

inline double clamp(const double x, const double min, const double max) {
    return (x < min ? min : (x > max ? max : x));
}

#endif // __MATHS_H__
