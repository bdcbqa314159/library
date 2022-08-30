#include <cppBook5>
#include <iostream>
#include <cmath>

using namespace std;

double **allocationMatrix(int rows, int cols)
{
    double **matrix;

    matrix = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols];
    }

    return matrix;
}

void freeEspace(int rows, double **A)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}

void interface1()
{
    double **M;
    M = allocationMatrix(2, 2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            M[i][j] = i * j;
        }
    }

    cout << "===== Display =====" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    freeEspace(2, M);
}

void calculateRealAndImaginary(double r, double theta, double *pR, double *pI)
{
    *pR = r * cos(theta);
    *pI = r * sin(theta);
}

void interface2()
{
    double r = 3.4;
    double theta = 1.23;

    double x, y;
    calculateRealAndImaginary(r, theta, &x, &y);
    cout << "re = " << x << " -- im = " << y << endl;
}

void doSomething(double u[], double A[][10], double B[10][10])
{
    u[2] = 1.;
    A[2][3] = 4.;
    B[3][3] = 3.5;
}

void interface3()
{
    double u[5], A[10][10], B[10][10];
    doSomething(u, A, B);
    cout << u[2] << endl;
    cout << A[2][3] << endl;
    cout << B[3][3] << endl;
}

void doSomething(double *u, double **A)
{
    u[2] = 1.;
    A[2][3] = 4.;
}

void interface4()
{
    double *u = new double[10];
    double **A = allocationMatrix(10, 10);

    doSomething(u, A);
    cout << u[2] << endl;
    cout << A[2][3] << endl;

    delete[] u;
    freeEspace(10, A);
}

void calculateCubeRoot(double &x, double K, double tol = 1.e-6, int maxIter = 100)
{
    int iter = 0;
    double res = x * x * x - K;

    while ((fabs(res) > tol) && (iter < maxIter))
    {
        x = x - (x * x * x - K) / (3. * x * x);
        res = x * x * x - K;
        iter++;
    }
}

void interface5()
{
    double x = 1.;
    double K = 12.;

    calculateCubeRoot(x, K);
    cout << x << endl;

    x = 1.;
    calculateCubeRoot(x, K, 0.001);
    cout << x << endl;

    x = 1.;
    calculateCubeRoot(x, K, 0.001, 50);
    cout << x << endl;
}

void multiply(double lambda, double *u, double *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = lambda * u[i];
    }
}

void multiply(double lambda, double **A, double **B, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[i][j] = lambda * A[i][j];
        }
    }
}

void interface6()
{
    int n = 2;
    double *u = new double[n];
    double *v = new double[n];
    u[0] = -8.7, u[1] = 3.2;

    double s = 2.3, t = 4.8;
    multiply(s, u, v, n);
    cout << endl;
    cout << "u and v: " << endl;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << u[i] << " -- " << v[i] << endl;
    }

    double **A = allocationMatrix(2, 2);
    double **B = allocationMatrix(2, 2);

    A[0][0] = 2.3;
    A[0][1] = -7.6;
    A[1][0] = 1.3;
    A[1][1] = 45.3;

    multiply(t, A, B, n);
    cout << endl;
    cout << "A matrix:" << endl;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "B matrix:" << endl;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    freeEspace(n, A);
    freeEspace(n, B);

    delete[] u;
    delete[] v;
}

double f1(double x);
double f2(double x);

void interface7();

void solveNewton(double (*f)(double), double (*df)(double), double &x);

double sqrt10(double x);

double sqrt10Prime(double x);

double cube10(double x);

double cube10Prime(double x);

void interface8();

long int factorial(int n);

void interface9();

int main()
{

    // interface1();
    // interface2();
    // interface3();
    // interface4();
    // interface5();
    // interface6();
    interface7();
    interface8();
    interface9();

    return 0;
}

double f1(double x)
{
    return x * x;
}

double f2(double x)
{
    return x * x * x;
}

void interface7()
{
    double (*p)(double x);

    p = &f1;
    cout << "f1:" << endl;
    cout << p(2.) << endl;

    cout << endl;

    p = &f2;

    cout << "f2:" << endl;
    cout << p(2.) << endl;
}

void solveNewton(double (*f)(double x), double (*df)(double x), double &x)
{
    double step = 0;

    do
    {
        step = (*f)(x) / (*df)(x);
        x -= step;
    } while (fabs(step) > 1.e-5);
}

double sqrt10(double x)
{
    return sqrt(x) - 10.;
}

double sqrt10Prime(double x)
{
    return 1. / (2. * sqrt(x));
}

double cube10(double x)
{
    return x * x * x - 10.;
}

double cube10Prime(double x)
{
    return 3. * x * x;
}

void interface8()
{
    cout << "root of sqrt(x) = 10 with guess 1. is" << endl;
    double x = 1.;
    solveNewton(sqrt10, sqrt10Prime, x);
    cout << x << endl;

    cout << "root of x^3 = 10 with guess 1. is" << endl;
    x = 1.;
    solveNewton(cube10, cube10Prime, x);
    cout << x << endl;
}

long int factorial(int n)
{
    assert(n >= 0);
    if (n <= 1)
        return n;
    else
        return n * factorial(n - 1);
}

void interface9()
{
    int n = 7;
    cout << "7! = " << factorial(7) << endl;
}