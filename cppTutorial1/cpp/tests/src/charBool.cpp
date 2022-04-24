#include <iostream>
#include <iomanip>

using namespace std;
int main()
{

    bool bvalue = true;

    cout << bvalue << endl;
    cout << boolalpha << bvalue << endl;

    char cvalue = 55;
    int value = 55;
    cout << "Char value for " << value << " is : " << cvalue << endl;
    cout << "Size of char : " << sizeof(char) << " bytes." << endl;

    wchar_t wvalue = 'i';
    cout << (char)wvalue << " is : " << wvalue << endl;
    cout << "Size of wchar_t is " << sizeof(wchar_t) << " bytes." << endl;

    return 0;
}