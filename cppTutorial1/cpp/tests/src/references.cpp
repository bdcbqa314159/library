#include <iostream>
#include <string>

using namespace std;

void changeto10(double a)
{
    a = 10;
}

void changeto10v2(double &a)
{
    a = 10;
}

int main()
{
    int a = 0;
    int b = a;
    b = 10;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    int &c = a;
    c = 10;

    cout << "a = " << a << endl;
    cout << "c = " << c << endl;

    double x = 9012.231;
    cout << "x = " << x << endl;
    changeto10(x);
    cout << "after function: " << endl;
    cout << "x = " << x << endl;
    cout << "If we work by reference: " << endl;
    cout << "x = " << x << endl;
    changeto10v2(x);
    cout << "after function: " << endl;
    cout << "x = " << x << endl;

    return 0;
}