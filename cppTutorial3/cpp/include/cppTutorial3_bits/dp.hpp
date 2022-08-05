#ifndef DP_H
#define DP_H

#include <vector>
using namespace std;

int lis(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);

    int len = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
                len = max(len, dp[i]);
            }
        }
    }

    return len;
}

int minNumberOfCoinsForChange(int m, vector<int> &denoms)
{
    vector<int> dp(m + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= m; i++)
    {
        dp[i] = INT_MAX;
        for (int c : denoms)
        {
            if (i - c >= 0 && dp[i - c] != INT_MAX)
                dp[i] = min(dp[i], dp[i - c]) + 1;
        }
    }
    return dp[m] == INT_MAX ? -1 : dp[m];
}

// Converting this recursive into dp solution.
// int knapsack(vector<int> &wts, vector<int> &prices, int N, int W)
// {
//     if (N == 0 || W == 0)
//         return 0;
//     int inc = 0, exc = 0;
//     if (wts[N - 1] <= W)
//     {
//         inc = prices[N - 1] + knapsack(wts, prices, N - 1, W - wts[N - 1]);
//     }
//     exc = knapsack(wts, prices, N - 1, W);
//     return max(inc, exc);
// }

int knapsack(vector<int> &wts, vector<int> &prices, int N, int W)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int n = 1; n <= N; n++)
    {
        for (int w = 1; w <= W; w++)
        {
            int inc = 0, exc = 0;

            if (wts[n - 1] <= w)
            {
                inc = prices[n - 1] + dp[n - 1][w - wts[n - 1]];
            }

            exc = dp[n - 1][w];

            dp[n][w] = max(inc, exc);
        }
    }
    return dp[N][W];
}

int wines(int dp[][10], int prices[], int L, int R, int y)
{
    if (L > R)
        return 0;

    if (dp[L][R] != 0)
        return dp[L][R];
    int pick_l = y * prices[L] + wines(dp, prices, L + 1, R, y + 1);
    int pick_r = y * prices[R] + wines(dp, prices, L, R - 1, y + 1);

    return dp[L][R] = max(pick_l, pick_r);
}

int winesBU(vector<int> &prices, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dp[i][i] = n * prices[i];
            else if (i < j)
            {
                int y = n - (j - i);
                int pickLeft = prices[i] * y + dp[i + 1][j];
                int picKRight = prices[j] * y + dp[i][j - 1];

                dp[i][j] = max(pickLeft, picKRight);
            }
        }
    }
    return dp[0][n - 1];
}

#endif