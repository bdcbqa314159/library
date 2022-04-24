#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Working with strings." << endl;
    string s1 = "Hello ";
    string s2 = "Fred";

    cout << s1 << s2 << endl;
    string s3 = s1 + s2;
    cout << "Concatenating: " << s3 << endl;

    return 0;
}