#include <cppTutorial4>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Parent{
public:
    virtual void f(){
        cout<<"from parent"<<endl;
    }
};

class Child:public Parent{
public:
    virtual void f(){
        cout<<"from child"<<endl;
    }
};

class Animal{
public:
    virtual void speak() =0;
    virtual ~Animal(){
    }
};

class Cat:public Animal{

public:
    virtual void speak() override{
        cout<<"meow"<<endl;
    }
    
    ~Cat(){
        cout<<"bye meow"<<endl;
    }
    
};

class Dog:public Animal{
public:
    virtual void speak() override{
        cout<<"woof"<<endl;
    }
    
    ~Dog(){
        cout<<"bye woof"<<endl;
    }
    
};

class Shape{
    
public:
    virtual void shape()=0;
    virtual ~Shape(){}
};

class Rectangle:public Shape{
public:
    virtual void shape() override{
        cout<<"I am a rectangle"<<endl;
    }
    ~Rectangle(){
        
    }
};

class Circle:public Shape{
public:
    virtual void shape() override{
        cout<<"I am a circle"<<endl;
    }
    ~Circle(){
        
    }
};

int main()
{
    
    cout<<"Polymorpshim"<<endl;
    
    Parent *p = new Child();
    p->f();
    
    Animal *a = new Cat();
    a->speak();
    
    delete a;
    
    a = new Dog();
    a->speak();
    delete a;
    
    return 0;
}


