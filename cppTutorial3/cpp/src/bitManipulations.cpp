#include "../include/cppTutorial3_bits/bitManipulations.hpp"

bool checkOddEven(int n)
{
    // only with bits!

    return 1 & n;
}

int getBit(int n, int i)
{
    int mask = 1 << i;
    return n & mask ? 1 : 0;
}

void setBit(int &n, int i)
{
    int mask = 1 << i;
    n = n | mask;
}

void clearBit(int &n, int i)
{
    int mask = ~(1 << i);
    n = n & mask;
}

void updateBit(int &n, int i, int v)
{
    clearBit(n, i);
    int mask = v << i;
    n = n | mask;
}

void clearLastBits(int &n, int i)
{
    int mask = (-1 << i);
    n = n & mask;
}

void clearBitsRange(int &n, int i, int j)
{
    int mask1 = (-1 << (j + 1)), mask2 = (1 << i) - 1, mask3 = mask1 | mask2;
    n = n & mask3;
}

void insertNinM(int &n, int i, int j, int m)
{
    clearBitsRange(n, i, j);
    int mask = m << i;
    n = n | mask;
}

bool powerOfTwo(int n)
{
    return (n & (n - 1)) == 0;
}

int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count += n & 1;
        n >> 1;
    }

    return count;
}

int countSetBitsHacked(int n)
{
    int count;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }

    return n;
}

int fastExponentiation(int a, int N)
{
    int ans = 1;
    while (N > 0)
    {
        int lastBit = N & 1;
        if (lastBit)
        {
            ans *= a;
        }

        a *= a;
        N = N >> 1;
    }
    return ans;
}

int convertToBinary(int n)
{
    int ans = 0, p = 1;
    while (n > 0)
    {
        int lastBit = (n & 1);
        ans += lastBit * p;
        p *= 10;
        n >> 1;
    }

    return ans;
}