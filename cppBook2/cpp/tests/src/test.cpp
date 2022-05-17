#include <cppBook2>
#include <iostream>
#include <vector>

using namespace std;

void test()
{
    message();
}

void collatz(int n)
{
    while (true)
    {
        std::cout << n << " ";
        if (n == 1)
            break;
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
    }
}

int main()
{
    test();
    int n;
    cin >> n;
    collatz(n);
    cout << "\n";
    return 0;
}
