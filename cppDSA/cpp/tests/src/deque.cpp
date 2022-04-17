#include <cppDSA>
#include <iostream>

using namespace std;

int main()
{
    Deque<int> deque = Deque<int>();
    deque.EnqueueFront(26);
    deque.EnqueueBack(78);
    deque.EnqueueBack(44);
    deque.EnqueueFront(91);
    deque.EnqueueFront(35);
    deque.EnqueueBack(12);

    while (!deque.IsEmpty())
    {
        cout << deque.Back() << " - ";
        deque.DequeueBack();
    }
    cout << "END" << endl;
    return 0;
}