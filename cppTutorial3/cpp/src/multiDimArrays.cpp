#include "../include/cppTutorial3_bits/multiDimArrays.hpp"
using namespace std;

void spiralPrint(int arr[][100], int n, int m)
{
    int sR = 0, eR = n - 1, sC = 0, eC = m - 1;

    while ((sC <= eC) && (sR <= eR))
    {
        for (int col = sC; col <= eC; col++)
        {
            cout << arr[sR][col] << " ";
        }

        for (int row = sR + 1; row <= eR; row++)
        {
            cout << arr[row][eC] << " ";
        }

        for (int col = eC - 1; col >= sC; col--)
        {
            if (sR == eR)
                break;
            cout << arr[eR][col] << " ";
        }

        for (int row = eR - 1; row >= sR + 1; row--)
        {
            if (sC == eC)
                break;
            cout << arr[row][sC] << " ";
        }
        sR++;
        eR--;
        sC++;
        eC--;
    }
}

pair<int, int> search2D(int arr[][100], int n, int m, int key)
{
    if (key < arr[0][0] || key > arr[n - 1][m - 1])
        return {-1, -1};

    int i = 0, j = m - 1;
    while (i <= n - 1 and j >= 0)
    {
        if (arr[i][j] == key)
            return {i, j};
        else if (arr[i][j] > key)
            j--;
        else
            i++;
    }
    return {-1, -1};
}

int mangoTreeOptimized(char arr[][100], int n)
{
    int ans = 0;
    int temp[100][100];

    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == '#')
            temp[i][0] = 1;
        else
            temp[i][0] = 0;
        if (i != 0)
            temp[i][0] += temp[i - 1][0];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[0][i] == '#')
            temp[0][i] = 1;
        else
            temp[0][i] = 0;
        if (i != 0)
            temp[0][i] += temp[0][i - 1];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == '#')
                temp[i][j] = 1 + temp[i - 1][j] + temp[i][j - 1] - temp[i - 1][j - 1];
            else
                temp[i][j] = temp[i - 1][j] + temp[i][j - 1] - temp[i - 1][j - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }

    for (int row = 0; row < n - 1; row++)
    {
        int s1, s2, s3, s4;
        int min_tree;
        for (int col = 0; col < n - 1; col++)
        {
            s1 = temp[row][col];
            s2 = temp[row][n - 1] - s1;
            s3 = temp[n - 1][col] - s1;
            s4 = temp[n - 1][n - 1] - s1 - s2 - s3 - s4;

            min_tree = min(s1, min(s2, min(s3, s4)));
            ans = max(ans, min_tree);
        }
    }
    return ans;
}