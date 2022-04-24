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

    if (value < 3)
    {
        cout << "Insufficient privileges to use these menu option." << endl;
    }
    else
    {
        cout << "You have the right to view / search the record or quit." << endl;
    }

    if (value == 5)
    {
        cout << "Quitting..." << endl;
    }
    else
    {
        cout << "Not quitting" << endl;
    }

    return 0;
}