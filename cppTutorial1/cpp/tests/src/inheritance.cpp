#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    void speak() const
    {
        cout << "Grrrr" << endl;
    }
};

class Cat : public Animal
{
public:
    void jump() const
    {
        cout << "I am jumping" << endl;
    }
};

class Tiger : public Cat
{
public:
    void attackAntelope()
    {
        cout << "Attacking!" << endl;
    }
};

class Frog
{
private:
    string name;
    string getName() const
    {
        return name;
    }

public:
    Frog(string name) : name(name)
    {
    }

    void speak() const
    {
        cout << "My name is " << getName() << " and kroak!" << endl;
    }
};

class Machine
{
private:
    int id;

public:
    Machine() : id(0)
    {
        cout << "Machine no argument constructor called" << endl;
    }
    Machine(int id) : id(id)
    {
        cout << "Machine with id constructor called" << endl;
    }
    void info() const
    {
        cout << "ID: " << id << endl;
    }
};

class Vehicle : public Machine
{
public:
    Vehicle() { cout << "Vehicle" << endl; }
    Vehicle(int id) : Machine(id)
    {
        cout << "Vehicle with another constructor" << endl;
    }
};

class Car : public Vehicle
{
public:
    Car() : Vehicle(12345) { cout << "Car no-argument constructor called." << endl; }
};

int main()
{

    cout << "==========" << endl;
    cout << "Working with inheritance" << endl;
    Animal a;
    a.speak();

    Cat b;
    b.speak();
    b.jump();

    Tiger t;
    t.speak();
    t.jump();
    t.attackAntelope();
    cout << endl;
    cout << "==========" << endl;
    cout << "Encapsulation" << endl;
    Frog frog("Freddy");
    frog.speak();

    cout << "==========" << endl;
    cout << "Constructor & inheritance" << endl;

    Vehicle vehicle;
    vehicle.info();

    Vehicle vehicle1(23);
    vehicle1.info();

    Car car;
    car.info();

    return 0;
}
