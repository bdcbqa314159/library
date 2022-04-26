#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
private:
    std::string name;
    int age;

public:
    Person();
    Person(std::string name);
    Person(std::string name, int age);
    ~Person();

    std::string toString();
    void setName(std::string name);
    std::string getName();
    Person *getMemoryLocation()
    {
        return this;
    }
};

#endif