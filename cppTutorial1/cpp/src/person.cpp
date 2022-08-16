#include "../include/cppTutorial1_bits/person.hpp"
#include <iostream>
#include <sstream>

Person::Person() : name("undefined"), age(0)
{
}

Person::Person(std::string name) : name(name), age(0)
{
}

Person::Person(const Person &other)
{
    name = other.name;
    age = other.age;
}

Person::Person(std::string name, int age) : name(name), age(age)
{
}

Person::~Person()
{
}

bool Person::operator<(const Person &other) const
{
    if (name == other.name)
        return age < other.age;
    else
        return name < other.name;
}

std::string Person::toString() const
{
    std::stringstream ss;
    ss << "Person name : " << name << std::endl
       << "Age : " << age << std::endl;
    std::string info = ss.str();
    return info;
}

void Person::setName(std::string name)
{
    this->name = name;
}

std::string Person::getName()
{
    return name;
}