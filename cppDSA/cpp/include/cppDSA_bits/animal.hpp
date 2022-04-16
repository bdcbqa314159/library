#include <string>
#include <iostream>
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{

protected:
    std::string name;

public:
    Animal(std::string name) : name(name)
    {
    }

    // void GiveName(std::string name)
    // {
    //     this->name = name;
    // }

    virtual std::string MakeSound() = 0;

    std::string GetName()
    {
        return name;
    }
};

class Dog : public Animal
{

public:
    Dog(std::string name) : Animal(name)
    {
    }

    void operator=(const Dog &D)
    {
        name = D.name;
    }

    std::string MakeSound() override
    {
        return "Woof-woooof!";
    }
};

class Cat : public Animal
{

public:
    Cat(std::string name) : Animal(name)
    {
    }

    void operator=(const Cat &C)
    {
        name = C.name;
    }

    std::string MakeSound() override
    {
        return "Meowwwww-meow!";
    }
};

template <typename T>
void GetNameAndMakeSound(T &theAnimal)
{
    std::cout << theAnimal.GetName() << " goes ";
    std::cout << theAnimal.MakeSound() << std::endl;
}

template <typename T>
class AnimalTemplate
{

private:
    T animal;

public:
    AnimalTemplate(T animal) : animal(animal)
    {
    }

    void GetNameAndMakeSound()
    {
        std::cout << animal.GetName() << " goes ";
        std::cout << animal.MakeSound() << std::endl;
    }
};

#endif