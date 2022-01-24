#include "RGBColor.hpp"

RGBColor::RGBColor() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
    // this->a = 0;
}
RGBColor::RGBColor(int i) {
    this->r = i;
    this->g = i;
    this->b = i;
    // this->a = 0;
}

RGBColor::RGBColor(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
    // this->a = a;
}

RGBColor::RGBColor(int r, int g, int b, int a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

RGBColor::~RGBColor() {
}

