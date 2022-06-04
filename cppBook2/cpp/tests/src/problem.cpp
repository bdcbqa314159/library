#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int helper(vector<vector<int>> &matrix, vector<vector<int>> &cache, int i, int j, int r, int c)
    {
        if (cache[i][j] > 0)
            return cache[i][j];
        int longest = 0;

        for (vector<int> direction : directions)
        {
            int x = direction[0] + i;
            int y = direction[1] + j;

            if (x > -1 && y > -1 && x < r && y < c && matrix[x][y] > matrix[i][j])
            {
                int temp = helper(matrix, cache, x, y, r, c);
                longest = max(temp, longest);
            }
        }
        cache[i][j] = longest + 1;
        return cache[i][j];
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;
        int r = matrix.size(), c = matrix[0].size(), longestPath = 0;
        vector<vector<int>> cache(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int longest = helper(matrix, cache, i, j, r, c);
                longestPath = max(longest, longestPath);
            }
        }
        return longestPath;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    int k = sol.longestIncreasingPath(mat);
    cout << k << endl;

    return 0;
}