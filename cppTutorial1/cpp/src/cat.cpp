#include "../include/cppTutorial1_bits/cat.hpp"
#include <iostream>

Cat::Cat()
{
    std::cout << "Cat created" << std::endl;
    happy = true;
}

Cat::~Cat()
{
    std::cout << "Cat disappearing" << std::endl;
}

void Cat::speak()
{
    if (happy)
    {
        std::cout << "Meooow :)" << std::endl;
        return;
    }

    else
    {
        std::cout << "Ssssssss :(" << std::endl;
        return;
    }
}

void Cat::jump()
{
    std::cout << "Jumping around here!" << std::endl;
}

void Cat::makeHappy()
{
    happy = true;
}

void Cat::makeSad()
{
    happy = false;
}