#include "../include/cppDSA_bits/realLifeAlgorithms.hpp"
#include <iostream>
#include <queue>

void MinimalChangeCoin(double changingNominal)
{
    std::vector<double> denom{0.01, 0.05, 0.10, 0.25, 1, 2, 5, 10, 20, 50, 100};
    int totalDenom = denom.size();

    std::vector<double> result;

    for (int i = totalDenom - 1; i >= 0; --i)
    {
        while (changingNominal >= denom[i])
        {
            changingNominal -= denom[i];
            result.push_back(denom[i]);
        }
        if (changingNominal < denom[0])
            break;
    }

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

void HuffmanCodes(char data[], int freq[], int dataSize)
{
    MinHeapNode *left, *right, *top;
    std::priority_queue<MinHeapNode *, std::vector<MinHeapNode *>, compare> minHeap;
    for (int i = 0; i < dataSize; i++)
    {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
        while (minHeap.size() != 1)
        {
            left = minHeap.top();
            minHeap.pop();
            right = minHeap.top();
            minHeap.pop();
            top = new MinHeapNode('$', left->Frequency + right->Frequency);
            top->LeftChild = left;
            top->RightChild = right;
            minHeap.push(top);
        }
        PrintCodes(minHeap.top(), "");
    }
}

void multiply(std::vector<std::vector<int>> &A, std::vector<std::vector<int>> &B, std::vector<std::vector<int>> &C)
{
    // Squared Matrices and all the same for multiplication
    int N = A.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

long long fib(int n)
{
    if (n <= 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

long long fib2(int n)
{
    if (n <= 1)
        return 1;

    long long last = 1;
    long long nextToLast = 1;
    long long answer = 1;

    for (int i = 2; i <= n; ++i)
    {
        answer = last + nextToLast;
        nextToLast = last;
        last = answer;
    }

    return answer;
}

int count(int S[], int m, int n)
{
    int x, y;
    int table[n + 1][m];
    for (int i = 0; i < m; i++)
        table[0][i] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;
            y = (j >= 1) ? table[i][j - 1] : 0;
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}

std::string GenerateCaptcha(int n)
{
    time_t t;
    std::srand((unsigned)time(&t));
    std::string chrs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string captcha = "";

    while (--n)
        captcha.push_back(chrs[rand() % 62]);
    return captcha;
}

Random::Random(int intialValue)
{
    if (intialValue < 0)
        intialValue += M;
    state = intialValue;
    if (state == 0)
        state = 1;
}

int Random::randomInt()
{
    return state = (A * state) % M;
}

double Random::random0_1()
{
    return static_cast<double>(randomInt()) / M;
}