#include "../include/cppTutorial1_bits/person.hpp"
#include <iostream>
#include <sstream>

Person::Person() : name("undefined"), age(0)
{
}

Person::Person(std::string name) : name(name), age(0)
{
}

Person::Person(std::string name, int age) : name(name), age(age)
{
}

Person::~Person()
{
}

std::string Person::toString()
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