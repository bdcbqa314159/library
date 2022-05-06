#include <cppTutorial2>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << queue.dequeue() << endl;
    cout << queue.size() << endl;

    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.size() << endl;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << queue.dequeue() << endl;
    cout << queue.size() << endl;

    return 0;
}