#ifndef __POINT3D_HPP__
#define __POINT3D_HPP__

class Point3D {
public:
    Point3D(void);
    Point3D(const double a);
    Point3D(const double x, const double y, const double z);
    Point3D(const Point3D & p);
    virtual ~Point3D(void);

    Point3D & operator=(const Point3D & rhs);

public:
    double x, y, z;
};

#endif // __POINT3D_HPP__
