#include <iostream>
#include <string>

using namespace std;
int main()
{
    int input = 0;
    int values[3] = {};

    cout << "Right after initialisation with {}" << endl;
    for (int i = 0; i < 3; i++)
        cout << values[i] << " ";

    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Set values[" << i << "] = ";
        cin >> input;
        values[i] = input;
    }

    cout << "There are the elements you just put in." << endl;
    for (int i = 0; i < 3; i++)
        cout << values[i] << " ";

    double numbers[4] = {1.8, 3.5, 90.342, 1.234};

    cout << "There are the elements in numbers: " << endl;
    for (int i = 0; i < 4; i++)
        cout << numbers[i] << " ";
    cout << endl;

    cout << "There are the elements in text: " << endl;
    string text[] = {"app", "ere", "alakdf"};
    for (int i = 0; i < 3; i++)
        cout << text[i] << " ";
    cout << endl;

    cout << "WARNING: if we assign int table[3]" << endl;
    cout << "we can do ask table[4] without any warning!" << endl;

    cout << "Small exercise: 12 times table." << endl;
    int ex[13] = {};
    for (int i = 0; i < 13; i++)
    {
        ex[i] = 12 * i;
    }

    cout << "Result:" << endl;
    for (int i = 0; i < 13; i++)
        cout << "12 * " << i << " = " << ex[i] << endl;

    cout << endl;

    return 0;
}