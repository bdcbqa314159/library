#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Working with the input from the user." << endl;

    cout << "Enter your name >> " << flush;
    string input;
    getline(cin, input);
    cout << "you entered: " << input << endl;

    int value;
    cout << "Enter a number>> " << flush;
    cin >> value;
    cout << "You entered: " << value << endl;

    return 0;
}