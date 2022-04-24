#ifndef RECURSION_H
#define RECURSION_H

void tail(int n);
void head(int n);
int factorial(int n);
int factorialAccumulator(int n, int accumulator);
int fibonacci(int n);
int fibonacciTail(int n, int a, int b);
void hanoiSolve(int n, char rodFrom, char middleRod, char rodTo);

#endif