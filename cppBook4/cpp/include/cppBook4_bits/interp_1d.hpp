#ifndef INTERP1D_H
#define INTERP1D_H

#include "nr.hpp"

struct Base_interp
{

    int n, m, jsav, cor, dj;
    const double *x, *y;

    Base_interp(const Vector<double> &x, const double *y, int m);

    double interp(double x);

    int locate(const double x);
    int hunt(const double);
    double virtual rawinterp(int jlo, double x) = 0;
};

struct Poly_interp : Base_interp
{

    double dy;
    Poly_interp(const Vector<double> &x, const Vector<double> &y, int m);

    double rawinterp(int jl, double t);
};

struct Spline_interp : Base_interp
{

    Vector<double> y2;

    Spline_interp(const Vector<double> &x, const Vector<double> &y, double yp1 = 1.e99, double ypn = 1.e99);

    Spline_interp(const Vector<double> &x, const double *y, double yp1 = 1.e99, double ypn = 1.e99);

    void sety2(const double *x, const double *y, double yp1, double ypn);

    double rawinterp(int jl, double t);
};

struct Rat_interp : Base_interp
{

    double dy;
    Rat_interp(const Vector<double> &x, const Vector<double> &y, int m);

    double rawinter(int jl, double x);
};

struct BaryRat_interp : Base_interp
{
    Vector<double> w;
    int d;
    BaryRat_interp(const Vector<double> &x, const Vector<double> &y, int dd);

    double rawinterp(int jl, double t);
    double interp(double t);
};

#endif