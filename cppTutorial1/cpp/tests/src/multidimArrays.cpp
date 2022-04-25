#include <iostream>
#include <string>
#include <string>

using namespace std;
int main()
{
    string animals[2][3] = {{"fox", "dog", "cat"},
                            {"mouse", "squirrel", "parrot"}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << animals[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    string animals1[][3] = {{"fox", "dog", "cat"},
                            {"mouse", "squirrel", "parrot"},
                            {"lion", "puma", "eagle"}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << animals1[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    cout << "Small exercise:" << endl;
    int ex[10][10] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            ex[i][j] = (i + 1) * (j + 1);
    }

    cout << "Displaying: " << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << i + 1 << " * " << j + 1 << " = " << ex[i][j] << endl;
        cout << endl;
    }

    return 0;
}