#include <cppTutorial2>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    StackArray<string> stack;

    stack.push("Adam");
    stack.push("Joe");

    cout << stack.size() << endl;
    cout << stack.pop() << endl;
    cout << stack.size() << endl;
    cout << stack.pop() << endl;

    StackLinkedList<int> stack1;
    stack1.push(10);
    stack1.push(3);

    cout << stack1.size() << endl;
    cout << stack1.pop() << endl;
    cout << stack1.size() << endl;
    cout << stack1.pop() << endl;

    return 0;
}