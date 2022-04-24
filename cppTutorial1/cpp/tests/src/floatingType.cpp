#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    float fvalue = 76.4;
    cout << "Normal notation: " << fvalue << endl;
    cout << fixed << fvalue << endl;
    cout << scientific << fvalue << endl;
    cout << "Size of float : " << sizeof(float) << " bytes" << endl;
    cout << setprecision(20) << fixed << fvalue << endl;

    double dvalue = 76.4;
    cout << "Normal notation: " << fvalue << endl;
    cout << fixed << dvalue << endl;
    cout << scientific << dvalue << endl;
    cout << "Size of double : " << sizeof(double) << " bytes" << endl;
    cout << setprecision(20) << fixed << dvalue << endl;

    long double lvalue = 123.3483249797593287;
    cout << setprecision(20) << fixed << lvalue << endl;
    cout << "Size of long double : " << sizeof(long double) << " bytes" << endl;

    return 0;
}