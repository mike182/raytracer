#include "Normal.hpp"

Normal::Normal(void)
    : x(0.0), y(0.0), z(0.0) { }

Normal::Normal(double a)
    : x(a), y(a), z(a) { }

Normal::Normal(double x, double y, double z)
    : x(x), y(y), z(z) { }

Normal::Normal(const Normal & n)
    : x(n.x), y(n.y), z(n.z) { }

Normal::~Normal(void)
{
}

Normal & Normal::operator=(const Normal & rhs) {
    if (this == &rhs)
        return *this;

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

