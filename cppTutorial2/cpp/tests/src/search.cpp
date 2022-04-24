#include <cppTutorial2>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Testing linear search: " << endl;
    int array[] = {1, 12, 4, 8, -2, 0, 1, 9};
    int n = sizeof(array) / sizeof(int);
    linearSearch(array, n, 1);

    cout << "===========" << endl;
    cout << "Testing binary search:" << endl;
    vector<int> nums = {1, 233, 23, 56, 10, 11, 35, 109, 5, 2, 6, 8, 90, 2, 3, 40, 20, 20, 10, 11};

    sort(nums.begin(), nums.end());
    int toFind = 20;
    int result = binarySearch(nums, 0, nums.size() - 1, toFind);
    cout << toFind << " found? " << endl;
    cout << "Index: " << result << endl;
    cout << "Check inside the vector >>" << endl;
    for (auto n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}