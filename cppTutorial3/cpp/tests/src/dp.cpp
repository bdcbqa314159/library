#include <cppTutorial3>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
// Input 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
void testingDP()
{
    cout << "=====Coin Change Promblem======" << endl;
    vector<int> denoms = {1, 5, 7, 10};
    int m = 8;
    cout << minNumberOfCoinsForChange(m, denoms) << endl;
    cout << "\n\n======Longest Increasing Problem==========" << endl;
    vector<int> arr = {50, 4, 10, 8, 30, 100};
    cout << lis(arr) << endl;

    cout << "\n\n======Knapsack Problem==========" << endl;
    vector<int> wts = {2, 7, 3, 4};
    vector<int> prices = {5, 20, 20, 10};
    int N = 4, W = 11;

    cout << knapsack(wts, prices, N, W) << endl;

    cout << "\n\n======Wines Problem Top Down==========" << endl;
    int a[] = {2, 3, 5, 1, 4};
    int n = 5;
    int dp[10][10] = {0};

    cout << wines(dp, a, 0, n - 1, 1) << endl;

    cout << "\n\n======Wines Problem Bottom Up==========" << endl;
    vector<int> a1 = {2, 3, 5, 1, 4};

    cout << winesBU(a1, n) << endl;

    return;
}

int main()
{
    testingDP();
    return 0;
}