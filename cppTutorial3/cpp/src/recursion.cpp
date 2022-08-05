#include "../include/cppTutorial3_bits/recursion.hpp"
using namespace std;

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if (n <= 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

bool isSorted(int a[], int n)
{
    if (n == 1 || n == 0)
        return true;
    if (a[0] < a[1] && isSorted(a + 1, n - 1))
        return true;
    return false;
}

void dec(int n)
{
    if (n == 0)
        return;
    cout << n << ", ";
    dec(n - 1);
}

void inc(int n)
{
    if (n == 0)
        return;
    inc(n - 1);
    cout << n << ", ";
}

int firstOcc(int a[], int n, int key)
{
    if (n == 0)
        return -1;
    if (a[0] == key)
        return 0;

    int subIndex = firstOcc(a + 1, n - 1, key);
    if (subIndex != -1)
        return subIndex + 1;
    else
        return -1;
}

int lastOcc(int a[], int n, int key)
{
    if (n == 0)
        return -1;

    int subIndex = firstOcc(a + 1, n - 1, key);
    if (subIndex != -1)
    {
        if (a[0] == key)
            return 0;
        else
            return -1;
    }
    return subIndex + 1;
}

int power(int a, int n)
{
    if (n == 0)
        return 1;
    return a * power(a, n - 1);
}

int powerPlus(int a, int n)
{
    if (n == 0)
        return 1;
    int temp = powerPlus(a, n / 2);
    temp *= temp;
    if (n & 1)
        return a * temp;
    else
        return temp;
}

void numberSpell(int n)
{
    if (n == 0)
        return;
    int a = n % 10;
    numberSpell(n / 10);
    cout << numbers[a] << " ";
}