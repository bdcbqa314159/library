#ifndef RECURSION_H
#define RECURSION_H
#include <iostream>
#include <vector>
#include <string>

int factorial(int n);
int fibonacci(int n);
bool isSorted(int a[], int n);
void dec(int n);
void inc(int n);
int firstOcc(int a[], int n, int key);
int lastOcc(int a[], int n, int key);
int power(int a, int n);
int powerPlus(int a, int n);

std::vector<std::string> numbers{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void numberSpell(int n);

#endif