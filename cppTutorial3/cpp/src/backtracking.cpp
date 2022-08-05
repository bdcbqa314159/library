#include "../include/cppTutorial3_bits/backtracking.hpp"
#include <iostream>

using namespace std;

bool compareBack(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

void findSubsets(char *input, char *output, int i, int j, vector<string> &v)
{

    if (input[i] == '\0')
    {
        output[j] = '\0';
        string temp(output);
        v.push_back(temp);
        return;
    }

    output[j] = input[i];
    findSubsets(input, output, i + 1, j + 1, v);
    output[j] = '\0';
    findSubsets(input, output, i + 1, j, v);
}

void permute(string &s, int i)
{
    // BASE CASE
    if (i == s.length() - 1)
    {
        cout << s << endl;
        return;
    }

    for (int j = i; j < s.length(); j++)
    {

        swap(s[i], s[j]);
        // RECURSIVE CASE
        permute(s, i + 1);

        swap(s[i], s[j]);
    }
}

void printBoard(int n, int board[][20])
{
    if (n >= 20)
        return;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j];
        cout << endl;
    }
    cout << endl;
}

bool canPlace(int board[][20], int n, int i, int j)
{
    for (int k = 0; k < i; k++)
    {
        if (board[k][j] == 1)
            return false;
    }

    int k = i, l = j;

    while (k >= 0 and l >= 0)
    {
        if (board[k][l] == 1)
            return false;
        k--;
        l--;
    }

    k = i, l = j;

    while (k >= 0 and l < n)
    {
        if (board[k][l] == 1)
            return false;
        k--;
        l++;
    }

    return true;
}

bool solveNQueen(int n, int board[][20], int i)
{
    if (i == n)
    {
        printBoard(n, board);
        return true;
    }

    for (int j = 0; j < n; j++)
    {
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            bool success = solveNQueen(n, board, i + 1);
            if (success)
            {
                return true;
            }

            board[i][j] = 0;
        }
    }
    return false;
}

int solveNQueenAllWays(int n, int board[][20], int i)
{
    if (i == n)
    {
        return 1;
    }

    int ways = 0;
    for (int j = 0; j < n; j++)
    {
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            ways += solveNQueenAllWays(n, board, i + 1);
            board[i][j] = 0;
        }
    }
    return ways;
}

int gridWays(int i, int j, int m, int n)
{
    if (i == m - 1 and j == n - 1)
        return 1;
    if (j >= n or i >= m)
        return 0;
    int ans = gridWays(i + 1, j, m, n) + gridWays(i, j + 1, m, n);
    return ans;
}

bool isSafe(int mat[][9], int i, int j, int no, int n)
{
    for (int k = 0; k < 9; k++)
    {
        if (mat[k][j] == no || mat[i][k] == no)
            return false;
    }

    int sx = (i / 3) * 3, sy = (j / 3) * 3;
    for (int x = sx; x < sx + 3; x++)
    {
        for (int y = sy; y < sy + 3; y++)
        {
            if (mat[x][y] == no)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[9][9], int i, int j, int n)
{
    if (i == n)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << mat[i][j] << ' ';
            cout << endl;
        }

        cout << endl;
        return true;
    }

    if (j == n)
    {
        return solveSudoku(mat, i + 1, 0, n);
    }

    if (mat[i][j] != 0)
    {
        return solveSudoku(mat, i, j + 1, n);
    }

    for (int no = 1; no <= n; no++)
    {
        if (isSafe(mat, i, j, no, n))
        {
            mat[i][j] = no;
            bool solveSubproblem = solveSudoku(mat, i, j, n);
            if (solveSubproblem == true)
            {
                return true;
            }
        }
    }

    mat[i][j] = 0;
    return false;
}