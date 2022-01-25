#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include <stdlib.h>
#include "RGBColor.hpp"

const double PI = 3.1415926535897932384;

const double kEpsilon = 0.0001;
const double kHugeValue = 1.0E10;

const RGBColor black(0.0);
const RGBColor white(1.0);
const RGBColor red(0.0, 0.0, 0.0);
const RGBColor green(0.0, 1.0, 0.0);
const RGBColor blue(0.0, 0.0, 1.0);
const RGBColor fuchsia(1.0, 0.0, 1.0);

#endif // __CONSTANTS_H__
