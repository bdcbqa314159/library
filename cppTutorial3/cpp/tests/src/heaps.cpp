#include <cppTutorial3>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;
// Input 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

class Compare2
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

void testingHeaps()
{
    int arr[] = {10, 15, 20, 14, 6, 90};

    int n = sizeof(arr) / sizeof(int);

    priority_queue<int, vector<int>, greater<int>> heap; // Min heap
    // priority_queue<int> heap; Max heap

    for (int x : arr)
        heap.push(x);

    cout << "STL priority queue: " << endl;
    while (!heap.empty())
    {
        cout << heap.top() << endl;
        heap.pop();
    }

    Heap myHeap;
    for (int x : arr)
        myHeap.push(x);

    cout << "My priority min queue: " << endl;
    while (!myHeap.empty())
    {
        cout << myHeap.top() << endl;
        myHeap.pop();
    }

    return;
}

void testingNearestCars()
{
    int N, K;
    cin >> N >> K;

    string id;
    int x, y;
    vector<Car> cars;

    for (int i = 0; i < N; i++)
    {
        cin >> id >> x >> y;
        Car car(id, x, y);
        cars.push_back(car);
    }
    cout << "Nearest cabs:" << endl;
    printNearestCars(cars, K);
}

int main()
{
    testingHeaps();
    testingNearestCars();
    return 0;
}