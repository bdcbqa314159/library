#include "../include/cppTutorial3_bits/oops.hpp"
#include <iostream>
using namespace std;

void ProductTest::setMRP(int price)
{
    if (price > 0)
    {
        mrp = price;
    }
}
void ProductTest::setSellingPrice(int price)
{
    if (price > mrp)
    {
        selling_price = mrp;
    }
    else
    {
        selling_price = price;
    }
}

int ProductTest::getMRP()
{
    return mrp;
}

int ProductTest::getSellingPrice()
{
    return selling_price;
}

ProductTest::ProductTest()
{
    cout << "default constructor" << endl;
}

ProductTest::ProductTest(int id, string name, int mrp, int selling_price) : id(id), name(name), mrp(mrp), selling_price(selling_price)
{
    cout << "Parametrized constructor" << endl;
}

ProductTest::ProductTest(ProductTest &rhs)
{
    id = rhs.id;
    name = rhs.name;
    selling_price = rhs.selling_price;
    mrp = rhs.mrp;
}

void ProductTest::operator=(ProductTest &rhs)
{
    if (this != &rhs)
    {
        id = rhs.id;
        name = rhs.name;
        selling_price = rhs.selling_price;
        mrp = rhs.mrp;
    }
    return;
}

ProductTest::~ProductTest()
{
    cout << "Deleting ProductTest" << endl;
}

void ProductTest::showDetails()
{
    cout << "id: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "selling price: " << selling_price << endl;
    cout << "mrp: " << mrp << endl;
}