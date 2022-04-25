#include <iostream>
#include <string>

using namespace std;
int main()
{
    int values[] = {4, 7, 3, 4};
    int n = sizeof(values) / sizeof(int);
    for (int i = 0; i < n; i++)
        cout << values[i] << " ";
    cout << endl;
    return 0;
}