#ifndef MULTIDIMARRAY_H
#define MULTIDIMARRAY_H
#include <iostream>
#include <utility>

using namespace std;

void spiralPrint(int arr[][100], int n, int m);
pair<int, int> search2D(int arr[][100], int n, int m, int key);
int mangoTreeOptimized(char arr[][100], int n);

#endif

/*
Important:
char numbers[][10] = {
    "one",
    "two",
    "three",
    "four",
    "five",
    "six"
};
*/

/*
Very important:
dynamic allocation for a matrix:
int **arr = new int*[rows];
for (int i = 0; i<rows; i++)
    arr[i] = new int[cols];
*/
