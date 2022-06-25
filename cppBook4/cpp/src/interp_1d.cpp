#include "../include/cppBook4_bits/interp_1d.hpp"

Base_interp::Base_interp(const Vector<double> &x, const double *y, int m) : n(x.size()), m(m), jsav(0), cor(0), x(&x[0]), y(y)
{

    dj = std::min(1, (int)pow((double)n, 0.25));
}

double Base_interp::interp(double x)
{
    int jlo = cor ? hunt(x) : locate(x);
    return rawinterp(jlo, x);
}

int Base_interp::locate(const double t)
{
    int ju, jm, jl;

    if (n < 2 || m < 2 || m > n)
        throw std::string("locate size error");

    bool ascnd = (x[n - 1] >= x[0]);

    jl = 0;
    ju = n - 1;

    while (ju - jl > 1)
    {
        jm = (ju + jl) >> 1;
        if (t >= x[jm] == ascnd)
            jl = jm;
        else
            ju = jm;
    }

    cor = abs(jl - jsav) > dj ? 0 : 1;
    jsav = jl;
    return std::max(0, std::min(n - m, jl - ((m - 2) >> 1)));
}

int Base_interp::hunt(const double t)
{
    int jl = jsav, jm, ju, inc = 1;
    if (n < 2 || m < 2 || m > n)
        throw std::string("hunt size error");

    bool ascnd = (x[n - 1] >= x[0]);
    if (jl < 0 || jl > n - 1)
    {
        jl = 0;
        ju = n - 1;
    }

    else
    {
        if (t >= x[jl] == ascnd)
        {
            for (;;)
            {
                ju = jl + inc;
                if (ju >= n - 1)
                {
                    ju = n - 1;
                    break;
                }
                else if (t < x[ju] == ascnd)
                    break;
                else
                {
                    jl = ju;
                    inc += inc;
                }
            }
        }
        else
        {
            ju = jl;
            for (;;)
            {
                jl = jl - inc;
                if (jl <= 0)
                {
                    jl = 0;
                    break;
                }

                else if (t >= x[jl] == ascnd)
                    break;
                else
                {
                    ju = jl;
                    inc += inc;
                }
            }
        }
    }
    while (ju - jl > 1)
    {
        jm = (ju + jl) >> 1;
        if (t >= x[jm] == ascnd)
            jl = jm;
        else
            ju = jm;
    }

    cor = abs(jl - jsav) > dj ? 0 : 1;
    jsav = jl;
    return std::max(0, std::min(n - m, jl - ((m - 2) >> 1)));
}

Poly_interp::Poly_interp(const Vector<double> &x, const Vector<double> &y, int m) : Base_interp(x, &y[0], m), dy(0.)
{
}

double Poly_interp::rawinterp(int jl, double t)
{

    // int n, m, jsav, cor, dj;
    // const double *x, *y;

    int ns = 0;
    double z, den, dif, dift, ho, hp, w;
    const double *xa = &x[jl], *ya = &y[jl];
    Vector<double> c(m), d(m);
    dif = abs(t - xa[0]);

    for (int i = 0; i < m; i++)
    {
        if ((dift = abs(t - xa[i])) < dif)
        {
            ns = i;
            dif = dift;
        }

        c[i] = ya[i];
        d[i] = ya[i];
    }

    z = ya[ns--];
    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < m - j; i++)
        {
            ho = xa[i] - t;
            hp = xa[i + m] - t;
            w = c[i + 1] - d[i];

            if ((den = ho - hp) == 0.)
                throw std::string("Poly_interp error");
            den = w / den;
            d[i] = hp * den;
            c[i] = ho * den;
        }
        z += (dy = (2 * (ns + 1) < (m - j) ? c[ns + 1] : d[ns--]));
    }

    return z;
}

Spline_interp::Spline_interp(const Vector<double> &x, const Vector<double> &y, double yp1, double ypn) : Base_interp(x, &y[0], 2), y2(x.size())
{
    sety2(&x[0], &y[0], yp1, ypn);
}

Spline_interp::Spline_interp(const Vector<double> &x, const double *y, double yp1, double ypn) : Base_interp(x, y, 2), y2(x.size())
{
    sety2(&x[0], y, yp1, ypn);
}

