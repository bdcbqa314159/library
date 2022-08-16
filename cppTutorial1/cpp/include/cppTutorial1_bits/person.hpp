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
    Person(const Person &other);
    Person(std::string name);
    Person(std::string name, int age);
    bool operator<(const Person &other) const;
    ~Person();

    std::string toString() const;
    void setName(std::string name);
    std::string getName();
    Person *getMemoryLocation()
    {
        return this;
    }
};

#endif