#include <cppDSA>
#include <iostream>

using namespace std;

int main()
{
    Queue<int> queueInt = Queue<int>();
    queueInt.Enqueue(35);
    queueInt.Enqueue(91);
    queueInt.Enqueue(26);
    queueInt.Enqueue(78);
    queueInt.Enqueue(44);
    queueInt.Enqueue(12);

    while (!queueInt.IsEmpty())
    {
        cout << queueInt.Front() << " - ";
        queueInt.Dequeue();
    }
    cout << "END" << endl;

    return 0;
}