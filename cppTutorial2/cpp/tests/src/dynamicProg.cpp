#include <cppTutorial2>
#include <iostream>

using namespace std;

void fibonacciDP();

int main()
{
    int numOfItems = 3;
    int capacityOfKnapsack = 5;

    vector<int> weightOfItems = {0, 4, 2, 3};
    vector<int> profitOfItems = {0, 10, 4, 7};

    Knapsack knapsack(numOfItems, capacityOfKnapsack, weightOfItems, profitOfItems);
    knapsack();
    knapsack.showResults();

    return 0;
}

void fibonacciDP()
{
    cout << "Testing Fibonacci naive vs dynamic programming" << endl;

    cout << "fibonacci no. 60 dp:" << endl;
    FibonacciAlgorithm fib;
    cout << fib.fibonacciAlgorithm(70) << endl;
    cout << "fibonacci no. 60 naive:" << endl;
    cout << fibonacci(60) << endl;
    cout << "fibonacci Tail, no.60:" << endl;
    cout << fibonacciTail(60, 0, 1) << endl;
}