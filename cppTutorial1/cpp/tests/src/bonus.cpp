#include <iostream>
#include <iomanip>

using namespace std;

class Animal
{
public:
    virtual void speak() = 0;
    virtual ~Animal()
    {
    }
};

class Cat : public Animal
{
public:
    void speak() override
    {
        cout << "RrrrrRRRrrrr" << endl;
    }
    virtual ~Cat()
    {
    }
};

class HouseCat : public Cat
{
public:
    void speak() override
    {
        cout << "Meouwww" << endl;
    }

    virtual ~HouseCat()
    {
    }
};

int main()
{
    int value = 8;

    cout << "postfix: value -> value++ -> value:" << endl;
    cout << value << endl;
    cout << value++ << endl;
    cout << value << endl;

    int test = 7;
    cout << "prefix: test -> ++test -> test:" << endl;

    cout << test << endl;
    cout << ++test << endl;
    cout << test << endl;

    cout << "Polymorphism!" << endl;

    Animal *pAnimal = new Cat;
    pAnimal->speak();

    pAnimal = nullptr;
    pAnimal = new HouseCat;
    pAnimal->speak();

    delete pAnimal;

    return 0;
}