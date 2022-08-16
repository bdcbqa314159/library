#include <cppTutorial1>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

void vectors()
{

    vector<string> strings(5);

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    strings[3] = "dog";

    cout << strings[3] << endl;

    cout << strings.size() << endl;

    cout << "----With auto------" << endl;
    for (auto &s : strings)
    {
        cout << s << endl;
    }

    cout << "----With iterator------" << endl;

    vector<string>::iterator it = strings.begin();
    for (; it != strings.end(); it++)
    {
        cout << *it << endl;
    }

    cout << "----With the indices------" << endl;
    for (int i = 0; i < strings.size(); i++)
    {
        cout << strings[i] << endl;
    }

    cout << "Creating a vector of doubles: vector<double> numbers(20, 0.9)" << endl;
    vector<double> numbers(20, 0.9);
    cout << "Size:" << endl;
    cout << numbers.size() << endl;
    cout << "Capacity:" << endl;
    cout << numbers.capacity() << endl;

    cout << "evolution of the vector's capacity:" << endl;
    for (int i = 0; i < 20; i++)
    {
        numbers.push_back(23);
        cout << numbers.capacity() << endl;
    }

    // numbers.clear() cleans the vector and size as well
    // numbers.reserve(100) fixes the capacity
    // numbers.resize(3000)

    vector<vector<double>> grid(3, vector<double>(4, 7));

    cout << "Grid with vectors:" << endl;

    grid[1].resize(13);

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void lists()
{
    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    cout << "Working with linked list:" << endl;
    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it << endl;
    }

    numbers.push_front(12);
    numbers.push_front(122);
    numbers.push_front(244);

    cout << "Pushing at front" << endl;

    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it << endl;
    }

    list<int>::iterator it = numbers.begin();

    numbers.insert(it, 3405);

    cout << "Inserting with insert:" << endl;
    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it << endl;
    }

    cout << "Erasing third element" << endl;

    list<int>::iterator erase = numbers.begin();
    for (int i = 0; i < 3; i++)
        erase++;

    erase = numbers.erase(erase);

    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it << endl;
    }

    cout << "Playing with erase and insert" << endl;
    for (auto it = numbers.begin(); it != numbers.end();)
    {
        if (*it == 2)
            numbers.insert(it, 1234);
        if (*it == 244)
            it = numbers.erase(it);
        else
            it++;
    }

    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it << endl;
    }
}

void maps()
{

    map<string, int> ages;
    ages["Mike"] = 40;
    ages["Peter"] = 23;
    ages["Marya"] = 32;

    cout << "=============" << endl;
    cout << "Looping with iterators" << endl;
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
        cout << "Name:" << it->first << " -- Age: " << it->second << endl;

    cout << endl;
    if (ages.find("Marya") != ages.end())
        cout << "Marya is found!" << endl;
    else
        cout << "Marya not found." << endl;

    cout << endl;
    if (ages.find("Pedro") != ages.end())
        cout << "Pedro is found!" << endl;
    else
        cout << "Pedro not found." << endl;

    cout << "=============" << endl;
    cout << "Looping with pairs" << endl;
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {

        pair<string, int> age = *it;

        cout << "Name:" << age.first << " -- Age: " << age.second << endl;
    }

    cout << "=============" << endl;
    cout << "Inserting stuff" << endl;

    ages.insert(pair<string, int>("Gail", 100));
    ages.insert(make_pair("Luis", 24));

    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {

        pair<string, int> age = *it;

        cout << "Name:" << age.first << " -- Age: " << age.second << endl;
    }

    cout << "=============" << endl;
    cout << "With custom objects" << endl;
    map<int, Person> people;

    people[0] = Person("Mike", 40);
    people[1] = Person("Vicky", 30);
    people[2] = Person("Mike", 20);

    for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++)
    {

        cout << "id:" << it->first << " -- Name: " << it->second.toString() << endl;
    }

    cout << "=============" << endl;
    cout << "With custom objects as keys!" << endl;

    map<Person, int> people2;

    people2[Person("Mike", 12)] = 40;
    people2[Person("Lola", 14)] = 80;
    people2[Person("oliver", 19)] = 20;

    for (map<Person, int>::iterator it = people2.begin(); it != people2.end(); it++)
    {

        cout << "Name: " << it->first.toString() << " -- id :" << it->second << endl;
    }
    // If we insert people2[Person("Mike", 1222)] = 443 will update 443 but not the 1222 if the operator< does not take into account the age.
}

