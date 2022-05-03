#include <iostream>

using namespace std;

int main()
{

    cout << "Working with arrays." << endl;
    const int SIZE = 10;
    int nums[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < SIZE; i++)
        cout << nums[i] << " ";
    cout << endl;

    cout << "Updating..." << endl;
    nums[2] = 100;

    for (int i = 0; i < SIZE; i++)
        cout << nums[i] << " ";
    cout << endl;
    cout << "Looking for 8:" << endl;

    for (int i = 0; i < SIZE; i++)
        if (nums[i] == 8)
            cout << "Found it at " << i << endl;

    cout << "Erasing 3rd item..." << endl;
    nums[2] = 0;
    for (int i = 2; i < SIZE - 1; i++)
        nums[i] = nums[i + 1];

    nums[SIZE - 1] = 0;

    cout << "Showing again last item = 0 because was erased and shifted." << endl;
    for (int i = 0; i < SIZE; i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}