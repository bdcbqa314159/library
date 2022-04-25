#include <iostream>
#include <string>

using namespace std;
int main()
{
    int value = 7;

    do
    {

        cout << "Hello & value = " << value << endl;
        value++;

    } while (value < 19);

    const string password = "hello";

    string input;

    do
    {
        cout << "Enter your password > " << flush;

        getline(cin, input);

        if (input != password)

            cout << "Access denied" << endl;

    } while (input != password);

    cout << "Password accepted" << endl;

    return 0;
}