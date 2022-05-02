#ifndef CAT_H
#define CAT_H

class Cat
{
    bool happy;

public:
    Cat();
    ~Cat();
    void makeHappy();
    void makeSad();
    void speak();
    void jump();
};

namespace bdcb
{
    class Cat
    {
    public:
        Cat();
        ~Cat();
        void speak() const;
    };

}

#endif