#include <cppTutorial3>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
// Input 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
void testingHashTables()
{
    HashTable h;

    h.insert("Mango", 100);
    h.insert("Apple", 120);
    h.insert("Banana", 140);
    h.insert("Orange", 200);

    h.print();
    cout << endl;
    h.insert("Kiwi", 210);
    h.insert("Papaya", 220);
    h.insert("Litchi", 30);
    h.print();

    string fruit;
    cin >> fruit;

    int *price = h.search(fruit);
    if (price)
    {
        cout << "the price for " << fruit << " is " << *price << endl;
    }
    else
    {
        cout << fruit << " is not in our menu, sorry" << endl;
    }

    h["pear"] = 220;
    cout << "pear cost is " << h["pear"] << endl;
    h.print();
    h["pear"] += 20;
    cout << "pear cost is " << h["pear"] << endl;

    return;
}

int main()
{
    testingHashTables();
    return 0;
}