void Spline_interp::sety2(const double *x, const double *y, double yp1, double ypn)
{
    double p, qn, sig, un;

    int n1 = y2.size();

    Vector<double> u(n - 1);

    if (yp1 > 0.99e99)
        y2[0] = u[0] = 0.;

    else
    {
        y2[0] = -0.5;
        u[0] = (3. / (x[1] - x[0])) * ((y[1] - y[0]) / (x[1] - x[0]) - yp1);
    }

    for (int i = 0; i < n1 - 1; i++)
    {
        sig = (x[i] - x[i - 1]) / (x[i + 1] - x[i - 1]);
        p = sig * y2[i - 1] + 2.;
        y2[i] = (sig - 1.) / p;
        u[i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]) - (y[i] - y[i - 1]) / (x[i] - x[i - 1]);

        u[i] = (6. * u[i] / (x[i + 1] - x[i - 1]) - sig * u[i - 1]) / p;
    }

    if (ypn > 0.99e99)
        qn = un = 0.;

    else
    {
        qn = 0.5;
        un = (3. / (x[n1 - 1] - x[n1 - 2])) * (ypn - (y[n1 - 1] - y[n1 - 2]) / (x[n1 - 1] - x[n1 - 2]));
    }

    y2[n1 - 1] = (un - qn * u[n - 2]) / (qn * y2[n1 - 2] + 1.);

    for (int k = n1 - 2; k >= 0; k--)
        y2[k] = y2[k] * y2[k + 1] + u[k];
}

double Spline_interp::rawinterp(int jl, double t)
{
    int klo, kl, khi = jl + 1;
    double z, h, b, a;

    h = x[khi] - x[klo];
    if (h == 0.)
        throw std::string("Bad input to routine splint");

    a = (x[khi] - t) / h;
    b = (t - x[klo]) / h;

    z = a * y[klo] + b * y[khi] + ((a * a * a - a) * y2[klo] + (b * b * b - b) * y2[khi]) * (h * h) / 6.;

    return z;
}

Rat_interp::Rat_interp(const Vector<double> &x, const Vector<double> &y, int m) : Base_interp(x, &y[0], m), dy(0.)
{
}

double Rat_interp::rawinter(int jl, double t)
{
    const double epsilon = 1.e-99;
    int ns = 0;
    double z, w, t_, hh, h, dd;
    const double *xa = &x[jl], *ya = &y[jl];
    Vector<double> c(m), d(m);

    hh = abs(t - xa[0]);

    for (int i = 0; i < m; i++)
    {
        h = abs(t - xa[i]);
        if (h == 0.)
        {
            dy = 0.;
            return ya[i];
        }
        else if (h < hh)
        {
            ns = i;
            hh = h;
        }
        c[i] = ya[i];
        d[i] = ya[i] + epsilon;
    }
    z = ya[ns--];
    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < m - j; i++)
        {
            w = c[i + 1] - d[i];
            h = xa[i + m] - t;
            t_ = (xa[i] - t) * d[i] / h;
            dd = t_ - c[i + 1];

            if (dd == 0.)
                throw std::string("Error in routine ratint");
            dd = w / dd;
            d[i] = c[i + 1] * dd;
            c[i] = t * dd;
        }
        z += (dy = (2 * (ns + 1) < (m - j) ? c[ns + 1] : d[ns--]));
    }
    return z;
}

BaryRat_interp::BaryRat_interp(const Vector<double> &x, const Vector<double> &y, int dd) : Base_interp(x, &y[0], x.size()), w(n), d(dd)
{

    if (n <= d)
        throw std::string("d too large for number of points in BaryRat_interp");

    for (int k = 0; k < n; k++)
    {
        int imin = std::max(k - d, 0);
        int imax = k >= n - d ? n - d - 1 : k;

        double temp = imin & 1 ? -1. : 1.;
        double sum = 0.;

        for (int i = imin; i <= imax; i++)
        {
            int jmax = std::min(i + d, n - 1);
            double term = 1.;

            for (int j = i; j < jmax; j++)
            {
                if (j == k)
                    continue;
                term *= (x[k] - x[j]);
            }

            term = temp / term;
            temp = -temp;
            sum += term;
        }
        w[k] = sum;
    }
}

double BaryRat_interp::rawinterp(int jl, double t)
{
    double num = 0, den = 0;

    for (int i = 0; i < n; i++)
    {
        double h = t - x[i];
        if (h == 0.)
            return y[i];

        else
        {
            double temp = w[i] / h;
            num += temp * y[i];
            den += temp;
        }
    }
    return num / den;
}

double BaryRat_interp::interp(double x)
{
    return rawinterp(1, x);
}