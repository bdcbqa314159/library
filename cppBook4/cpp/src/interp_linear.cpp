#include "../include/cppBook4_bits/interp_linear.hpp"

Linear_interp::Linear_interp(const Vector<double> &x, const Vector<double> &y) : Base_interp(x, &y[0], 2)
{
}

double Linear_interp::rawinterp(int j, double t)
{
    if (x[j] == x[j + 1])
        return y[j];
    else
        return y[j] + ((t - x[j]) / (x[j + 1] - x[j])) * (y[j + 1] - y[j]);
}