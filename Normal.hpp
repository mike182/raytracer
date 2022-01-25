#ifndef __NORMAL_HPP__
#define __NORMAL_HPP__

class Normal {
public:
    Normal(void);
    Normal(double a);
    Normal(double x, double y, double z);
    Normal(const Normal & n);
    virtual ~Normal(void);

    Normal & operator=(const Normal & rhs);

public:
    double x, y, z;
};

#endif // __NORMAL_HPP__
