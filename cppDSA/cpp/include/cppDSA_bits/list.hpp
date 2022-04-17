#ifndef LIST_H
#define LIST_H

class List
{

private:
    int count;
    int *items;

public:
    List();
    ~List();
    int Get(int index);
    void Insert(int index, int val);
    int Search(int val);
    void Remove(int index);
    int Count();
};

#endif