#include <cppTutorial3>
#include <iostream>

using namespace std;

void testingFactorial()
{
    cout << "Testing factorial" << endl;
    int n;
    cout << "Give a positive value >> ";
    cin >> n;
    cout << n << "! = " << factorial(n) << endl;
}

void testingFibonacci()
{
    cout << "Testing fibonacci" << endl;
    int n;
    cout << "Give a positive value >> ";
    cin >> n;
    cout << "fib(" << n << ") = " << fibonacci(n) << endl;
}

void testingIsSorted()
{
    int a[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Is sorted: " << isSorted(a, 5);
    cout << endl;

    int b[] = {1, 8, 3, 4, 9};
    for (int i = 0; i < 5; i++)
        cout << b[i] << " ";
    cout << endl;
    cout << "Is sorted: " << isSorted(b, 5);
    cout << endl;
}

void testingDecreasing()
{
    int n;
    cout << "give a number >>";
    cin >> n;
    dec(n);
    cout << endl;
}

void testingIncreasing()
{
    int n;
    cout << "give a number >>";
    cin >> n;
    inc(n);
    cout << endl;
}

void testingFirstOcc()
{

    int a[] = {1, 2, 3, 4, 5, 45, 12, 33, 667, 12, 6, 8};
    // for (int i = 0; i < 12; i++)
    //     cout << a[i] << " ";
    int key = 5;
    int n = sizeof(a) / sizeof(int);
    cout << endl;
    cout << "first occurence for " << key << ": " << firstOcc(a, n, key);
    cout << endl;
}

void testingLastOcc()
{

    int a[] = {1, 3, 5, 8, 7, 6, 2, 11, 21};
    // for (int i = 0; i < 12; i++)
    //     cout << a[i] << " ";
    int key = 7;
    int n = sizeof(a) / sizeof(int);
    cout << endl;
    cout << "last occurence for " << key << ": " << lastOcc(a, n, key);
    cout << endl;
}

void testingPower()
{
    int a = 4;
    int n = 5;

    cout << a << "^" << n << "=" << power(a, n) << endl;

    cout << a << "^" << n + 3 << "=" << power(a, n + 3) << endl;
}

void testingNumberSpeller()
{
    int n;
    cout << "Give a number >>";
    cin >> n;
    cout << "Number : " << n << endl;
    cout << "And its spelling:" << endl;
    numberSpell(n);
    cout << endl;
}

int main()
{

    cout << "Hey recurion" << endl;
    // testingFactorial();
    // testingFibonacci();
    // testingIsSorted();

    // cout << endl
    //      << endl;
    // testingIncreasing();
    // testingDecreasing();

    // testingFirstOcc();
    // testingLastOcc();
    // testingPower();

    testingNumberSpeller();
    return 0;
}