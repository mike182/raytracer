#include "ShadeRec.hpp"
#include "Constants.h"

// deleted
// ShadeRec::ShadeRec(void) { }

ShadeRec::ShadeRec(World & w)
    : hit_an_object(false),
    local_hit_point(),
    normal(),
    color(black),
    w(w) { }

ShadeRec::ShadeRec(const ShadeRec & sr)
    : hit_an_object(sr.hit_an_object),
    local_hit_point(sr.local_hit_point),
    normal(sr.normal),
    color(sr.color),
    w(sr.w) { }

ShadeRec::~ShadeRec(void)
{
}

// deleted
// ShadeRec & ShadeRec::operator=(const ShadeRec & rhs) {
//     if (this == &rhs)
//         return *this;

//     // x = rhs.x;
//     // y = rhs.y;
//     // z = rhs.z;

//     return *this;
// }

