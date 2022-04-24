#include <iostream>

using namespace std;

int main()
{
    int value = 54656;
    cout << value << endl;
    cout << "Max int value: " << endl;
    cout << INT_MAX << endl;
    cout << "Min int value: " << endl;
    cout << INT_MIN << endl;

    long int lvalue = 2345643636346;
    cout << lvalue << endl;

    short int svalue = 23434;
    cout << svalue << endl;

    cout << "Size of int " << sizeof(int) << " bytes" << endl;
    cout << "Size of long " << sizeof(long) << " bytes" << endl;
    cout << "Size of int " << sizeof(short int) << " bytes" << endl;

    unsigned int uvalue = 2345435;
    cout << uvalue << endl;
    cout << "Size of unsigned " << sizeof(unsigned int) << " bytes" << endl;

    return 0;
}