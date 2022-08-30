#include <cppBook5>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

double helper(double x, double y)
{
    if (x > y || x < 5.)
        return 4.;
    else
        return 2.;
}

void exercise1()
{
    cout << "x = 10. && y = -1." << endl;
    cout << helper(10., -1.) << endl;

    cout << "x = 10. && y = 20." << endl;
    cout << helper(10., 20.) << endl;

    cout << "x = 0. && y = 20." << endl;
    cout << helper(0., 20.) << endl;
}

int f(int p, int q, int j)
{
    if (p >= q || j != 10)
        return 5;
    else
        throw string("Not defined by the function");
}

int g(int p, int q, int j)
{
    if (p >= q || j == 20)
        return 5;
    else
        return p;
}

int h(int p, int q, int j)
{
    if (p > q)
        return 0;
    else if (j == 10)
        return 1;
    else
        return 2;
}

int mySum()
{
    int answer = 0;
    int input = 0;
    while (true)
    {
        cout << "Enter an integer (-1 to kill the process) ";
        cin >> input;
        if (input == -1)
            break;
        answer += input;
        if (answer > 100)
            break;
        if (input == -2)
            answer = 0;
    }
    return answer;
}

void interfaceSum()
{
    int a = mySum();

    cout << "The result is " << a << endl;
}

vector<double> diff(vector<double> &a, vector<double> &b)
{
    int n = a.size();
    vector<double> c(n);
    for (int i = 0; i < n; i++)
        c[i] = a[i] - b[i];

    return c;
}

vector<double> product(vector<vector<double>> &A, vector<double> &u)
{
    int n = u.size();
    vector<double> v(n);
    for (int i = 0; i < n; i++)
    {
        double temp = 0.;
        for (int j = 0; j < n; j++)
        {
            temp += A[i][j] * u[j];
        }
        v[i] = temp;
    }
    return v;
}

vector<vector<double>> product(vector<vector<double>> &A, vector<vector<double>> &B)
{
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double temp = 0.;
            for (int k = 0; k < n; k++)
            {
                temp += A[i][k] * B[k][j];
            }
            C[i][j] = temp;
        }
    }
    return C;
}

vector<vector<double>> diff(vector<vector<double>> &A, vector<vector<double>> &B)
{
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

vector<vector<double>> product(vector<vector<double>> &A, double k)
{
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = k * A[i][j];
        }
    }
    return C;
}

void show(vector<vector<double>> &X)
{
    int n = X.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << X[i][j] << " ";
        }
        cout << endl;
    }
}

void show(vector<double> &x)
{
    for (double y : x)
        cout << y << endl;
}

void interfaceExercise4()
{
    vector<double> u = {1., 2., 3}, v = {6., 5., 4.};
    vector<double> w(3);
    for (int i = 0; i < 3; i++)
        w[i] = u[i] - 3 * v[i];

    vector<vector<double>> A = {{1., 5., 0.}, {7., 1., 2.}, {0., 0., 1.}};
    vector<vector<double>> B = {{-2., 0., 1.}, {1., 0., 0.}, {4., 1., 0.}};

    vector<double> x = diff(u, v);
    show(x);
    cout << endl;

    vector<double> y = product(A, u);
    show(y);
    cout << endl;

    vector<double> z = diff(y, v);
    show(z);
    cout << endl;

    vector<vector<double>> D = product(A, B);
    show(D);
    cout << endl;

    vector<vector<double>> E = product(A, 3.);
    vector<vector<double>> F = product(B, 3.);
    vector<vector<double>> C = diff(E, F);

    show(C);
    cout << endl;
}

vector<vector<double>> invDim2(vector<vector<double>> &M)
{
    vector<vector<double>> X(2, vector<double>(2));
    double a = M[0][0], b = M[0][1], c = M[1][0], d = M[1][1];

    double m = (a * d - b * c);
    assert(m != 0);
    X[0][0] = d, X[0][1] = -b, X[1][0] = -c, X[1][1] = a;
    vector<vector<double>> A = product(X, 1 / m);
    return A;
}

void interfaceExercise5()
{
    vector<vector<double>> A = {{4, 10}, {1, 1}};
    vector<vector<double>> X = invDim2(A);
    vector<vector<double>> C = product(A, X);

    show(C);
}

class myFunction
{
public:
    virtual double operator()(double x) = 0;
    virtual double df(double x) = 0;

    virtual ~myFunction()
    {
    }
};

class foo : public myFunction
{

public:
    double operator()(double x) override
    {
        return exp(x) + x * x * x - 5;
    }

    double df(double x) override
    {
        return exp(x) + 2 * x * x;
    }
};

void NewtonRaphson_v1()
{
    double x_prev = 0., x_next = 0.;
    foo f;
    cout << "Initial x  = " << x_prev << endl;
    int i = 0;
    for (; i < 100; i++)
    {
        x_next = x_prev - f(x_prev) / f.df(x_prev);
        if (fabs(x_next - x_prev) <= 1e-8)
            break;
        x_prev = x_next;
    }
    cout << "with for Final x = " << x_next << " i= " << i << endl;
}

void NewtonRaphson_v2()
{
    double x_prev = 0., x_next = 1.;
    foo f;
    cout << "Initial x  = " << x_prev << endl;
    double delta = fabs(x_prev - x_next);
    while (delta >= 1.e-8)
    {
        x_next = x_prev - f(x_prev) / f.df(x_prev);
        delta = fabs(x_prev - x_next);
        cout << x_prev << " " << x_next << endl;
        x_prev = x_next;
    }

    cout << "with while Final x = " << x_next << endl;
}

int main()
{
    cout << "Notes on flow control" << endl;
    // exercise1();
    // interfaceSum();
    // interfaceExercise4();
    // interfaceExercise5();
    NewtonRaphson_v1();
    NewtonRaphson_v2();
    return 0;
}