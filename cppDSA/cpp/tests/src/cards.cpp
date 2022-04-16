#include <cppDSA>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout << "Without Cards Struct" << endl;
    srand(static_cast<unsigned int>(time(0)));
    int iSuit = GenerateRandomNumber(0, 3);
    int iElement = GenerateRandomNumber(0, 12);

    CardSuits suit = static_cast<CardSuits>(iSuit);
    CardElements element = static_cast<CardElements>(iElement);

    cout << "Your card is ";
    cout << GetElementString(element);
    cout << " of " << GetSuitString(suit);
    cout << endl;

    cout << "With Cards Struct" << endl;
    Cards card;
    iSuit = GenerateRandomNumber(0, 3);
    iElement = GenerateRandomNumber(0, 12);

    card.suit = static_cast<CardSuits>(iSuit);
    card.element = static_cast<CardElements>(iElement);

    cout << "Your card is ";
    cout << GetElementString(card.element);
    cout << " of " << GetSuitString(card.suit);
    cout << endl;

    return 0;
}