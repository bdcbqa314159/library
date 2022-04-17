#include <cppDSA>
#include <iostream>

using namespace std;

int main()
{
    int arr[] = {21, 47, 87, 35, 92};
    cout << "Array elements: ";
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); ++i)
        cout << arr[i] << " ";
    cout << endl;

    arr[2] = 30;
    arr[4] = 64;

    cout << "Array elements: ";
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}