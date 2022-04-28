#include <iostream>
#include <string>

using namespace std;

void manipulate(int value);
void realManipulate(int *value);
void pointersBasics()
{

    cout << "Some basic stuff with pointers" << endl;

    int n = 0;
    int *p = nullptr;

    cout << n << endl;
    cout << p << endl;

    cout << "Give a number for n: >>";
    cin >> n;

    cout << "This is n: " << n << endl;
    cout << "This is the address of n: " << &n << endl;

    p = &n;
    cout << "Value for the pointer: " << endl;
    cout << p << endl;
    cout << "And the value: " << endl;
    cout << *p << endl;
    cout << "Modification of n by address:" << endl;
    *p = 56;
    cout << "Value n: " << n << endl;
    cout << "Address n: " << &n << endl;
    cout << "Pointer p: " << p << endl;
    cout << "Value of *p: " << *p << endl;
    n = 10;
    cout << "Value n: " << n << endl;
    cout << "Address n: " << &n << endl;
    cout << "Pointer p: " << p << endl;
    cout << "Value of *p: " << *p << endl;

    cout << "=============" << endl;
    cout << "Shallow copy: " << endl;
    int Val = 90;
    cout << "Val: " << Val << endl;
    manipulate(Val);
    cout << "Val: " << Val << endl;
    cout << "Deep copy with addresses: " << endl;
    cout << "Val: " << Val << endl;
    realManipulate(&Val);
    cout << "ValAfter: " << Val << endl;
}

int main()
{
    pointersBasics();

        return 0;
}

void manipulate(int value)
{
    cout << "Value: " << value << endl;
    value = 10;
    cout << "Value : " << value << endl;
}

void realManipulate(int *value)
{
    *value = 60;
}