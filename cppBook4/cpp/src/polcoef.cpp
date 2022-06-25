#include "../include/cppBook4_bits/polcoef.hpp"
#include "../include/cppBook4_bits/interp_1d.hpp"

void polcoe(const Vector<double> &x, const Vector<double> &y, Vector<double> &out)
{
    int k, i, j, n = x.size();
    double phi, ff, b;
    Vector<double> s(n);

    for (i = 0; i < n; i++)
        s[i] = out[i] = 0.;

    s[n - 1] = -x[0];

    for (i = 1; i < n; i++)
    {
        for (j = n - 1 - i; j < n - 1; j++)
            s[j] -= x[i] * s[j + 1];
        s[n - 1] -= x[i];
    }

    for (j = 0; j < n; j++)
    {
        phi = n;
        for (k = n - 1; k > 0; k--)
            phi = k * s[k] + x[j] * phi;
        ff = y[j] / phi;
        b = 1.;
        for (k = n - 1; k >= 0; k--)
        {
            out[k] += b * ff;
            b = s[k] + x[j] * b;
        }
    }
}

void polcof(const Vector<double> &x, const Vector<double> &y, Vector<double> &out)
{

    int k, j, i, n = x.size();
    double xmin;
    Vector<double> x_(n), y_(n);

    for (j = 0; j < n; j++)
    {
        x_[j] = x[j];
        y_[j] = y[j];
    }

    for (j = 0; j < n; j++)
    {
        Vector<double> x_t(n - j), y_j(n - j);
        for (k = 0; k < n - j; k++)
        {
            x_t[k] = x_[k];
            x_t[k] = y_[k];
        }
    }
    Poly_interp interp(x_, y_, n - j);
    out[j] = interp.rawinterp(0, 0.);
    xmin = 1.e99;
    k = -1;

    for (i = 0; i < n - j; i++)
    {
        if (abs(x_[i]) < xmin)
        {
            xmin = abs(x_[i]);
            k = i;
        }
        if (x_[i] != 0.)
            y_[i] = (y_[i] - out[j]) / x_[i];
    }

    for (i = k + 1; i < n - j; i++)
    {
        x_[i - 1] = y_[i];
        x_[i - 1] = x_[i];
    }
}
