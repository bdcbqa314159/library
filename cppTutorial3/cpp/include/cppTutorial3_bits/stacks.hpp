#ifndef STACKS_H
#define STACKS_H

#include "./nodes.hpp"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Stack
{
public:
    Node *top;
    int size;

    Stack() : top(0), size(0)
    {
    }

    void push(int data)
    {
        Node *node = new Node(data);
        node->next = top;
        top = node;
        size++;
    }

    int giveTop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }

        return top->data;
    }

    void pop()
    {
        if (isEmpty())
        {
            return;
        }

        Node *node = top;
        top = top->next;
        node->next = nullptr;
        delete node;
        size--;
        return;
    }

    int giveSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    ~Stack()
    {
        delete top;
    }
};

class StackV
{

public:
    vector<int> arr;

    void push(int data)
    {
        arr.push_back(data);
    }

    void pop()
    {
        arr.pop_back();
    }

    int top()
    {
        return arr[arr.size() - 1];
    }

    bool isEmpty()
    {
        return arr.size() == 0;
    }
};

class StackQ
{
public:
    queue<int> q1, q2;
    void push(int x)
    {
        if (!q1.empty())
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
        }
        return;
    }

    void pop()
    {
        if (q1.empty())
        {
            while (!q2.empty())
            {
                int front = q2.front();
                q2.pop();

                if (q2.empty())
                    break;

                q1.push(front);
            }
        }

        else
        {
            while (!q1.empty())
            {
                int front = q1.front();
                q1.pop();

                if (q1.empty())
                    break;

                q2.push(front);
            }
        }
        return;
    }

    int top()
    {
        int front = 0;
        if (q1.empty())
        {
            while (!q2.empty())
            {
                front = q2.front();
                q2.pop();
                q1.push(front);
                if (q2.empty())
                    break;
            }
        }

        else
        {
            while (!q1.empty())
            {
                front = q1.front();
                q1.pop();
                q2.push(front);
                if (q1.empty())
                    break;
            }
        }
        return front;
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

#endif