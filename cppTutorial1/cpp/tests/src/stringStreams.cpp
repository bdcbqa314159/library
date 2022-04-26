#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string name = "Bob";
    int age = 32;
    stringstream ss;

    ss << "Name is: ";
    ss << name;
    ss << ";";
    ss << endl;
    ss << "Age is : ";
    ss << age;

    string info = ss.str();

    cout << info << endl;
    return 0;
}