#include <cppDSA>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    srand(static_cast<unsigned int>(time(0)));

    int computerNumber = GenerateRandomNumber(1, 100);

    int userNumber;
    cout << "Please enter a number between 1 to 100: ";
    cin >> userNumber;

    while (userNumber != computerNumber)
    {
        cout << userNumber << " is ";
        if (userNumber > computerNumber)
            cout << "greater";
        else
            cout << "lower";
        cout << " than computer's number" << endl;
        cin >> userNumber;
    }

    cout << "Yeah! You've got the number." << endl;

    return 0;
}