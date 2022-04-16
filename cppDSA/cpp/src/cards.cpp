#include "../include/cppDSA_bits/cards.hpp"

using namespace std;

string GetSuitString(CardSuits suit)
{
    string s;
    switch (suit)
    {
    case Club:
        s = "Club";
        break;
    case Diamond:
        s = "Diamond";
        break;

    case Heart:
        s = "Heart";
        break;
    case Spade:
        s = "Spade";
        break;
    }
    return s;
}

string GetElementString(CardElements element)
{

    string e;
    switch (element)
    {
    case Ace:
        e = "Ace";
        break;
    case Two:
        e = "Two";
        break;
    case Three:
        e = "Three";
        break;
    case Four:
        e = "Four";
        break;
    case Five:
        e = "Five";
        break;
    case Six:
        e = "Six";
        break;
    case Seven:
        e = "Seven";
        break;
    case Eight:
        e = "Eight";
        break;
    case Nine:
        e = "Nine";
        break;
    case Ten:
        e = "Ten";
        break;
    case Jack:
        e = "Jack";
        break;
    case Queen:
        e = "Queen";
        break;
    case King:
        e = "King";
        break;
    }
    return e;
}
