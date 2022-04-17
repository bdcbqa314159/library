#include <cppDSA>
#include <iostream>

using namespace std;

int main()
{
    Stack<int> stackInt = Stack<int>();

    stackInt.Push(32);
    stackInt.Push(47);
    stackInt.Push(18);
    stackInt.Push(59);
    stackInt.Push(88);
    stackInt.Push(91);

    while (!stackInt.IsEmpty())
    {
        cout << stackInt.Top() << " - ";
        stackInt.Pop();
    }

    cout << "END" << endl;

    return 0;
}