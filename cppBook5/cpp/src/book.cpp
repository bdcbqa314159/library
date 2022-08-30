#include "../include/cppBook5_bits/book.hpp"
#include <iostream>
#include <cassert>

Book::Book() : author("unspecified"), title("unspecified"), publisher("unspecified"), format("unspecified"), mYearOfPublication(0), price(0)
{
}

Book::Book(const Book &rhs) : author(rhs.author), title(rhs.title), publisher(rhs.publisher), format(rhs.format), price(rhs.price), mYearOfPublication(rhs.mYearOfPublication)
{
}

Book::Book(string bookTitle) : title(bookTitle)
{
}

Book::~Book()
{
}

void Book::setYearOfPublication(int year)
{
    assert((year > 1440) && (year < 2022));

    this->mYearOfPublication = year;
    return;
}

int Book::getYearOfPublication() const
{
    return mYearOfPublication;
}

Ebook::Ebook() : Book()
{
    format = "electronic";
}