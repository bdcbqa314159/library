#include <iostream>
#include <iomanip>

using namespace std;

class Test
{
public:
    static const int MAX = 99;

private:
    int id;
    static int count;

public:
    Test()
    {
        id = ++count;
    }

    int getId()
    {
        return id;
    }

    static void showInfo()
    {
        cout << count << endl;
    }
};

class Cell
{

public:
    static const int MAX_CELLS = 1024;

private:
    int cellId;
    int number;
    static int counter;

public:
    Cell()
    {
        number = ++counter;
        cellId = counter;
    }

    int getId()
    {
        return cellId;
    }

    int getNumber()
    {
        return number;
    }

    static int showId()
    {
        return counter;
    }
};

int Test::count = 0;
int Cell::counter = 0;

int main()
{
    cout << "First complement" << endl;
    char value = 127;
    cout << (int)value << endl;
    value++;
    cout << (int)value << endl;
    cout << endl;
    cout << "Second complement" << endl;
    cout << "Prefixes / Postfixes & static keyword." << endl;
    Test::showInfo();
    cout << Test::MAX << endl;

    Test test1;
    cout << "Object 1 ID:" << test1.getId() << endl;
    Test::showInfo();
    Test test2;
    cout << "Object 2 ID:" << test2.getId() << endl;
    Test::showInfo();

    cout << "Exercise with cells" << endl;
    cout << Cell::MAX_CELLS << endl;
    cout << Cell::showId() << endl;

    Cell c1;
    c1.getId();
    c1.getNumber();
    cout << Cell::showId() << endl;

    Cell c2;
    c2.getId();
    c2.getNumber();
    cout << Cell::showId() << endl;

    return 0;
}