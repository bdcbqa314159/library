#include <cppBook6>
#include <iostream>

using namespace std;

int main()
{
    cout << "Design Patterns and Idioms" << endl;

    /*
    ************************************************************************
    Canonical Form

    The term Canonical Form in this context describes a representation of something that is reduced to the simplest and most significant form without losing generality. Related to design patterns, the canonical form of a pattern describes its most basic elements: name, context, problem, forces, solution, examples, drawbacks, etc.

    ************************************************************************
    Design Principles vs. Design Patterns

    One simple sentence to summarize all this:
    Decisions and patterns give people solutions; principles help them design their own.

    ************************************************************************
    Some Patterns, and When to Use Them

    WARNING: Don’t exaggerate it with the usage of design patterns! no doubt, design patterns are cool and sometimes even fascinating. But an overplayed use of them, especially if there are no good reasons to justify it, can have catastrophic consequences. Your software design will suffer from useless overengineering. always remember Kiss and Yagni

    ************************************************************************
    Dependency Injection (DI)

    Before to introuduce it we will discuss about an anti-pattern: The singleton.

    ************************************************************************
    The Singleton Anti-Pattern
    ************************************************************************
    A Singleton in OO is like a global variable in procedural programming.
    If they are so bad the perhaps surprisingly simple answer, which of course requires some further explanations, is this: Just create one, and inject it everywhere its needed!

    ************************************************************************
    Dependency Injection to the Rescue

    Basically, Dependency Injection (DI) is a technique in which the independent service objects needed by a dependent client object are supplied from outside. The client object does not have to take care about its required service objects itself, or actively request the service objects, for example, from a
    Factory (see Factory pattern later in this chapter), or from a Service Locator.

    Decouple components from their required services in such a way that the components do not have to know the names of these services, nor how they have to be procured.

    ************************************************************************
    std::string_view [C++17]
    Objects of this class are very performant proxies (proxy is, by the way, also a design pattern) of a string, which are cheap to construct (there is no memory allocation for raw string data) and thus also cheap to copy.


    ************************************************************************
    Adapter

    Convert the interface of a class into another interface clients expect. Adapter lets classes work together that couldn’t otherwise because of incompatible interfaces.

    ************************************************************************
    Strategy

    Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.

    ************************************************************************

    Command

    Encapsulate a request as an object, thereby letting you parameterize clients with
    different requests, queue or log requests, and support undoable operations.

    ************************************************************************

    Command Processor

    When using the command pattern in practice, you’re often confronted with the need to be able to compose a more complex command from several simple commands or to record and replay commands (scripting). In order to be able to implement such requirements in an elegant manner, the following design pattern is suitable.

    ************************************************************************
    Composite

    Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.

    ************************************************************************
    Observer

    Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

    ************************************************************************
    Factories

    The Factory design pattern is basically relatively simple and appears in code bases in many different forms and varieties.

    ************************************************************************
    Façade

    Provide a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use.

    ************************************************************************
    Determining the range of an arithmetic type

    The actual implementation-specific ranges for arithmetic types (either integral or floating-point) can be found as class templates in header <limits>.
    For example, this is how you will find maximum range for int:
    #include <limits>
    constexpr auto INT_LOWER_BOUND = std::numeric_limits<int>::min();
    constexpr auto INT_UPPER_BOUND = std::numeric_limits<int>::max();

    ************************************************************************
    The Money Class

    It is just another kind of complex data. One should ask himself these questions
    in order to handle this kind of class properly:
    What is the full range of values to be handled (minimum, maximum)?

    Which rounding rules apply? There are national laws or practices for
    roundings in some countries.

    Are there legal requirements for accuracy?

    Which standards must be considered (e.g., ISO 4217 International Standard for
    Currency Codes)?

    How will the values be displayed to the user?

    How often will conversion take place?

    ************************************************************************
    Sepcial Case Object (Null Object)

    A subclass that provides special behavior for particular cases.

    ************************************************************************
    std::optional<T> [C++17]

    Since C++17, there is another interesting alternative that could be used for a possibly missing result or value: std::optional<T> (defined in header <optional>). instances of this class template represent an “optional contained value,” that is, a value that may or may not be present.

    ************************************************************************
    What Is an Idiom?

    A simple example in C/C++ is the structure of a header filer with the well-known
    macros #ifndef/ #define/ #endif

    ************************************************************************
    Some Useful C++ Idioms

    They are close to 100 and very easy to find in Wikibooks.
    ************************************************************************
    The Power of Immutibility

    Benefits of immutable objects:
    Immutable objects are thread-safe by default
    Immutability makes it easier to write, use, and reason about the code.


    To create an immutable class in C++, the following measures must be taken:
    The member variables of the class must all be made immutable, that is, they must all be made const.

    Manipulating methods do not change the object on which they are called, but return a new instance of the class with an altered state.

    The class should be marked as final.

    ************************************************************************
    Substitution Failrue Is Not an Error (SFINAE)

    Is not a real idiom but a feature of the C++ compiler. It has already been a part of the C++98 standard, but with C++11 several new features have been added.

    If a substitution results in an invalid type or expression, type deduction fails. An invalid type or expression is one that would be ill-formed if written using the substituted arguments. Only invalid types and expressions in the immediate context of the function type and its template parameter types can result in a deduction failure.

    ************************************************************************
    The Copy-and-Swap Idiom

    Implement the copy assignment operator with strong exception safety.

    ************************************************************************
    Pointer to Implementation (PIMPL)

    Remove compilation dependencies on internal class implementation details by relocating them into a hidden implementation class and thus improve compile times.
































































    */

    return 0;
}
