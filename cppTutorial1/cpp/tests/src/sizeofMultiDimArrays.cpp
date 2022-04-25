#include <iostream>
#include <string>

using namespace std;
int main()
{
    string animals[][3] = {{"fox", "dog", "cat"},
                           {"mouse", "squirrel", "parrot"},
                           {"lion", "puma", "eagle"}};

    int n = sizeof(animals) / sizeof(animals[0]);
    int m = sizeof(animals[0]) / sizeof(string);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << animals[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    return 0;
}