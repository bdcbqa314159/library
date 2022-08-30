#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book
{
    int mYearOfPublication;

public:
    Book();
    Book(const Book &rhs);
    Book(string bookTitle);
    ~Book();
    string author, title, publisher, format;
    int price;

    void setYearOfPublication(int year);
    int getYearOfPublication() const;
};

class Ebook : public Book
{
public:
    Ebook();
    string hiddenUrl;
};

#endif