void multimaps()
{
    multimap<int, string> lookup;

    lookup.insert(make_pair(30, "Mike"));
    lookup.insert(make_pair(10, "Vicky"));
    lookup.insert(make_pair(30, "Raj"));
    lookup.insert(make_pair(25, "Bob"));

    cout << "With multimap we can have the same key multiple times" << endl;
    for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }

    // Makes life easier: :o)
    // pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);
    auto its = lookup.equal_range(30);

    cout << "Looking for all the occurences" << endl;
    for (multimap<int, string>::iterator it = its.first; it != its.second; it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
}

class Test
{

    int id;
    string name;

public:
    Test() : id(0), name("")
    {
    }

    Test(int id, string name) : id(id), name(name)
    {
    }

    ~Test()
    {
    }

    Test(const Test &other)
    {
        id = other.id;
        name = other.name;
    }

    void print() const
    {
        cout << "id " << id << " --- name : " << name << endl;
    }

    bool operator<(const Test &other) const
    {
        if (name == other.name)
            return id < other.id;
        else
            return name < other.name;
    }

    string getName()
    {
        return name;
    }

    int getId()
    {
        return id;
    }

    friend bool comp(const Test &a, const Test &b);
};

void sets()
{
    set<int> numbers;

    numbers.insert(10);
    numbers.insert(50);
    numbers.insert(30);
    numbers.insert(40);

    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it << endl;
    }

    cout << "Adding another 40:" << endl;
    numbers.insert(40);

    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it << endl;
    }

    set<int>::iterator itFind = numbers.find(30);
    if (itFind != numbers.end())
    {
        cout << 30 << " found in the set" << endl;
    }

    else
    {
        cout << 30 << " not found!" << endl;
    }

    cout << "With count: " << endl;

    if (numbers.count(40))
    {
        cout << 40 << " found with .count method." << endl;
    }

    else
    {
        cout << "Not found!" << endl;
    }

    cout << "Sets with custom objects:" << endl;
    set<Test> tests;

    tests.insert(Test(10, "Mike"));
    tests.insert(Test(20, "Mk"));
    tests.insert(Test(30, "Me"));
    tests.insert(Test(40, "Mik"));
    tests.insert(Test(120, "Mik"));

    for (set<Test>::iterator it = tests.begin(); it != tests.end(); it++)
    {
        it->print();
    }
}

class Test1
{
    string name;

public:
    Test1() : name("")
    {
    }

    Test1(string name) : name(name)
    {
    }

    ~Test1()
    {
        // cout << "Fun?" << endl;
    }
    Test1(const Test1 &other)
    {
        name = other.name;
    }

    void print()
    {
        cout << name << endl;
    }
};

void stacks()
{
    stack<Test1> testStack;

    testStack.push(Test1("one"));
    testStack.push(Test1("two"));
    testStack.push(Test1("four"));
    testStack.push(Test1("five"));

    cout << "Working with stacks" << endl;

    while (!testStack.empty())
    {
        Test1 &temp = testStack.top();
        temp.print();
        testStack.pop();

        /* Bad when poping the ref is destroyed
        Test1 &temp = testStack.top();
        testStack.pop();
        temp.print();
        */
    }
}

void queues()
{
    queue<Test1> testQueue;

    testQueue.push(Test1("one"));
    testQueue.push(Test1("two"));
    testQueue.push(Test1("four"));
    testQueue.push(Test1("five"));

    cout << "Working with queues" << endl;

    while (!testQueue.empty())
    {
        Test1 &temp = testQueue.front();
        temp.print();
        testQueue.pop();
    }
}

bool comp(const Test &a, const Test &b)
{
    return a.name < b.name;
}

void sorting()
{
    vector<Test> tests;
    tests.push_back(Test(5, "Mike"));
    tests.push_back(Test(10, "Sue"));
    tests.push_back(Test(7, "Raj"));
    tests.push_back(Test(3, "Vicky"));

    sort(tests.begin(), tests.end());

    for (int i = 0; i < tests.size(); i++)
        tests[i].print();

    cout << endl;

    sort(tests.begin(), tests.end(), comp);

    /*
    Another stl class: deque => double ended queue.
    Queue with insertion in the front as well in the end.

    */
}

int main()
{
    // We can nest all the stl objects together with more complex structures.

    map<string, vector<int>> scores;

    scores["Mike"].push_back(10);
    scores["Mike"].push_back(40);
    scores["Mike"].push_back(30);

    scores["Vicky"].push_back(50);

    for (map<string, vector<int>>::iterator it = scores.begin(); it != scores.end(); it++)
    {
        string name = it->first;
        vector<int> scoreList = it->second;

        cout << name << ": " << endl;
        for (int i = 0; i < scoreList.size(); i++)
        {
            cout << scoreList[i] << " " << flush;
        }
    }

    return 0;
}