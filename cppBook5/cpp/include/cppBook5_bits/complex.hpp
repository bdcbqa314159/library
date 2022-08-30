#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>
using namespace std;

class ComplexNumber
{

    double mRe, mIm;

public:
    ComplexNumber();
    ComplexNumber(double x, double y);
    ComplexNumber(const ComplexNumber &rhs);
    ~ComplexNumber();
    double calculateModulus() const;
    double calculateArgument() const;
    ComplexNumber calculatePower(double n) const;

    ComplexNumber &operator=(const ComplexNumber &z);
    ComplexNumber operator-() const;
    ComplexNumber operator+(const ComplexNumber &z) const;
    ComplexNumber operator-(const ComplexNumber &z) const;
    friend ostream &operator<<(ostream &os, const ComplexNumber &z);
};

#endif