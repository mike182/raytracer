#ifndef __WORLD_HPP__
#define __WORLD_HPP__

#include "RGBColor.hpp"
// #include "Point2D.hpp"

class World {
public:
    World();
    World(int hres, int vres);
    virtual ~World();

public:
    void build();
    void render();

private:
public:
    int hres;
    int vres;
    // Point2D vp;
    // RGBColor bg;
};

#endif // __WORLD_HPP__
