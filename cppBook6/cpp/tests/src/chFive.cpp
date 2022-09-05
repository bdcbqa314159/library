#include <cppBook6>
#include <iostream>

using namespace std;

int main()
{
    cout << "Advanced Concepts of Modern C++" << endl;

    /*
    ************************************************************************
    Managing Resources
    Warning: Do not underestimate resource leaks! Resource leaks are a serious
    problem, particularly for long-lived processes, and for processes that rapidly allocate many resources without deallocating them after usage.
    If an operating system has a lack of resources, this can lead to critical system stated.
    Furthermore, resource leaks can be a security issue, because they can be exploited by assaulters for denial-of-service attack.
    The central question is this: How can we guarantee that allocated resources are always freed?
    ************************************************************************
    Resource Acquisition Is Initialization (RAII)
    The point is to wrap the resource in order to play with its constructor/destructor within the scope of execution and no use any new/delete manually.
    ************************************************************************
    Smart Pointers
    ************************************************************************
    Unique Ownership with std::unique_ptr<T>
    Caution from C++11 std::auto_ptr<T> is deprecated and from C++17 it is removed.
    ************************************************************************
    Shared Ownership with std::shared_ptr<T>
    One Resource can be shared by many of this kind of pointers, the move semantics allows copy constructors which is not the case with std::unique_ptr<T>
    ************************************************************************
    No Ownership, but Secure Access with std::weak_ptr<T>
    With shared and weak we can make the distinction between users and owners of a resource.
    IMPORTANT: Use weak pointer when it comes circular dependency.
    Circular dependency should be avoided when it is possible we should follow Acyclic Dependency Principle instead.
    ************************************************************************
    Avoid Explicit New and Delete
    new and delete increase complexity.
    Use allocations on the stack whenever possible.
    To allocate a resource on the heap, use "make functions."
    Use containers (Standard Library, Boost, or others) wherever appropriate.
    Provide wrappers for resources from proprietary third-party libraries.
    ************************************************************************
    Managing Proprietary Resources
    Check how HANDLE in Windows manages resources, it is a void-pointer so we would need:
    using Win32SharedHandle = std::shared_ptr<void>;
    using Win32WeakHandle = std::weak_ptr<void>;
    Note: It is not allowed to define std::unique_ptr<void> in C++! It is because std::shared_ptr<T> implements type-erasure, while std::unique_ptr<T> does not. I a class supports type-erasure, it means that it can store objects of an arbitrary type, and destruct them correctly.
    ************************************************************************
    We Like to Move It
    The most important feature in C++11: The MOVE semantics.
    ************************************************************************
    What Are Move Semantics?
    Some cases where the copy constructor are used:
    The returning of a local object instance as a return value from a function or method. To prevent the copy construction in these cases prior C++11, pointers were frequently used.
    Inserting an object into a std::vector or other containers.
    The implementation of the std::swap<T> template function.

    As we will see later in the section “The Rule of Zero,” it should be a major goal of any C++ developer to not declare and define such constructors and assignment operators explicitly.

    ************************************************************************
    The Matter with Those lvalues and rvalues

    lvalue it is a locator value.
    Examples:
    Type var1;
    The expression var1 is an lvalue of type Type. The following declarations represent lvalues too:
    Type* pointer;
    Type& reference;
    Type& function();
    ************************************************************************
    rvalue References
    Move semantics are very close to rvalues.
    ************************************************************************
    Don't Enforce Move Everywhere
    In most cases, it is not necessary to do that. Under normal circumstances, the selection between the copy and the move versions of constructors or assignment operators is done automatically at compile time through overload resolution. The compiler ascertains whether it is confronted with an lvalue or an rvalue, and then selects the best fitting constructor or assignment operator accordingly.
    Be careful with optimization! The compiler can do this move semantics by itself.
    ************************************************************************
    The Rule of Zero
    The Rule of Three -> The Rule of Five -> The Rule Of Zero
    Write your classes in a way that your do not need to declare/define neither a destructor, nor a copy/move constuctor or copy/move assignment operator. Use C++ smart pointers and standard library classes and containers for managing ressources.
    ************************************************************************
    The Compiler is Your Colleague
    3 Rules:
    Everything that can be done at compile time should also be done at compile time.
    Everything that can be checked at compile time should also be checked at compile time.
    Everything the compiler can know about a program should also be determined be the compiler.
    ************************************************************************
    Automatic Type Deduction
    In short the auto keyword :)
    Argument Dependent Name Lookup (ADL):is a compiler technique to look up for an unqualified function name (that is, a function name without a prefixed namespace qualifier) depending on the types of the arguments passed to the function at its call site.
    A bottom line for all this: do not be afraid to use auto auto& or const auto&.
    ************************************************************************
    STD::INITIALIZER_LIST<T> C++11
    Since C++11 we can do this:
    std::vector<int> integerSequence { 14, 33, 69, 104, 222, 534 };
    If it does not obscure the intent of your code, use auto wherever possible!
    ************************************************************************
    Computation during Compile Time
    The constexpr specifier declares that it is possible to evaluate the value of the function or variable at compile time. Such variables and functions can then be used where only compile time constant expressions are allowed (provided that appropriate function arguments are given).
    ************************************************************************
    Variable Templates
    Last but not least, you can also use classes in computations at compile time.
    You can define constexpr constructors and member functions for classes.

    Also constexpr classes can be used both, at compile time and at runtime. In contrast to ordinary classes, however, it is not allowed to define virtual member functions (there is no polymorphism at compile time), and a constexpr class must not have an explicitly defined destructor.


    NOTE: The above code example could fail to compile on some C++ compilers.
    By today’s standards, the C++ standard does not specify common mathematical
    functions from the numerics library (header <cmath>) as constexpr, like
    std::sqrt() and std::pow(). Compiler implementations are free to do it
    anyway, but it’s not mandatorily required.
    ************************************************************************
    Don't Allow Undefined Behavior
    Wrong usage of smart pointers:

    const std::size_t NUMBER_OF_STRINGS { 100 };
    std::shared_ptr<std::string> arrayOfStrings(new std::string[NUMBER_OF_STRINGS]>);

    CAUTIONS: Avoid undefined behavior! It is a bad mistake and ends up with programs that silently misbehave.

    Good usage:
    const std::size_t NUMBER_OF_STRINGS { 100 };
    std::shared_ptr<std::string> arrayOfStrings(new std::string[NUMBER_OF_STRINGS],
    std::default_delete<std::string[]>());

    ************************************************************************
    Type-Rich Programming

    constexpr Acceleration gravitationalAccelerationOnEarth = 9.80665_ms2;
    constexpr Acceleration operator"" _ms2(long double magnitude)
    { return Acceleration(magnitude);}

    TIP: There are already some template-based libraries available that provide types for physical quantities, including all sI units. a well-known example is Boost.Units (part of Boost since version 1.36.0; see https://www.boost.org).

    ************************************************************************
    Know Your Libraries
    Over the past decades, many excellent libraries and frameworks have emerged
    in the C++ environment. These solutions had the chance to mature over a
    long time, and have been used successfully in tens of thousands of projects.
    There is no need to reinvent the wheel. Good software craftspeople should know
    about these libraries. It is not required to know every tiny detail about these
    libraries and their APIs. It is just good to know, however, that there are
    already tried-and-tested solutions for certain fields of application, which are
    worth looking at to take into a narrower selection for your software development
    project.

    ************************************************************************
    Take Advantage of <algorithm>
    Find out if a poor handmade craft algorithm can be replaced by a stl one.

    ************************************************************************
    Easier Parallelization of Algorithms Since C++17
    A majority of algoritm templates from header <algorithm> have been overloaded and are now also available in a parallelizable version.
    the three standard policy tags that are available for the template
    parameter ExecutionPolicy are:

    std::execution::seq – an execution policy type that defines that a parallel algorithm’s execution may be sequentially. hence, it is more or less the same as you would use the single-threaded standard version of the algorithm template function without an execution policy.

    std::execution::par – an execution policy type that defines that a parallel algorithm’s execution may be parallelized. It permits the implementation to execute the algorithm on multiple threads. Important: the parallel algorithms do not automatically protect against critical data races or deadlocks! You are responsible to ensure that no data race conditions can occur while executing the function.

    std::execution::par_unseq – an execution policy type that defines that a parallel algorithm’s execution may be vectorized and parallelized. vectorization takes advantage of the sIMd (Single Instruction, Multiple Data) command set of modern CpU’s. sIMd means that a processor can perform the same operation on multiple data points simultaneously.

    ************************************************************************
    Sorting and Output of a Container

    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <vector>
    void printCommaSeparated(const std::string& text)
    { std::cout << text << ", ";}

    int main() {
    std::vector<std::string> names = { "Peter", "Harry", "Julia", "Marc", "Antonio", "Glenn" };
    std::sort(std::begin(names), std::end(names));
    std::for_each(std::begin(names), std::end(names), printCommaSeparated);
    return 0;
    }

    ************************************************************************
    Comparing Two Sequences
    See Listing 5-26;
    But to sum up we use std::equal within a boolean function.
    std::equal use by default operator==.
    But we can also use a inbuilt boolean comparator by wrapping std::compare.
    And we can also, ofc use a lambda function within std::equal.

    ************************************************************************
    Take Advantage of Boost
    This is a must!

    ************************************************************************
    More Libraries That You Should Know About

    Date and time utilities (<chrono>)
    Regular expression library (<regex>)
    Filesystem library (<filesystem>)
    Range-v3
    Concurrent Data Structures (libcds)

    ************************************************************************
    Proper Exception and Error Handling

    The following sections present some rules, guidelines, and principles
    that help C++ programmers to design and implement a good error handling strategy.

    ************************************************************************
    Prevention Is Better Than Aftercare

    Precondition: A precondition is a condition that must always be true before
    a function or a class’s method is invoked. If a precondition is violated,
    no guarantee can be given that the function call leads to the expected result:
    the function call may succeed, may fail, can cause unwanted side effects,
    or show undefined behavior.

    Invariant: An invariant is a condition that must always be true during the
    execution of a function or method. In other words, it is a condition that
    is true at the beginning and at the end of a function’s execution. A special
    form of an invariant in object- orientation is a class invariant. If such
    an invariant is violated, the object (instance) of the class is left behind
    in an incorrect and inconsistent state after a method call.

    Postcondition: A postcondition is a condition that must always be true
    immediately after the execution of a function or method. If a
    postcondition is violated, an error must have occurred during execution
    of the function or method.

    ************************************************************************
    No Exception-Safety

    I think that there is no doubt about that the code written by you should never
    ever offer this inadequate level of exception-safety! Just pretend that
    there is no such thing as “no exception-safety.” That’s all; there’s nothing
    more to say about that.

    ************************************************************************
    Basic Exception-Safety

    If an exception is thrown during a function or method call, it is ensured that no
    resources are leaked! This guarantee includes memory resources as well as
    other resources. This can be achieved by applying RAII Pattern (see section
    about RAII and Smart Pointers).

    If an exception is thrown during a function or method call, all invariants
    are preserved.

    If an exception is thrown during a function or method call, there will be
    no corruption of data or memory afterwards, and all objects are in a healthy
    and consistent state. However, it is not guaranteed that the data content is
    the same as before the function or method has been called.

    Design your code, especially your classes, such that they guarantee at least
    the basic exception-safety. This should always be the default exception-safety
    level!

    ************************************************************************
    Strong Exception-Safety

    Issue the strong exception-safety guarantee for your code only if it is absolutely
    required.
    Of course, if there are certain quality requirements regarding data integrity
    and data correctness that have to be satisfied, you have to provide the
    rollback mechanism that is guaranteed through strong exception-safety.

    ************************************************************************
    The No-Throw Guarantee

    Simply speaking, this level means that as a caller of a function or method
    you don’t have to worry about exceptions. The function or method call
    will succeed.
    This is quite difficult or even impossible within C++.
    But here are the cases where the no-throw guarantee is either absolutely mandatory.

    Destructors of classes must guarantee to be no-throw under all circumstances!
    Move operations (move constructors and move assignment operators) should guarantee to be no-throw.
    Default constructors should be preferably no-throw.
    A swap function must guarantee to be no-throw under all circumstances!

    ************************************************************************
    NOEXCEPT SPCIFIER AND OPERATOR [C++11]

    The usage of throw(exceptionType, exceptionType, ...) is deprecated since
    C++11 and has now been finally removed from the standard with C++17!

    What is still available, but also marked as deprecated since C++11 is the
    throw() specifier without an exception type list. Its semantics are now the
    same as the noexcept(true) specifier.

    The noexcept specifier in a function’s signature declares that the function
    may not throw any exceptions. the same is valid for noexcept(true), which is
    just a synonym for noexcept. Instead, a function that is declared with
    noexcept(false) is potentially throwing, that is, it may throw exceptions.
    Here are some examples:
    void nonThrowingFunction() noexcept;
    void anotherNonThrowingFunction() noexcept(true);
    void aPotentiallyThrowingFunction() noexcept(false);

    There are at least two good reasons for the use of noexcept:
    First, exceptions that a function or method could throw (or not) are parts of
    the function’s interface.
    Second, it can be used by the compiler for optimizations.

    ************************************************************************
    An Exception Is an Exception - Literally!

    Throw exceptions only in very exceptional cases. do not misuse exceptions
    to control the normal program flow.

    ************************************************************************
    If You Can't Recover, Get Out Quickly

    If you are confronted with an exception from which you cannot recover, it
    is often the best approach to log the exception (if possible), or to generate
    a crash dump file for later analyzing purposes, and to terminate the
    program immediately.

    ************************************************************************
    Define User-Specific Exception Types

    It is a very good idea to create your custom exception classes
    for certain, mostly domain-specific, exceptions.

    ************************************************************************
    Throw by Value, Catch by const Reference
    Everything is said :)

    ************************************************************************
    Pay Attention to the Correct Order of Catch-Clauses

    The more specific exceptions must be handled first.




























































































































    */

    return 0;
}
