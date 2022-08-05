#ifndef BITMANIPULATIONS_H
#define BITMANIPULATIONS_H

bool checkOddEven(int n);
int getBit(int n, int i);
void setBit(int &n, int i);
void clearBit(int &n, int i);
void updateBit(int &n, int i, int v);
void clearLastBits(int &n, int i);
void clearBitsRange(int &n, int i, int j);
void insertNinM(int &n, int i, int j, int m);
bool powerOfTwo(int n);
int countSetBits(int n);
int fastExponentiation(int a, int N);

#endif