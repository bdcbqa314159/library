#include "../include/cppTutorial3_bits/spaceTime.hpp"
#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>

using namespace std;

void ticking()
{
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        arr[i] = n - i;

    auto startTime = clock();
    sort(arr.begin(), arr.end());
    auto endTime = clock();

    cout << "Time elapsed: " << endTime - startTime << " ms" << endl;
}