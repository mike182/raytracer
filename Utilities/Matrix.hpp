#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include "Normal.hpp"

class Matrix {
public:
    Matrix(void);
    Matrix(const Matrix& m);
    ~Matrix (void);

    Matrix& operator=(const Matrix& rhs);
    Matrix operator*(const Matrix& m) const;
    Matrix operator/(const double d);

    Point3D operator*(const Point3D& p);
    Normal operator*(const Normal& n);

    void set_identity(void);

public:
    double m[4][4];
};

#endif // __MATRIX_HPP__
