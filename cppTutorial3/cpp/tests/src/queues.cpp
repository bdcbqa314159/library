#include <cppTutorial3>
#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

void testingQueues()
{
    Queue myQueue(7);

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    myQueue.push(6);
    myQueue.push(7);
    myQueue.push(8);
    myQueue.pop();
    myQueue.pop();
    myQueue.push(9);

    while (!myQueue.empty())
    {
        cout << myQueue.getFront() << endl;
        myQueue.pop();
    }

    return;
}

void testingSTLQueues()
{
    cout << "Queues with STL:" << endl;
    queue<int> q;
    for (int i = 1; i <= 10; i++)
        q.push(i);

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return;
}

int main()
{
    testingQueues();
    testingSTLQueues();
    return 0;
}