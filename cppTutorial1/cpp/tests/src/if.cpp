#include <iostream>
#include <string>

using namespace std;

int main()
{

    string password{"hello"};
    cout << "Enter your password > " << flush;
    string input;
    getline(cin, input);
    // cout << "input: " << input << endl;
    // cout << "password: " << password << endl;

    if (password == input)
        cout << "The password is correct" << endl;
    // else
    if (password != input)
        cout << "Sorry this is not the correct password." << endl;

    return 0;
}