#ifndef BACKTRACKING_H
#define BACKTRACKING_H
#include <vector>
#include <string>

using namespace std;

void findSubsets(char *input, char *output, int i, int j, vector<string> &v);
bool compareBack(string a, string b);
void permute(string &s, int i = 0);
bool canPlace(int board[][20], int n, int i, int j);
void printBoard(int n, int board[][20]);
bool solveNQueen(int n, int board[][20], int i);
int solveNQueenAllWays(int n, int board[][20], int i);
int gridWays(int i, int j, int m, int n);
bool isSafe(int mat[9][9], int i, int j, int no, int n);
bool solveSudoku(int mat[9][9], int i, int j, int n);

#endif