#include <cppTutorial2>
#include <iostream>

using namespace std;

int main()
{
    cout << "Testing tail and head recursion examples:" << endl;
    tail(10);
    cout << "============" << endl;
    head(10);

    cout << "Testing factorials with & without accumulator:" << endl;

    cout << "5! = " << factorial(5) << endl;
    cout << "5! = " << factorialAccumulator(5, 1) << endl;

    cout << "12! = " << factorial(12) << endl;
    cout << "12! = " << factorialAccumulator(12, 1) << endl;

    cout << "Testing Fibonacci numbers:" << endl;
    cout << "Fibonacci(10) = " << fibonacci(10) << endl;
    cout << "FibonacciTail(10) = " << fibonacciTail(10, 0, 1) << endl;

    cout << "Testing Hanoi Tower solution: " << endl;
    hanoiSolve(3, 'A', 'B', 'C');

    return 0;
}