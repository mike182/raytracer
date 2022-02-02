#include "ShadeRec.hpp"
#include "Constants.h"

// deleted
// ShadeRec::ShadeRec(void) {
// }

ShadeRec::ShadeRec(World& w)
    : hit_an_object(false),
    material_ptr(nullptr),
    hit_point(),
    local_hit_point(),
    normal(),
    ray(),
    depth(0),
    color(black),
    t(0.0),
    u(0.0),
    v(0.0),
    w(w)
{
}

ShadeRec::ShadeRec(const ShadeRec& sr)
    : hit_an_object(sr.hit_an_object),
    material_ptr(sr.material_ptr),
    hit_point(sr.hit_point),
    local_hit_point(sr.local_hit_point),
    normal(sr.normal),
    ray(sr.ray),
    depth(sr.depth),
    color(sr.color),
    t(sr.t),
    u(sr.u),
    v(sr.v),
    w(sr.w)
{
}

#include "World.hpp"
#include "Material.hpp"

ShadeRec::~ShadeRec(void) {
    // if (material_ptr) {
        // delete material_ptr;
        // material_ptr = nullptr;
    // }
}

// deleted
// ShadeRec& ShadeRec::operator=(const ShadeRec& rhs) {
//     if (this == &rhs)
//         return *this;

//     // x = rhs.x;
//     // y = rhs.y;
//     // z = rhs.z;

//     return *this;
// }
