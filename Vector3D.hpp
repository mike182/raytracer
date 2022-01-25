#ifndef __VECTOR3D_HPP__
#define __VECTOR3D_HPP__

class Vector3D {
public:
    Vector3D(void);
    Vector3D(double a);
    Vector3D(double x, double y, double z);
    Vector3D(const Vector3D & v);
    virtual ~Vector3D(void);

    Vector3D & operator=(const Vector3D & rhs);

public:
    double x, y, z;
};

#endif // __VECTOR3D_HPP__
