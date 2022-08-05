#include <cppTutorial3>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
// Input 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

vector<Product> allProducts = {

    Product(1, "apple", 26),
    Product(3, "mango", 16),
    Product(2, "guava", 36),
    Product(5, "banana", 56),
    Product(4, "strawberry", 29),
    Product(6, "pineapple", 20),

};

Product *chooseProduct()
{
    string productList;
    cout << "Available products:" << endl;

    for (auto product : allProducts)
    {
        productList.append(product.getDisplayName());
    }
    cout << productList << endl;
    cout << "------------------" << endl;
    string choice;
    cin >> choice;

    for (int i = 0; i < allProducts.size(); i++)
    {
        if (allProducts[i].getShortName() == choice)
        {
            return &allProducts[i];
        }
    }

    cout << "Product not found" << endl;
    return nullptr;
}

bool checkout(Cart &cart)
{
    if (cart.isEmpty())
        return false;
    int total = cart.getTotal();
    cout << "Pay in cash: £ >>> ";
    int paid;
    cin >> paid;

    if (paid >= total)
    {
        cout << "Change " << paid - total << endl;
        cout << "Thank you for shopping with us" << endl;
        return true;
    }
    else
    {
        cout << "Not enough cash" << endl;
        return false;
    }
}

void testingShoppingCart()
{
    // cout << "=====Shopping Cart Testing======" << endl;
    // Product p(1, "apple", 26);
    // cout << p.getDisplayName() << endl;

    // Item fruit(p, 3);
    // cout << fruit.getItemInfo() << endl;
    char action;
    Cart cart;
    while (true)
    {
        cout << "Select action - (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin >> action;

        if (action == 'a')
        {
            Product *product = chooseProduct();
            if (product)
            {
                cout << "Added to the cart: " << product->getDisplayName() << endl;
                cart.addProduct(*product);
            }
        }

        else if (action == 'v')
        {
            cout << "-------------" << endl;
            cout << cart.viewCart();
            cout << "-------------" << endl;
        }

        else
        // (action == 'c')
        {
            cart.viewCart();
            if (checkout(cart))
                break;
        }
    }

    return;
}

int main()
{
    testingShoppingCart();
    return 0;
}