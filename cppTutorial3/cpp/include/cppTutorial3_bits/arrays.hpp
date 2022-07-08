#ifndef ARRAYS_H
#define ARRAYS_H

#include <iostream>

void showArray(int *arr, int n);
int linearSearch(int *arr, int n, int key);
int binarySearch(int *arr, int n, int key);
void reverse(int *arr, int n);
void printingPairs(int *arr, int n);
void printingSubarrays(int *arr, int n);

int maxSubarrayVersion1(int *arr, int n);
int maxSubarrayVersion2(int *arr, int n);
int maxSubarrayVersion3(int *arr, int n);
int maxSubarrayVersion4(int *arr, int n);

void characterArraysHW();
void giveAlphaDigitsSpaces();
void characterArrays();
void shortestPath();
void largestString();

#endif