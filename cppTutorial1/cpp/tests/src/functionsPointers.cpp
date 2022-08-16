#include <cppTutorial1>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void test()
{
    cout << "Hello!" << endl;
}

void test1(int value)
{
    cout << "Hello! version " << value << endl;
}

void funcPointers1()
{
    cout << "Functions pointers." << endl;

    test();
    // Pointer to test?
    // void (*pTest)();

    // pTest = &test;
    // cout << "Calling test with a function pointer." << endl;
    // (*pTest)();

    // All we need: the name of a function is a pointer to a function so:

    void (*pTest)() = test;
    cout << "Calling test with a function pointer." << endl;
    pTest();

    void (*pTest1)(int) = test1;
    cout << "Calling test with a function pointer with params." << endl;
    pTest1(8);
}

bool match(string test)
{
    return test.size() == 3;
}

int countStrings(vector<string> &texts, bool (*f)(string))
{
    int answer = 0;
    for (int i = 0; i < texts.size(); i++)
    {
        if (f(texts[i]))
            answer++;
    }
    return answer;
}

void funcPointers2()
{
    vector<string> texts;

    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("four");
    texts.push_back("two");
    texts.push_back("three");

    cout << match("one") << endl;

    // Super cool feature:
    cout << "Using count_if and function pointers" << endl;
    cout << count_if(texts.begin(), texts.end(), match) << endl;

    cout << "Using my own version of count_if and function pointers" << endl;
    cout << countStrings(texts, match) << endl;
}

class Parent
{
    int one;

public:
    Parent() : one(0)
    {
    }

    Parent(const Parent &p) : one(p.one)
    {
    }

    virtual void print()
    {
        cout << "parent" << endl;
    }

    virtual ~Parent()
    {
    }
};

class Child : public Parent
{
    int two;

public:
    Child() : Parent(), two(0)
    {
    }

    void print()
    {
        cout << "child" << endl;
    }
};

void slicingObjects()
{
    Child c1;
    Parent &p1 = c1;

    p1.print();

    Parent p2 = Child(); // Object slicing

    p2.print();
}

class Animal
{
public:
    virtual void run() = 0;
    virtual void speak() = 0;
};

class Wolf : public Animal
{
public:
    virtual void speak()
    {
        cout << "ouuuuuh" << endl;
    }
};

class EuropeanWolf : public Wolf
{

public:
    virtual void run()
    {
        cout << "euro Wolf running" << endl;
    }
};

class Tiger : public Animal
{

public:
    virtual void speak()
    {
        cout << "RRRRROARRR" << endl;
    }
};

class JungleTiger : public Tiger
{
public:
    virtual void run()
    {
        cout << "Running in the jungle" << endl;
    }
};

void testingSpeak(Animal &a)
{
    a.speak();
    a.run();
}

void abstractClasses()
{

    Animal *animals[5];

    for (int i = 0; i < 5; i++)
    {
        if (i % 2 == 0)
        {
            JungleTiger tiger;
            animals[i] = &tiger;
        }

        else
        {
            EuropeanWolf wolf;
            animals[i] = &wolf;
        }
    }
    cout << "-----------------------------" << endl;
    cout << "Playing with wirtual classes" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        animals[i]->speak();
    }

    cout << "-----------------------------" << endl;
    cout << "Playing with wirtual classes and functions" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        testingSpeak(*animals[i]);
    }
}

struct GeneralTest
{

    virtual bool operator()(string &test) = 0;
    virtual ~GeneralTest(){};
};

struct MatchTest : public GeneralTest
{

    virtual bool operator()(string &text)
    {
        return text == "lion";
    }
};

void check(string text, GeneralTest &test)
{
    if (test(text))
    {
        cout << "Matching text!" << endl;
    }
    else
        cout << "No match." << endl;
}

int main()
{

    cout << "Working with functors." << endl;
    MatchTest pred;
    string value = "lion";
    cout << pred(value) << endl;

    check("liond", pred);
    check("lion", pred);

    return 0;
}
