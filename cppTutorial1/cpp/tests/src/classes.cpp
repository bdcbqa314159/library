#include <iostream>
#include <cppTutorial1>

using namespace std;

void workingWithCats();
void workingWithPersons();
void workingWithPersons2();

int main()
{
    workingWithCats();
    workingWithPersons();
    workingWithPersons2();

    return 0;
}

void workingWithCats()
{
    cout << "Testing..." << endl;
    Cat cat;
    cat.makeHappy();
    cat.speak();
    cat.jump();
    {
        Cat bob;
        bob.makeSad();
        bob.speak();
    }

    cout << "Ending program" << endl;
}

void workingWithPersons()
{
    cout << endl;
    cout << "Testing ..." << endl;
    Person person;
    cout << person.toString() << endl;
    person.setName("Charles");
    cout << person.toString() << endl;
    cout << "Get name with getter..." << endl;
    cout << "This object has the name : " << person.getName() << endl;
    cout << endl;
    Person person1("Bob");
    cout << person1.toString() << endl;

    Person person2("Sue", 100);
    cout << person2.toString() << endl;
}

void workingWithPersons2()
{
    cout << "Testing ..." << endl;
    Person person;
    cout << person.toString() << "Memory location: " << &person << endl;
    Person *memLoc = person.getMemoryLocation();
    cout << "Giving the memory location with getMemoryLocation(): " << endl;
    cout << memLoc << endl;
}