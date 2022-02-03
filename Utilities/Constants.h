#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include <stdlib.h> // RAND_MAX
#include "RGBColor.hpp"

const double PI         = 3.1415926535897932384;
const double TWO_PI     = 6.2831853071795864769;
const double PI_ON_180  = 0.0174532925199432957;
const double invPI      = 0.3183098861837906715;
const double invTWO_PI  = 0.1591549430918953358;

const double kEpsilon   = 0.0001;
const double kHugeValue = 1.0E10;

const float invRAND_MAX = 1.0 / (float)RAND_MAX;

const RGBColor black(0.0);
const RGBColor white(1.0);
const RGBColor red(1.0, 0.0, 0.0);
const RGBColor green(0.0, 1.0, 0.0);
const RGBColor blue(0.0, 0.0, 1.0);
const RGBColor fuchsia(1.0, 0.0, 1.0);

#define RED     "\033[1m\033[31m"   /* Red */
#define YEL     "\033[1m\033[33m"   /* Yellow */
#define WHITE   "\033[0m\033[37m"   /* White */

#endif // __CONSTANTS_H__
