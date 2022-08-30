#include <cppBook5>
#include <iostream>

using namespace std;

void complexNumbers()
{

    ComplexNumber z1(4., 3.);
    cout << "z1 = " << z1 << endl;

    cout << " Modulus z1 = " << z1.calculateModulus() << endl;

    cout << " Argument z1 = " << z1.calculateArgument() << endl;

    ComplexNumber z2;
    z2 = z1.calculatePower(3);

    cout << "z2 = z1^3 = " << z2 << endl;

    ComplexNumber z3;
    z3 = -z2;

    cout << "z3 = -z2 = " << z3 << endl;

    ComplexNumber z4;
    z4 = z1 + z2;

    cout << "z4 = z1+z2 = " << z4 << endl;
}

void Books()
{

    Book good_read;

    good_read.author = "C S Lewis";
    good_read.title = "The silver chair";
    good_read.publisher = "Geoffrey Bles";
    good_read.price = 699;
    good_read.format = "paperback";
    good_read.setYearOfPublication(1953);

    Book another_book(good_read);
    Book an_extra_book("The Magician's nephew");

    Ebook holiday_reading;
    holiday_reading.title = "Skull beneath the skin";
    holiday_reading.author = "P D James";
    cout << "The author is " << holiday_reading.author << endl;
    cout << "The format is " << holiday_reading.format << endl;

    holiday_reading.setYearOfPublication(1982);
    cout << "Year of publication is " << holiday_reading.getYearOfPublication() << endl;
    holiday_reading.hiddenUrl = "http://ebook.example.com/example-book";
    cout << "The URL is " << holiday_reading.hiddenUrl << endl;
}

int main()
{

    Guest *pgu1 = new Guest;
    Guest *pgu2 = new Guest;
    Guest *pgu3 = new SpecialGuest;

    pgu1->numberOfNights = 3;
    pgu1->telephoneBill = 0.;
    pgu2->numberOfNights = 3;
    pgu2->telephoneBill = 0.;
    pgu3->numberOfNights = 3;
    pgu3->telephoneBill = 0.;

    cout << "Bill 1: " << pgu1->CalculateBill() << endl;
    cout << "Bill 2: " << pgu2->CalculateBill() << endl;
    cout << "Bill 3: " << pgu3->CalculateBill() << endl;

    delete pgu1;
    delete pgu2;
    delete pgu3;

    return 0;
}