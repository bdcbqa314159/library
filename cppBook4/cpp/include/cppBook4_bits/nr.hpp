#ifndef NR_H
#define NR_H

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

template <class T>
inline T sign(const T &a, const T &b)
{
    return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a);
}

template <class T>
class Vector
{

private:
    size_t n;
    T *v;

public:
    Vector();
    Vector(size_t n);
    Vector(size_t n, const T &a);
    Vector(size_t n, const T *a);
    Vector(const Vector &source);
    Vector &operator=(const Vector &rhs);
    T &operator[](size_t i);
    T const &operator[](size_t i) const;
    size_t size() const;
    T *data() const;
    void resize(int n);
    ~Vector();
};

template <class T>
Vector<T>::Vector() : n(0), v(NULL)
{
}

template <class T>
Vector<T>::Vector(size_t n) : n(n), v(n > 0 ? new T[n] : NULL)
{
}

template <class T>
Vector<T>::Vector(size_t n, const T &a) : n(n), v(n > 0 ? new T[n] : NULL)
{

    for (int i = 0; i < n; i++)
        v[i] = a;
}

template <class T>
Vector<T>::Vector(size_t n, const T *a) : n(n), v(n > 0 ? new T[n] : NULL)
{

    for (int i = 0; i < n; i++)
        v[i] = *a++;
}

template <class T>
Vector<T>::Vector(const Vector<T> &rhs) : n(rhs.n), v(n > 0 ? new T[n] : NULL)
{

    for (int i = 0; i < n; i++)
        v[i] = rhs[i];
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &rhs)
{

    if (this != &rhs)
    {
        if (n != rhs.n)
        {
            if (v != NULL)
                delete[](v);
            n = rhs.n;
            v = n > 0 ? new T[n] : NULL;
        }

        for (int i = 0; i < n; i++)
            v[i] = rhs[i];
    }

    return *this;
}

template <class T>
T &Vector<T>::operator[](size_t i)
{

    if (i < 0 || i >= n)
        throw std::string("Vector subscript out of bounds");

    return v[i];
}

template <class T>
T const &Vector<T>::operator[](size_t i) const
{
    if (i < 0 || i >= n)
        throw std::string("Vector subscript out of bounds");

    return v[i];
}

template <class T>
size_t Vector<T>::size() const
{
    return n;
}

template <class T>
T *Vector<T>::data() const
{
    return v;
}

template <class T>
void Vector<T>::resize(int n)
{
    if (this->n != n)
    {
        if (v != NULL)
            delete[](v);
        this->n = n;
        v = n > 0 ? new T[n] : NULL;
    }
}

template <class T>
Vector<T>::~Vector()
{
    if (v != NULL)
        delete[](v);
}

template <class T>
class Matrix
{

private:
    size_t n;
    size_t m;
    T *v;

public:
    Matrix();
    Matrix(size_t n, size_t m);
    Matrix(size_t n, size_t m, const T &a);
    Matrix(size_t n, size_t m, const T *a);
    Matrix(const Matrix &source);
    Matrix &operator=(const Matrix &rhs);
    T &operator()(size_t i, size_t j);
    T const &operator()(size_t i, size_t j) const;
    size_t nrows() const;
    size_t ncols() const;
    T *data() const;
    void resize(int n, int m);

    ~Matrix();
};

template <class T>
Matrix<T>::Matrix() : n(0), m(0), v(NULL)
{
}

template <class T>
Matrix<T>::Matrix(size_t n, size_t m) : n(n), m(m), v(n > 0 ? new T[n * m] : NULL)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[(size_t)(i * m + j)] = 0;
        }
    }
}

template <class T>
Matrix<T>::Matrix(size_t n, size_t m, const T &a) : n(n), m(m), v(n > 0 ? new T[n * m] : NULL)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[(size_t)(i * m + j)] = a;
        }
    }
}

template <class T>
Matrix<T>::Matrix(size_t n, size_t m, const T *a) : n(n), m(m), v(n > 0 ? new T[n * m] : NULL)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[(size_t)(i * m + j)] = *a++;
        }
    }
}

template <class T>
Matrix<T>::Matrix(const Matrix &rhs) : n(rhs.n), m(rhs.m), v(n > 0 ? new T[n * m] : NULL)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[(size_t)(i * m + j)] = rhs(i, j);
        }
    }
}

template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &rhs)
{

    if (this != &rhs)
    {

        if (n != rhs.n || m != rhs.m)
        {
            if (v != NULL)
                delete[](v);

            n = rhs.n;
            m = rhs.m;
            int nel = n * m;

            v = n > 0 ? new T[nel] : NULL;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                v[(size_t)(i * m + j)] = rhs(i, j);
            }
        }
    }
    return *this;
}

template <class T>
T &Matrix<T>::operator()(size_t i, size_t j)
{

    if (i < 0 || i >= n || j < 0 || j >= m)
        throw std::string{"Vector subscript out of bounds"};
    return v[(size_t)(i * m + j)];
}

template <class T>
const T &Matrix<T>::operator()(size_t i, size_t j) const
{

    if (i < 0 || i >= n || j < 0 || j >= m)
        throw std::string{"Vector subscript out of bounds"};
    return v[(size_t)(i * m + j)];
}

template <class T>
size_t Matrix<T>::nrows() const
{
    return n;
}

template <class T>
size_t Matrix<T>::ncols() const
{
    return m;
}

template <class T>
T *Matrix<T>::data() const
{

    return v;
}

template <class T>
void Matrix<T>::resize(int n, int m)
{

    if (this->n != n || this->m != n)
    {
        if (v != NULL)
            delete[](v);
        this->n = n;
        this->m = m;
        v = n > 0 ? new T[n * m] : NULL;
    }
}

template <class T>
Matrix<T>::~Matrix()
{

    if (v != NULL)
        delete[](v);
}

typedef const Vector<int> vecInt_I;
typedef const Vector<unsigned int> vecUint_I;
typedef const Vector<float> vecFlt_I;
typedef const Vector<double> vecDoub_I;

typedef Vector<int> vecInt, vecInt_O, vecInt_IO;
typedef Vector<unsigned int> vecUint, vecUint_O, vecUint_IO;
typedef Vector<float> vecFlt, vecFlt_O, vecFlt_IO;
typedef Vector<double> vecDoub, vecDoub_O, vecDoub_IO;

typedef const Matrix<int> matInt_I;
typedef const Matrix<unsigned int> matUint_I;
typedef const Matrix<float> matFlt_I;
typedef const Matrix<double> matDoub_I;

typedef Matrix<int> matInt, matInt_O, matInt_IO;
typedef Matrix<unsigned int> matUint, matUint_O, matUint_IO;
typedef Matrix<float> matFlt, matFlt_O, matFlt_IO;
typedef Matrix<double> matDoub, matDoub_O, matDoub_IO;

#endif