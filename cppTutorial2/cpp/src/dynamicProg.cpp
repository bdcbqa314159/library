#include "../include/cppTutorial2_bits/dynamicProg.hpp"
#include <algorithm>
#include <iostream>

FibonacciAlgorithm::FibonacciAlgorithm()
{
    memoizeTable.resize(100);
    memoizeTable[0] = 0;
    memoizeTable[1] = 1;
}

int FibonacciAlgorithm::fibonacciAlgorithm(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (memoizeTable[n] != 0)
        return memoizeTable[n];
    else
    {
        memoizeTable[n] = fibonacciAlgorithm(n - 1) + fibonacciAlgorithm(n - 2);
        return memoizeTable[n];
    }
}

Knapsack::Knapsack(int numOfItems, int capacityOfKnapsack, const std::vector<int> &weights, const std::vector<int> &values) : numOfItems(numOfItems), capacityOfKnapsack(capacityOfKnapsack), weights(weights), values(values)
{
    knapsackTable.resize(numOfItems + 1);
    for (auto &item : knapsackTable)
        item.resize(capacityOfKnapsack + 1);
}

void Knapsack::operator()()
{
    for (int i = 1; i < numOfItems + 1; i++)
    {
        for (int w = 1; w < capacityOfKnapsack + 1; w++)
        {
            int notTakingItem = knapsackTable[i - 1][w];
            int takingItem = 0;
            if (weights[i] <= w)
                takingItem = values[i] + knapsackTable[i - 1][w - weights[i]];
            knapsackTable[i][w] = std::max(notTakingItem, takingItem);
        }
    }
    totalBenefit = knapsackTable[numOfItems][capacityOfKnapsack];
}

void Knapsack::showResults()
{
    std::cout << "Total benefit: " << totalBenefit << std::endl;
    for (int n = numOfItems, w = capacityOfKnapsack; n > 0; --n)
    {
        if (knapsackTable[n][w] != 0 && knapsackTable[n][w] != knapsackTable[n - 1][w])
        {
            std::cout << "We take item #" << n << std::endl;
            w -= weights[n];
        }
    }
}
