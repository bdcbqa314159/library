#ifndef DYNAMICPROG_H
#define DYNAMICPROG_H

#include <vector>

class FibonacciAlgorithm
{
    std::vector<int> memoizeTable;

public:
    FibonacciAlgorithm();
    int fibonacciAlgorithm(int n);
};

class Knapsack
{
    int numOfItems;
    int capacityOfKnapsack;
    std::vector<std::vector<int>> knapsackTable;
    int totalBenefit = 0;
    std::vector<int> weights;
    std::vector<int> values;

public:
    Knapsack(int numOfItems, int capacityOfKnapsack, const std::vector<int> &weights, const std::vector<int> &values);
    void operator()();
    void showResults();
};

#endif