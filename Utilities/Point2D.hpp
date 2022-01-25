#ifndef __POINT2D_HPP__
#define __POINT2D_HPP__

class Point2D {
public:
    Point2D(void);
    Point2D(const float a);
    Point2D(const float x, const float y);
    Point2D(const Point2D & p);
    virtual ~Point2D(void);

    Point2D & operator=(const Point2D & rhs);
    Point2D operator*(const float a);

public:
    float x, y;
};

#endif // __POINT2D_HPP__
