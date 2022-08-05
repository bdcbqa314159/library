#ifndef HEAPS_H
#define HEAPS_H
#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Heap
{
public:
    vector<int> v;

    Heap(int size = 10)
    {
        v.reserve(size + 1);
        v.push_back(-1);
    }

    ~Heap()
    {
    }

    void push(int data)
    {
        v.push_back(data);
        int index = v.size() - 1;
        int parent = index / 2;

        while (index > 1 && v[index] < v[parent])
        {
            swap(v[index], v[parent]);
            index = parent;
            parent /= 2;
        }
        return;
    }

    int top()
    {
        return v[1];
    }

    void hepify(int i)
    {
        int l = 2 * i, r = 2 * i + 1;

        int minIdx = i;
        if (l < v.size() && v[l] < v[i])
        {
            minIdx = l;
        }
        if (r < v.size() && v[r] < v[minIdx])
        {
            minIdx = r;
        }

        if (minIdx != i)
        {
            swap(v[i], v[minIdx]);
            hepify(minIdx);
        }
    }

    void pop()
    {
        int idx = v.size() - 1;
        swap(v[1], v[idx]);
        v.pop_back();
        hepify(1);
        return;
    }

    bool empty()
    {
        return v.size() == 1;
    }
};

class Car
{
public:
    string id;
    int x, y;
    Car(string id, int x, int y) : id(id), x(x), y(y)
    {
    }
    int dist() const
    {
        return x * x + y * y;
    }
};

class CarCompare
{

public:
    bool operator()(const Car a, const Car b)
    {
        return a.dist() < b.dist();
    }
};

bool DistCompare(const Car a, const Car b)
{
    return a.dist() < b.dist();
}

void printNearestCars(vector<Car> &cars, int k)
{
    // Max heap of size k
    priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k);

    for (int i = k; i < cars.size(); i++)
    {
        auto car = cars[i];
        if (car.dist() < max_heap.top().dist())
        {
            max_heap.pop();
            max_heap.push(car);
        }
    }

    vector<Car> output;
    while (!max_heap.empty())
    {
        output.push_back(max_heap.top());
        max_heap.pop();
    }

    sort(output.begin(), output.end(), DistCompare);

    for (auto x : output)
        cout << x.id << " " << endl;

    cout << endl;

    return;
}

#endif