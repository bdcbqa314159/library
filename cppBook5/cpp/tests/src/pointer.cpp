#include <cppBook5>
#include <iostream>
#include <memory>

using namespace std;

void intro()
{
    double y, z;
    double *p = 0;

    z = 3.;
    p = &z;

    y = *p + 1.;
    cout << z << " " << y << " " << p << endl;
}

void bestPractices()
{
    cout << "Best practices, should read the code." << endl;
    double *p = 0;
    p = new double;
    *p = 1.;

    cout << *p << " at " << p << endl;
    delete p;

    double *q = 0;
    double y = 9.0;
    q = &y;

    cout << "y = " << y << endl;
    *q *= 6.;
    cout << "y = " << y << endl;
}

void vectors()
{
    double *x = 0, *y = 0;
    x = new double[10];
    y = new double[10];

    for (int i = 0; i < 10; i++)
    {
        x[i] = (double)i;
        y[i] = 2 * x[i];
    }

    cout << "===== Display =====" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << x[i] << " -- " << y[i] << endl;
    }

    delete[] x;
    delete[] y;
}

void matrices()
{
    int rows = 5, cols = 3;

    double **A;
    A = new double *[rows];

    for (int i = 0; i < rows; i++)
    {
        A[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            A[i][j] = i + j;
        }
    }
    cout << "===== Display =====" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] A[i];
    }

    delete[] A;
}

/*
TIPS:
double *p = 0;
p = new double[10000];
assert(p != nullptr);
*/

void playingWithPointers()
{
    int a = 8;
    int &b = a;

    cout << a << " " << b << endl;

    int *p = 0;
    p = new int(3);

    int *&q = p;
    cout << q << endl;
    cout << p << endl;
    delete p;
    p = nullptr;
    p = &a;
    cout << p << endl;
    cout << "here" << endl;
    cout << q << endl;
}

void uniquePointer()
{
    unique_ptr<int> p(new int);
    *p = 5;

    // int *q = px; => will crash, instead:
    int *q = p.get();

    unique_ptr<int> w;
    // w = p; => will crash, instead:
    cout << p << endl;
    w = move(p);
    cout << p << endl;
    cout << w << endl;
    cout << q << endl;
}

void sharedPointer()
{
    shared_ptr<int> p(new int);
    cout << p << endl;
    cout << "p user count: " << p.use_count() << endl;
    *p = 5;
    shared_ptr<int> q = p;
    cout << "p user count: " << p.use_count() << endl;
    q.reset();
    cout << p << endl;
    cout << "p user count: " << p.use_count() << endl;
    *p = 9;
    cout << p << endl;
    cout << "p user count: " << p.use_count() << endl;
    p.reset();
    cout << p << endl;
    cout << "p user count: " << p.use_count() << endl;
}

void exercise1()
{
    int i = 5;
    int *p_j = &i;

    cout << "Before i = " << i << endl;
    *p_j *= 5;
    cout << "After modifying via i's address: " << i << endl;

    int *p_k = new int;
    p_k = &i;
    *p_j = 0;

    cout << i << " -- " << *p_j << " -- " << *p_k << endl;
    // delete p_k;
    p_k = nullptr;

    int *z = new int(5);
    delete z;
}

void exercise2()
{
    int i = 10, j = 11;
    int *p = &i, *q = &j;

    cout << "Before: " << i << " - " << j << endl;
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;

    cout << "After: " << i << " - " << j << endl;
}

double helper()
{
    double *x = new double[3];
    double *y = new double[3];

    for (int i = 0; i < 3; i++)
    {
        x[i] = 3. * i;
        y[i] = 2. * i;
    }

    double answer = 0.;
    for (int i = 0; i < 3; i++)
        answer += x[i] * y[i];

    delete[] x;
    delete[] y;

    return answer;
}

void exercise3()
{
    for (int i = 0; i < 1000000; i++)
    {
        cout << "for i = " << i << " result = " << helper() << endl;
    }
}

void helper1()
{
    double **A = new double *[2];
    double **B = new double *[2];
    double **C = new double *[2];

    for (int i = 0; i < 2; i++)
    {
        A[i] = new double[2];
        B[i] = new double[2];
        C[i] = new double[2];
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            A[i][j] = i + j;
            B[i][j] = i - j;

            C[i][j] = A[i][j] + B[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {

            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
}

void exercise4()
{
    for (int i = 0; i < 1000000; i++)
    {
        cout << "for i = " << i << " result : " << endl;
        helper1();
    }
}

void weakPointer()
{
    shared_ptr<int> p(new int);
    cout << "p user count: " << p.use_count() << endl;
    *p = 5;

    shared_ptr<int> q = p;
    weak_ptr<int> w = p;
    cout << "p user count: " << p.use_count() << endl;
    q.reset();
    cout << "p user count: " << p.use_count() << endl;
    cout << *w.lock() << endl;
    p.reset();
    cout << "p user count: " << p.use_count() << endl;

    // cout << *w.lock() << endl; ERROR
}

int main()
{
    exercise1();
    exercise2();
    // exercise3();
    // exercise4();
    weakPointer();

    return 0;
}
