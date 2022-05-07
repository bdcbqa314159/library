#include <cppTutorial2>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    Heap heap{};

    heap.insert(10);
    heap.insert(-9);
    heap.insert(-1);
    heap.insert(100);
    heap.insert(40);
    heap.insert(2);
    heap.insert(90);
    heap.insert(56);

    heap.heapsort();

    return 0;
}