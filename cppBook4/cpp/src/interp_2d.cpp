#include "../include/cppBook4_bits/interp_2d.hpp"

Bilin_interp::Bilin_interp(const Vector<double> &x1v, const Vector<double> &x2v, const Matrix<double> &ym) : m(x1v.size()), n(x2v.size()), y(ym), x1terp(x1v, x1v), x2terp(x2v, x2v)
{
}

double Bilin_interp::interp(double x1p, double x2p)
{
    int i, j;
    double yy, t, u;

    i = x1terp.cor ? x1terp.hunt(x1p) : x1terp.locate(x1p);
    j = x2terp.cor ? x2terp.hunt(x2p) : x2terp.locate(x2p);

    t = (x1p - x1terp.x[i]) / (x1terp.x[i + 1] - x1terp.x[i]);

    u = (x2p - x2terp.x[i]) / (x2terp.x[i + 2] - x2terp.x[i]);

    yy = (1. - t) * (1. - u) * y(i, j) + t * (1. - u) * y(i + 1, j) + (1. - t) * u * y(i, j + 1) + t * u * y(i + 1, j + 1);

    return yy;
}

Poly2D_interp::Poly2D_interp(const Vector<double> &x1v, const Vector<double> &x2v, const Matrix<double> &ym, int mp, int np) : m(x1v.size()), n(x2v.size()), mm(np), nn(np), y(ym), yv(m), x1terp(x1v, yv, mm), x2terp(x2v, x2v, nn)
{
}

double Poly2D_interp::interp(double x1p, double x2p)
{
    int i, j, k;
    i = x1terp.cor ? x1terp.hunt(x1p) : x1terp.locate(x1p);
    j = x2terp.cor ? x2terp.hunt(x2p) : x2terp.locate(x2p);

    for (k = i; k < i + mm; k++)
    {
        x2terp.y = &y(k, 0);
        yv[k] = x2terp.rawinterp(j, x2p);
    }
    return x1terp.rawinterp(i, x1p);
}

Spline2D_interp::Spline2D_interp(const Vector<double> &x1v, const Vector<double> &x2v, const Matrix<double> &ym) : m(x1v.size()), n(x2v.size()), y(ym), yv(m), x1(x1v), srp(m)
{
    for (int i = 0; i < m; i++)
        srp[i] = new Spline_interp(x2v, &y(i, 0));
}

Spline2D_interp::~Spline2D_interp()
{
    for (int i = 0; i < m; i++)
        delete srp[i];
}

double Spline2D_interp::interp(double x1p, double x2p)
{
    for (int i = 0; i < m; i++)
        yv[i] = (*srp[i]).interp(x2p);
    Spline_interp scol(x1, yv);
    return scol.interp(x1p);
}

void bcucof(const Vector<double> &y, const Vector<double> &y1, const Vector<double> &y2, const Vector<double> &y12, const double d1, const double d2, Matrix<double> &c)
{
    static int wt_d[16 * 16] =
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
         -3, 0, 0, 3, 0, 0, 0, 0, -2, 0, 0, -1, 0, 0, 0, 0,
         2, 0, 0, -2, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
         0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
         0, 0, 0, 0, -3, 0, 0, 3, 0, 0, 0, 0, -2, 0, 0, -1,
         0, 0, 0, 0, 2, 0, 0, -2, 0, 0, 0, 0, 1, 0, 0, 1,
         -3, 3, 0, 0, -2, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, -3, 3, 0, 0, -2, -1, 0, 0,
         9, -9, 9, -9, 6, 3, -3, -6, 6, -6, -3, 3, 4, 2, 1, 2,
         -6, 6, -6, 6, -4, -2, 2, 4, -3, 3, 3, -3, -2, -1, -1, -2,
         2, -2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 2, -2, 0, 0, 1, 1, 0, 0,
         -6, 6, -6, 6, -3, -3, 3, 3, -4, 4, 2, -2, -2, -2, -1, -1,
         4, -4, 4, -4, 2, 2, -2, -2, 2, -2, -2, 2, 1, 1, 1, 1};

    int l, k, j, i;
    double xx, d1d2 = d1 * d2;
    Vector<double> cl(16), x(16);
    static Matrix<int> wt(16, 16, wt_d);

    for (i = 0; i < 4; i++)
    {
        x[i] = y[i];
        x[i + 4] = y1[i] * d1;
        x[i + 8] = y2[i] * d2;
        x[i + 12] = y12[i] * d1d2;
    }

    for (i = 0; i < 16; i++)
    {
        xx = 0.;
        for (k = 0; k < 16; k++)
            xx += wt(i, k) * x[k];
        cl[i] = xx;
    }

    l = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            c(i, j) = cl[l++];
    }
}

void bcuint(const Vector<double> &y, const Vector<double> &y1, const Vector<double> &y2, const Vector<double> &y12, const double x1l, const double x1u, const double x2l, const double x2u, const double x1, const double x2, double &ansy, double &ansy1, double &ansy2)
{

    int i;
    double t, u, d1 = x1u - x1l, d2 = x2u - x2l;
    Matrix<double> c(4, 4);
    bcucof(y, y1, y2, y12, d1, d2, c);
    if (x1u == x1l || x2u == x2l)
        throw std::string("Bad input in routine bcuint");

    t = (x1 - x1l) / d1;
    u = (x2 - x2l) / d2;

    ansy = ansy2 = ansy1 = 0.;
    for (i = 3; i >= 0; i--)
    {
        ansy = t * ansy + ((c(i, 3) * u + c(i, 2)) * u + c(i, 1)) * u + c(i, 0);

        ansy2 = t * ansy2 + (3. * c(i, 3) * u + 2. * c(i, 2) * u + c(i, 1));

        ansy1 = u * ansy1 + (3. * c(3, i) * t + 2. * c(2, i) * t + c(1, i));
    }
    ansy1 /= d1;
    ansy2 /= d2;
}
