#ifndef MYVECTOR_H
#define MYVECTOR_H

using namespace std;

class myVector
{
    double *mData;
    int mSize;

public:
    myVector();
    myVector(const myVector &rhs);
    myVector(int size);

    ~myVector();

    int getSize() const;

    double &operator[](int i);
    double read(int i) const;
    double &operator()(int i);

    myVector &operator=(const myVector &rhs);
    myVector operator+() const;
    myVector operator-() const;
    myVector operator+(const myVector &v1) const;
    myVector operator-(const myVector &v1) const;

    myVector operator*(double a) const;
    double calculateNorm(int p = 2) const;
    friend int length(const myVector &v);
};

int length(const myVector &v);

#endif