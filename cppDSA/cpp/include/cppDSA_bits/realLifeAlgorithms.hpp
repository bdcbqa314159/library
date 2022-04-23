#ifndef REALLIFEALGORITHMS_H
#define REALLIFEALGORITHMS_H
#include <vector>
#include <string>
#include "minHeapNode.hpp"

void MinimalChangeCoin(double changingNominal);
void HuffmanCodes(char data[], int freq[], int datasize);
void multiply(std::vector<std::vector<int>> &A, std::vector<std::vector<int>> &B, std::vector<std::vector<int>> &C);
long long fib(int n);
long long fib2(int n);
int count(int S[], int m, int n);
std::string GenerateCaptcha(int n);

class Random
{
private:
    int state;
    static const int A = 1;
    static const int M = 10;

public:
    explicit Random(int initialValue = 1);
    int randomInt();
    double random0_1();
};

#endif