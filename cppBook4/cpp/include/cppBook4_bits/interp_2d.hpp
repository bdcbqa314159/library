#ifndef INTERP2D_H
#define INTERP2D_H

#include "interp_linear.hpp"
#include "interp_1d.hpp"

struct Bilin_interp
{
    int m, n;
    const Matrix<double> &y;

    Linear_interp x1terp, x2terp;

    Bilin_interp(const Vector<double> &x1v, const Vector<double> &x2v, const Matrix<double> &ym);

    double interp(double x1p, double x2p);
};

struct Poly2D_interp
{
    int m, n, mm, nn;
    const Matrix<double> &y;
    Vector<double> yv;

    Poly_interp x1terp, x2terp;

    Poly2D_interp(const Vector<double> &x1v, const Vector<double> &x2v, const Matrix<double> &ym, int mp, int np);

    double interp(double x1p, double x2p);
};

struct Spline2D_interp
{

    int m, n;
    const Matrix<double> &y;
    const Vector<double> &x1;
    Vector<double> yv;
    Vector<Spline_interp *> srp;

    Spline2D_interp(const Vector<double> &x1v, const Vector<double> &x2v, const Matrix<double> &ym);

    ~Spline2D_interp();
    double interp(double x1p, double x2p);
};

void bcucof(const Vector<double> &y, const Vector<double> &y1, const Vector<double> &y2, const Vector<double> &y12, const double d1, const double d2, Matrix<double> &c);

void bcuint(const Vector<double> &y, const Vector<double> &y2, const Vector<double> &y12, const double x1l, const double x1u, const double x2l, const double x2u, const double x1, const double x2, double &ansy, double &ansy1, double &ansy2);

#endif