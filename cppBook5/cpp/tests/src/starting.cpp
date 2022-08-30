#include <cppBook5>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

void program()
{
    cout << "Hello World!" << endl;
    return;
}

void ring()
{
    cout << "\a" << endl;
}

void testing()
{
    double a{};
    cout << "Enter a non-negative number?" << endl;
    cin >> a;
    assert(a >= 0.);
    cout << "The square root of " << a << endl;
    cout << sqrt(a) << endl;
    /*
    Others examples: isfinite(a), isinf(a), isnan(a);
    */
}

void twoNumbers()
{
    int a, b;
    a = b = 0;

    cout << "Give 2 integers:" << endl;
    cout << "a >>> ";
    cin >> a;
    cout << "b >>> ";
    cin >> b;
    cout << a << "*" << b << " = " << a * b << endl;
}

double dot(vector<double> &a, vector<double> &b)
{
    int n = a.size(), m = b.size();
    double out = 0;
    if (n != m)
        throw string("vectors must have same length");
    else
    {
        for (int i = 0; i < n; i++)
            out += a[i] * b[i];
    }
    return out;
}

double norm2(vector<double> &a)
{
    int n = a.size();
    double out = 0;
    if (n == 0)
        throw string("vector needs to have at least one dimension");
    else
    {
        for (int i = 0; i < n; i++)
            out += a[i] * a[i];
    }
    return sqrt(out);
}

template <typename T>
void filling(vector<T> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cout << "at index " << i << " : ";
        cin >> a[i];
    }
    return;
}

void vectors()
{
    cout << "Give 3 coordinates for vectors u and v." << endl;
    vector<double> u(3), v(3);
    cout << "vector u:" << endl;
    filling<double>(u);
    cout << "vector v:" << endl;
    filling<double>(v);

    try
    {
        double dotProduct = dot(u, v);
        cout << "u.v = " << dotProduct << endl;
        double norm2Result1 = norm2(u), norm2Result2 = norm2(v);

        cout << "Norm2(u) = " << norm2Result1 << endl;
        cout << "Norm2(v) = " << norm2Result2 << endl;
    }
    catch (string &e)
    {
        cerr << e << endl;
    }
}

void filling2D(vector<vector<double>> &Mat)
{
    int n = Mat.size(), m = Mat[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << " at " << i << " " << j << " : ";
            cin >> Mat[i][j];
        }
    }
    return;
}

vector<vector<double>> sumMatrices(vector<vector<double>> &A, vector<vector<double>> &B)
{
    int n = A.size(), m = A[0].size();
    int p = B.size(), q = B[0].size();

    vector<vector<double>> C;

    if (n != p || m != q)
        throw string("matrices must have exactly same dimensions");
    else
    {
        C.resize(n);
        for (int i = 0; i < n; i++)
        {
            C[i].resize(m);
            for (int j = 0; j < m; j++)
            {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }
    return C;
}

vector<vector<double>> prodMatrices(vector<vector<double>> &A, vector<vector<double>> &B)
{
    int n = A.size(), m = A[0].size();
    int p = B.size(), q = B[0].size();

    vector<vector<double>> C;

    if (m != p)
        throw string("number of columns must be equal to number of lines");
    else
    {
        C.resize(n);
        for (int i = 0; i < n; i++)
        {
            C[i].resize(m);
            for (int j = 0; j < m; j++)
            {
                double prod = 0.;
                for (int k = 0; k < m; k++)
                {
                    prod += A[i][k] * B[k][j];
                }
                C[i][j] = prod;
            }
        }
    }
    return C;
}

void showMatrix(vector<vector<double>> &a)
{
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void matrices()
{
    vector<vector<double>> A(3, vector<double>(3, 0.)), B(3, vector<double>(3, 0.));
    cout << "Give data for A" << endl;
    filling2D(A);

    cout << "Give data for B" << endl;
    filling2D(B);

    cout << "A" << endl;
    showMatrix(A);
    cout << endl;
    cout << "B" << endl;
    showMatrix(B);
    cout << endl;

    vector<vector<double>> C = sumMatrices(A, B);

    cout << "C = A+B" << endl;
    showMatrix(C);
    cout << endl;
    vector<vector<double>> D = prodMatrices(A, B);

    cout << "D = A*B" << endl;
    showMatrix(D);
    cout << endl;
}

void namingUser()
{
    string name, surname;
    cout << "Please give me your name ";
    getline(cin, name);
    cout << "Many thanks " << name << ", now give me your surname ";
    getline(cin, surname);
    cout << "Great! Hello " << name + " " << surname << endl;
}

double myMean(vector<int> &cars)
{
    int n = cars.size();
    int sum = 0;
    for (int x : cars)
        sum += x;

    return (1. * sum) / n;
}

void carsInterface()
{
    vector<int> cars(5);
    cout << "please give the cars data: " << endl;
    filling<int>(cars);
    double mean = myMean(cars);
    cout << "The mean is " << mean << endl;
}

int main()
{

    cout << "Chapter 1 notes." << endl;

    // Execution of the first program
    // program();
    // // ring();
    // testing();
    // cout << "Message!" << endl;
    // cout.flush();

    // cout << "Exercices:" << endl;
    // cout << "1. Easy to do, my setup compiles properly." << endl;
    // cout << "2. calling twoNumbers" << endl;
    // twoNumbers();

    // cout << "3. calling vectors" << endl;
    // vectors();

    // matrices();
    // namingUser();
    carsInterface();
    cout << "6. Compiler warning works more than ok here." << endl;

    return 0;
}
