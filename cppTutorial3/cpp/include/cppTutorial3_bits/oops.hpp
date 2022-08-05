#ifndef OOPS_H
#define OOPS_H
#include <string>

using namespace std;

class ProductTest
{
    int id;
    string name;
    int mrp;
    int selling_price;

public:
    void setMRP(int price);
    void setSellingPrice(int price);

    int getMRP();
    int getSellingPrice();

    ProductTest();
    ProductTest(int id, string name, int mrp, int selling_price);
    ProductTest(ProductTest &rhs);
    void operator=(ProductTest &rhs);
    ~ProductTest();

    void showDetails();
};

#endif