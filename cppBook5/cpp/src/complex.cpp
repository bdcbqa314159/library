#include "../include/cppBook5_bits/complex.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

ComplexNumber::ComplexNumber() : mRe(0), mIm(0)
{
}

ComplexNumber::ComplexNumber(double x, double y) : mRe(x), mIm(y)
{
}

ComplexNumber::ComplexNumber(const ComplexNumber &rhs) : mRe(rhs.mRe), mIm(rhs.mIm)
{
}

ComplexNumber::~ComplexNumber()
{
}

double ComplexNumber::calculateModulus() const
{
    return sqrt(mRe * mRe + mIm * mIm);
}

double ComplexNumber::calculateArgument() const
{
    return atan2(mIm, mRe);
}

ComplexNumber ComplexNumber::calculatePower(double n) const
{
    double modulus = calculateModulus();
    double arg = calculateArgument();
    double modRes = pow(modulus, n);
    double argRes = pow(arg, n);

    double re = modRes * cos(argRes);
    double im = modRes * sin(argRes);

    ComplexNumber z(re, im);

    return z;
}

ComplexNumber &ComplexNumber::operator=(const ComplexNumber &z)
{
    mRe = z.mRe;
    mIm = z.mIm;
    return *this;
}

ComplexNumber ComplexNumber::operator-() const
{
    ComplexNumber w(-mRe, -mIm);
    return w;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &z) const
{
    ComplexNumber w(mRe + z.mRe, mIm + z.mIm);
    return w;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &z) const
{
    ComplexNumber w(mRe - z.mRe, mIm - z.mIm);
    return w;
}

ostream &operator<<(ostream &os, const ComplexNumber &z)
{
    os << z.mRe << " ";

    if (z.mIm >= 0.)
        os << " + " << z.mIm << "i";
    else
        os << " - " << -z.mIm << "i";
    return os;
}
