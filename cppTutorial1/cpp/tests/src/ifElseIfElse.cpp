#include <iostream>

using namespace std;

int main()
{
    cout << "1.\t Add new record." << endl;
    cout << "2.\t Delete record." << endl;
    cout << "3.\t View record." << endl;
    cout << "4.\t Search record." << endl;
    cout << "5.\t Quit." << endl;

    cout << "Enter your selection > " << flush;
    int value;
    cin >> value;

    if (value == 1)
    {
        cout << "Adding a new record" << endl;
    }
    else if (value == 2)
    {
        cout << "Deleting record" << endl;
    }

    else if (value == 3)
    {
        cout << "Viewing record" << endl;
    }

    else if (value == 4)
    {
        cout << "Searching record" << endl;
    }

    else if (value == 5)
    {
        cout << "Quitting..." << endl;
    }

    else
    {
        cout << "Invalid option." << endl;
    }

    return 0;
}