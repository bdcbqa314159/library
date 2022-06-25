#ifndef INTERPLINEAR_H
#define INTERPLINEAR_H

#include "nr.hpp"
#include "interp_1d.hpp"

struct Linear_interp : Base_interp
{
    Linear_interp(const Vector<double> &x, const Vector<double> &y);

    double rawinterp(int j, double x);
};

#endif