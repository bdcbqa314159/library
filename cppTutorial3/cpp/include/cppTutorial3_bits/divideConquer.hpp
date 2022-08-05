#ifndef DIVIDECONQUER_H
#define DIVIDECONQUER_H
#include <vector>

using namespace std;

void merge(vector<int> &a, int s, int e);
void mergeSort(vector<int> &a, int s, int e);
int partition(vector<int> &a, int s, int e);
void quickSort(vector<int> &a, int s, int e);
int rotatedSearch(vector<int> &a, int k);

#endif