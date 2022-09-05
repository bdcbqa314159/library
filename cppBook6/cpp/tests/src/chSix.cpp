#include <cppBook6>
#include <iostream>

using namespace std;

int main()
{
    cout << "Object Orientation" << endl;

    /*
    ************************************************************************
    Object-Oriented Thinking
    Objects are cells, main questions which could be addressed:
    How do I find and form the "cells" (objects)?
    How do I design the public availbale interface of those cells?
    How do I govern who can communicate with whom (dependencies)?

    ************************************************************************
    Abstraction - the Key to Master Complexity

    First step is decomposition, these principles help to the purpose:
    Information hiding.
    Strong cohesion.
    Loose coupling.
    Single Reponsibility Principle.

    ************************************************************************
    Principles for Good Class Design

    There we will give several clues to achieve that.
    ************************************************************************

    Keep Classes Small

    The God Class Anti-Pattern

    God Classes is an anti-pattern, this kind of classes tend to become bigger and bigger and cause too many problems.

    The bottom line is keep them small and with only one responsibility.

    ************************************************************************
    Single Responsibility Principle (SRP)

    Only one task, it will help the maintenance.
    And it leads to have less dependencies.

    ************************************************************************

    Open-Closed Principle

    Open to extension but closed to modification.
    We can use inheritance to achieve that.

    ************************************************************************
    Liskov Substitution Principle (LSP)

    An example would be:
    The Square-Rectangle Dilemma
    Even if a square is a subset of a rectangle it is not a good oo design to set inheritance from rectangle to square.

    The principle is:

    Functions that use pointers or references to base classes must be able to use objects of derived classes without knowing it.

    ************************************************************************
    Final keyword
    It states the end within the chain of inheritance.

    ************************************************************************
    RUN-TIME TYPE INFORMATION (RTTI)

    In C++, the typeid operator (defined in header <typeinfo>) and dynamic_cast<T>
    belong to rtti. For instance, to determine the class of an object at runtime, you can write:

    const std::type_info& typeInformationAboutObject = typeid(instance);

    The const reference of type std::type_info (also defined in header <typeinfo>) now holds information about the object’s class, for example, the class’s name. Since C++11, a hash code is also available (std::type_info::hash_code()), which is identical for the std::type_info objects referring to the same type.

    It is important to know that rtti is available only for classes that are polymorphic.

    CAUTION: Whenever you are compelled to use rtti in your program to distinguish between different types, it is a distinct “design smell,” that is, an obvious indicator for a bad object-oriented software design!

    ************************************************************************
    Favor Composition over Inheritance

    If never we really need a class square the principle would be to make it inherit from shape but use a rectangle class as a private member as a black box.
    Composition = black box.
    Inheritance = white box.

    ************************************************************************
    Interface Segregation Principle

    The Interface Segregation Principle says that we should segregate a “fat interface” into smaller and highly cohesive interfaces. The resulting small interfaces are also referred to as role interfaces.

    ************************************************************************
    Acyclic Dependency Principle

    If take an example between classes like customer and account we could fall
    very quickly into a circular dependency which is not good.

    ************************************************************************
    Dependency Inversion Principle (DIP)

    The first step is that we no longer allow one of the two classes to have direct access to the other class.

    Bob's statements on this matter:

    A. High-level modules should not depend on low-level modules. Both should depend on abstractions.

    B. Abstractions should not depend on details. Details should depend on abstractions.

    Note: The terms “high-level modules” and “low-level modules” in this quote can
    be misleading. they refer not necessarily to their conceptual position within
    a layered architecture. a high-level module in this particular case is a software
    module that requires external services from another module, the so-called
    low-level module. high-level modules are those where an action is invoked,
    low-level modules are the ones where the action
    is performed. in some cases, these two categories of modules may also be located
    on different levels of a software architecture (e.g., layers), or as in our
    example in different components.

    ************************************************************************
    Don't Talk to Strangers (Law of Demeter)

    This principle states that you should do shy programming, and the goal is to govern the communication structure within an object-oriented design.

    We have the following rules:

    A member function is allowed to call other member functions in its own class scope directly.

    A member function is allowed to call member functions on member variables that are in its class scope directly.

    If a member function has parameters, the member function is allowed to call the member functions of these parameters directly.

    If a member function creates local objects, the member function is allowed to call member functions on those local objects.

    If one of these four aforementioned kinds of member function calls returns an object that is structurally farther distant than the immediate neighbors of the class, it is forbidden to call a member function on those objects.

    ************************************************************************
    Avoid Anemic Classes

    We are talking about objects used as bags for a bunch of data. This is just procedural programming with data structures, and it has nothing to do with object orientation.

    ************************************************************************
    Tell Don't Ask

    The principle Tell Don’t Ask reminds us that we should not ask an object to release information about its internal state and to decide outside of this object what to do, if this object would be able to decide it on its own. Basically, this principle reminds us that in Object Orientation, data, and the operations operating on these data, are to be combined to cohesive units.

    ************************************************************************
    Avoid Static Class Members

    We are talking about the Junk Shop Anti-Pattern.

    We must avoid static member variables respectively and member functions largely.
    One exception from this rule are private constants of a class, because they are read-only and do not represent an object’s state. Another exception are factory methods, that is, static member functions that create instances of an object, usually instances of the class type that serves also as the namespace of the static member function.














































    */

    return 0;
}
