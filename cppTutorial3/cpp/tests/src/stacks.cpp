#include <cppTutorial3>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void insertAtBottom(stack<int> &s, int data)
{

    stack<int> temp;
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(data);
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

void insertAtBottomV2(stack<int> &s, int data)
{
    if (s.empty())
    {
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottomV2(s, data);
    s.push(temp);
}

void reverse(stack<int> &s)
{
    if (s.empty())
        return;
    int t = s.top();
    s.pop();
    reverse(s);
    insertAtBottomV2(s, t);
}

void testingStacks()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    while (!st.isEmpty())
    {
        cout << st.giveTop() << endl;
        st.pop();
    }

    return;
}

void testingStacksSTL()
{
    stack<string> books;
    books.push("C++");
    books.push("Java");
    books.push("Python");
    books.push("OS");

    while (!books.empty())
    {
        cout << books.top() << endl;
        books.pop();
    }
}

void testingStackQ()
{
    StackQ s;
    s.push(1);
    s.push(2);
    s.pop();
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.pop();

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

int main()
{
    // testingStacks();
    // testingStacksSTL();
    testingStackQ();
    return 0;
}