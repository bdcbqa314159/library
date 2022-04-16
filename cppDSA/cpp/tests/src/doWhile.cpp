#include <cppDSA>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    srand(static_cast<unsigned int>(time(0)));
    char userChar;

    int iMin = 1, iMax = 100;
    int iGuess;

    cout << "Choose a number between 1 to 100, ";
    cout << "and I'll guess your number." << endl;
    cout << "Press L and ENTER if my guessed number is lower than yours.";
    cout << endl;
    cout << "Press G and ENTER if my guessed number is greater than yours.";
    cout << endl;

    cout << "Press Y and ENTER if I've successfully guessed your number!";
    cout << endl
         << endl;

    do
    {
        iGuess = GenerateRandomNumber(iMin, iMax);
        cout << "I guess your number is " << iGuess << endl;
        cout << "What do you think? ";
        cin >> userChar;
        if (userChar == 'L' || userChar == 'l')
            iMin = iGuess + 1;
        else if (userChar == 'G' || userChar == 'g')
            iMax = iGuess - 1;
    } while (userChar != 'Y' && userChar != 'y');
    cout << "Yeah I've got your number!" << endl;

    return 0;
}