#include <cppTutorial1>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Working with templates & classes" << endl;
    TestTemplate<string> test1("Hello");
    test1.print();

    cout << "Working with templates & functions" << endl;
    myPrintTemplate<string>("Hello");
    myPrintTemplate<double>(3.75943);

    cout << "Testing some behaviours" << endl;
    myPrintTemplate<>(4);
    myPrintTemplate(31);
    myPrintTemplate<string>("Buddy");

    return 0;
}