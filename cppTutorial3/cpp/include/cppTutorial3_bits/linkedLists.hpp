#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include "./nodes.hpp"

class List
{
public:
    Node *head;
    Node *tail;
    int size;

    List() : head(nullptr), tail(nullptr), size(0)
    {
    }

    ~List()
    {
        if (!head)
            delete head;
    }

    void push_front(int data)
    {
        if (!head)
        {
            Node *node = new Node(data);
            head = tail = node;
        }
        else
        {
            Node *node = new Node(data);
            node->next = head;
            head = node;
        }
        size++;
    }

    void push_back(int data)
    {
        if (!head)
        {
            Node *node = new Node(data);
            head = tail = node;
        }
        else
        {
            Node *node = new Node(data);
            tail->next = node;
            tail = node;
        }
        size++;
    }

    void show()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "X" << endl;
    }

    void insert(int data, int position)
    {
        if (position < 0 || position > size)
            return;

        if (position == 0)
        {
            push_front(data);
            return;
        }

        Node *temp = head;
        for (int i = 1; i <= position - 1; i++)
            temp = temp->next;

        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

    int search(int key)
    {
        Node *temp = head;
        int idx = 0;

        while (temp)
        {
            if (temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    int searchHelper(Node *start, int key)
    {
        if (!start)
            return -1;
        if (start->data == key)
            return 0;
        int subIdx = searchHelper(start->next, key);
        if (subIdx == -1)
            return -1;
        else
            return subIdx + 1;
    }

    int recursiveSearch(int key)
    {
        int idx = searchHelper(head, key);
        return idx;
    }

    void pop_front()
    {
        if (!head)
            return;
        Node *temp = head;

        head = temp->next;
        temp->next = nullptr;
        delete temp;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = head->next;

        while (current)
        {
            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;
    }
};

#endif