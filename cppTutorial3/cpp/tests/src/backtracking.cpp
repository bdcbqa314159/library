#include <cppTutorial3>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void testingFindSubsets()
{
    char input[1000];
    char output[1000];
    cout << "Finding subsets of a string" << endl;
    cin >> input;
    vector<string> l;
    findSubsets(input, output, 0, 0, l);
    sort(l.begin(), l.end(), compareBack);

    for (auto x : l)
        cout
            << x << ",";
    cout << endl;
}

void testingPermute()
{
    char input[1000];
    cout << "Permuting subsets of a string" << endl;
    cin >> input;
    string s(input);
    permute(s, 0);
}

void testingNQueens()
{
    int board[20][20] = {0};
    int n;
    cout << "Give an integer n >>";
    cin >> n;
    solveNQueen(n, board, 0);
    int board1[20][20] = {0};
    cout << "There are " << solveNQueenAllWays(n, board1, 0) << " ways" << endl;
}

void testingGridWays()
{
    int m, n;
    cout << "Give m, n dimensions of the grid: " << endl;
    cin >> m >> n;
    cout << "There are " << gridWays(0, 0, m, n) << " ways" << endl;
}

void testingSudoku()
{
    int n = 9;
    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (!solveSudoku(mat, 0, 0, n))
        cout << "No solution exists" << endl;
}

int main()
{

    cout << "Hey backtracking" << endl;
    // testingFindSubsets();
    // testingPermute();
    // testingNQueens();
    // testingGridWays();
    testingSudoku();

    return 0;
}