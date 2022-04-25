#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    cout << "Working with break keyword." << endl;
    int check{};
    for (int i = 0; i < 5; i++)
    {
        cout << "i is: " << i << endl;
        if (i == 3)
        {
            check = i;
            break;
        }
    }

    cout << "Checking break : check = " << check << endl;

    cout << "Working with continue keyword." << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "i is: " << i << endl;
        if (i == 3)
        {
            cout << "continue here..." << endl;
            continue;
        }
        cout << "I said i is: " << i << endl;
    }

    const string password = "hello";

    string input;

    do
    {
        cout << "Enter your password > " << flush;

        getline(cin, input);

        if (input == password)
            break;
        else
            cout << "Access denied" << endl;

    } while (true);

    cout << "Password accepted" << endl;

    return 0;
}