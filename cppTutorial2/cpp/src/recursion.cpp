#include "../include/cppTutorial2_bits/recursion.hpp"
#include <iostream>

void tail(int n)
{
    if (n == 0)
        return;
    std::cout << "Tail function called with n= " << n << std::endl;
    tail(n - 1);
}

void head(int n)
{
    if (n == 0)
        return;
    head(n - 1);
    std::cout << "Head recursion called with n=" << n << std::endl;
}

int factorial(int n)
{

    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int factorialAccumulator(int n, int accumulator)
{

    if (n == 1)
        return accumulator;
    return factorialAccumulator(n - 1, n * accumulator);
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciTail(int n, int a, int b)
{

    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fibonacciTail(n - 1, b, a + b);
}

void hanoiSolve(int n, char rodFrom, char middleRod, char rodTo)
{
    if (n == 1)
    {
        std::cout << "Plate 1 from " << rodFrom << " to " << rodTo << std::endl;
        return;
    }

    hanoiSolve(n - 1, rodFrom, rodTo, middleRod);
    std::cout << "Plate " << n << " from " << rodFrom << " to " << rodTo << std::endl;
    hanoiSolve(n - 1, middleRod, rodFrom, rodTo);
}