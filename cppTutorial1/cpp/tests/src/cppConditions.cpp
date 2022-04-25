#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    int val1 = 7;
    int val2 = 4;
    if (val1 < 8)
    {
        cout << "Condition1: true" << endl;
    }
    else
    {
        cout << "Condition2: false" << endl;
    }

    if (val1 == 7 && val2 < 3)
    {
        cout << "Condition2: true" << endl;
    }
    else
    {
        cout << "Condition2: false" << endl;
    }

    if (val1 == 7 || val2 < 3)
    {
        cout << "Condition3: true" << endl;
    }
    else
    {
        cout << "Condition3: false" << endl;
    }

    if ((val2 != 8 && val1 == 7) || val1 < 10)
    {
        cout << "Condition4: true" << endl;
    }
    else
    {
        cout << "Condition4: false" << endl;
    }

    bool condition1 = (val2 != 8 && val1 == 7);
    cout << boolalpha << condition1 << endl;

    bool condition2 = val1 > 10;
    cout << boolalpha << condition2 << endl;
    if (condition1 || condition2)
    {
        cout << "Condition5: true" << endl;
    }
    else
    {
        cout << "Condition5: false" << endl;
    }

    return 0;
}