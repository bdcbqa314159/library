#include <cmath>
#include <iostream>
#include <cassert>
#include "../include/cppBook5_bits/myVector.hpp"

myVector::myVector() : mSize(0), mData(nullptr)
{
}

myVector::myVector(const myVector &rhs)
{
    mSize = rhs.getSize();
    mData = new double[mSize];

    for (int i = 0; mSize; i++)
    {
        mData[i] = rhs.mData[i];
    }
}

myVector::myVector(int size)
{
    assert(size > 0);
    mSize = size;
    mData = new double[mSize];

    for (int i = 0; i < mSize; i++)
    {
        mData[i] = 0.;
    }
}

myVector::~myVector()
{
    delete[] mData;
}

int myVector::getSize() const
{
    return mSize;
}

double &myVector::operator[](int i)
{
    assert(i > -1);
    assert(i < mSize);
    return mData[i];
}

double myVector::read(int i) const
{
    assert(i > -1);
    assert(i < mSize);
    return mData[i];
}

double &myVector::operator()(int i)
{
    assert(i > 0);
    assert(i < mSize + 1);
    return mData[i - 1];
}

myVector &myVector::operator=(const myVector &rhs)
{
    assert(mSize == rhs.mSize);
    for (int i = 0; i < mSize; i++)
    {
        mData[i] = rhs.mData[i];
    }
    return *this;
}

myVector myVector::operator+() const
{
    myVector v(mSize);
    for (int i = 0; i < mSize; i++)
    {
        v[i] = mData[i];
    }
    return v;
}

myVector myVector::operator-() const
{
    myVector v(mSize);
    for (int i = 0; i < mSize; i++)
    {
        v[i] = -mData[i];
    }
    return v;
}

myVector myVector::operator+(const myVector &v1) const
{
    assert(mSize == v1.mSize);
    myVector v(mSize);

    for (int i = 0; i < mSize; i++)
    {
        v[i] = mData[i] + v1.mData[i];
    }

    return v;
}

myVector myVector::operator-(const myVector &v1) const
{
    assert(mSize == v1.mSize);
    myVector v(mSize);

    for (int i = 0; i < mSize; i++)
    {
        v[i] = mData[i] - v1.mData[i];
    }

    return v;
}

myVector myVector::operator*(double a) const
{
    myVector v(mSize);

    for (int i = 0; i < mSize; i++)
    {
        v[i] = a * mData[i];
    }

    return v;
}

double myVector::calculateNorm(int p = 2) const
{
    double norm_val, sum = 0.;
    for (int i = 0; i < mSize; i++)
    {
        sum += pow(fabs(mData[i]), p);
    }

    norm_val = pow(sum, 1. / p);
    return norm_val;
}

int length(const myVector &v)
{
    return v.mSize;
}