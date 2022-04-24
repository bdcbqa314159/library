#include "../include/cppTutorial2_bits/search.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

void linearSearch(int arr[], int n, int a)
{
    std::vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
            ans.push_back(i);
    }
    if (ans.size() == 0)
    {
        std::cout << "Item " << a << " not present." << std::endl;
        return;
    }

    else
    {
        if (ans.size() == 1)
        {
            std::cout << "Item " << a << " found at index: " << ans[0] << std::endl;
            return;
        }

        else
        {
            std::cout << "Item " << a << " found at indices: " << std::endl;
            for (int i = 0; i < ans.size(); i++)
                std::cout << ans[i] << " ";
            std::cout << std::endl;
            return;
        }
    }
}

int binarySearch(std::vector<int> &v, int low, int high, int a)
{
    if (low > high)
        return -1;
    int middle = low + (high - low) / 2;

    if (v[middle] == a)
        return middle;
    else if (v[middle] < a)
        return binarySearch(v, middle + 1, high, a);
    else
        return binarySearch(v, low, middle - 1, a);
}