#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <string>
#include <unordered_map>
using namespace std;

class Product
{
    int id;
    string name;
    int price;

public:
    Product() : id(0), name(""), price(0)
    {
    }

    Product(int id, string name, int price) : id(id), name(name), price(price)
    {
    }

    string getDisplayName()
    {
        return name + " : £ " + to_string(price) + "\n";
    }

    const int getPrice()
    {
        return price;
    }

    const string getName()
    {
        return name;
    }

    string getShortName()
    {
        return name.substr(0, 1);
    }

    int getId()
    {
        return id;
    }
};
class Item
{
    Product product;
    int quantity;

public:
    Item() : product(), quantity(0)
    {
    }

    Item(Product p, int quantity) : product(p), quantity(quantity)
    {
    }

    int getItemPrice()
    {
        return quantity * product.getPrice();
    }

    string getItemInfo()
    {
        return to_string(quantity) + " * " + product.getName() + " £ " + to_string(quantity * product.getPrice()) + "\n";
    }

    int getQuantity()
    {
        return quantity;
    }

    void addingQuantity()
    {
        quantity++;
    }
};

class Cart
{
    unordered_map<int, Item> items;

public:
    void addProduct(Product product)
    {
        if (items.count(product.getId()) == 0)
        {
            Item newItem(product, 1);
            items[product.getId()] = newItem;
        }
        else
        {
            items[product.getId()].addingQuantity();
        }

        return;
    }

    int getTotal()
    {
        int total = 0;
        for (auto itemPair : items)
        {
            auto item = itemPair.second;
            total += item.getItemPrice();
        }

        return total;
    }

    string viewCart()
    {
        if (items.empty())
            return "Cart is empty.\n";
        string itemizedList;
        int cart_total = getTotal();

        for (auto itemPair : items)
        {
            auto item = itemPair.second;
            itemizedList.append(item.getItemInfo());
        }
        return itemizedList + "\nTotal amount : £" + to_string(cart_total) + "\n";
    }

    bool isEmpty()
    {
        return items.empty();
    }
};

#endif