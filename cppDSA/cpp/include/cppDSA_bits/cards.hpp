#include <string>
#ifndef CARDS_H
#define CARDS_H

enum CardSuits
{
    Club,
    Diamond,
    Heart,
    Spade
};

enum CardElements
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

struct Cards
{
    CardSuits suit;
    CardElements element;
};

std::string GetSuitString(CardSuits suit);
std::string GetElementString(CardElements element);

#endif