#include <cppBook6>
#include <iostream>

using namespace std;

int main()
{
    cout << "Functional Programming" << endl;

    /*
    ************************************************************************
    What is Functional Programming?
    As a programming paradigm, functional programming has its own principles:
    No side effects by avoiding a (globally) shared mutable state.
    Immutable data and objects.
    Function composition and higher-order functions.
    Better and easier parallelization.
    Easy to test.
    ************************************************************************

    What Is a Function?
    First we have referential transparency for functions: which essentially means that for one input we will always have the same output.

    ************************************************************************
    Pure vs. Impure Functions

    Function with referential transparency and no side effects within the state is a pure function. Everything else is impure function.

    ************************************************************************
    Functional Programming in Modern C++

    We need to talk about Template Metaprogramming (TMP).
    ************************************************************************
    Functional Programming with C++ Templates

    TMP is functional programming and Turing Complete.
    ************************************************************************
    Turing Completeness
    A programming language is characterized as turing Complete, if you can solve any possible problem with it that can be theoretically computed by a turing machine. a turing machine is an abstract and theoretical machine invented by alan turing that serves as an idealized model for computations.

    ************************************************************************
    Function-Like Objects (Functors)

    Create a class and assign the operator() to make it work as a function.
    We have 3 types: Generator, Unary Function, Binary Function.
    ************************************************************************
    Generator
    As the name reveals, this type of Functor is used to produce something.

    Tip: The header <numeric> already contains a function template std::iota(), named
    after the functional symbol iota from programming language APL, which is not a generator functor, but it can be used to fill a container with an ascending sequence of values in an elegant way.

    ************************************************************************
    Unary Function
    As its name suggests, this Functor squares the values passed to it in the parenthesis operator. The operator() is declared as const, which is an indicator that it behaves like a pure function, that is, a call will have no side effects. This does not necessarily always have to be the case, because, of course, also a unary Functor can have private member variables, and thus a mutable state.

    ************************************************************************
    Predicates
    A special kind of Functors is Predicate. A unary Functor is called a Unary Predicate if it has one parameter and a Boolean return value.

    ************************************************************************
    Type traits
    Templates are the foundation of generic programming. the containers from the C++ Standard library, but also iterators and algorithms, are outstanding examples of very flexible generic programming using C++’s template concept. But from a technical point of view, however, just a simple textual find and replace procedure takes place if a template is instantiated with template arguments. For instance, if a template parameter is named T, every occurrence of T is replaced by the data type that is passed in as template argument during template instantiation.

    The C++ Standard library header <type_traits> (available since C++11) provides a comprehensive collection of checks to retrieve information about the types passed in as template arguments at compile time. in other words, with the help of type traits you are able to define compiler-verifiable requirements that template arguments must fulfill.

    ************************************************************************
    Binary Functors

    A Binary Functor is a function-like object that takes two parameters. If such a Functor operates on its two parameters to perform some calculation (e.g., addition) and returns the result of this operation, it is called a Binary Operator. If such a Functor has a Boolean return value as a result of some test, as shown in the following example, it is called a Binary Predicate.

    NOTE: std::binary_function and std::unary_function have been labelled deprecated with C++11, and are removed from the Standard Library with the recent C++17 standard.

    ************************************************************************

    Binders and Function Wrappers
    The <functional> header allows to wrap a function like an object and use the partial application where we can also use the place holders like _1, _2, ... _n
    and so make the function partially bounded with default values like.

    constexpr double multiply(const double multiplicand, const double multiplier) noexcept { return multiplicand * multiplier;}

    ...
    auto multiplyWith10 = std::bind(multiply, _1, 10.0);
    std::cout << "result = " << multiplyWith10(5.0) << std::endl;
    ...

    The function has been wrapped and now it only has one variable parameter.

    ************************************************************************
    Lambda Expressions

    Other frequently used terms for them are lambda functions, function literals, or just lambdas. Sometimes they are also called Closures, which is actually a general term from functional programming, and which, incidentally, is also not entirely correct.

    ************************************************************************

    Closure
    In imperative programming languages, we are accustomed to the fact that a variable is no longer available when the program execution leaves the scope within which the variable is defined. For instance, if a function is done and returns to its caller, all local variables of that function are removed from the call stack and deleted from memory.

    On the other hand, in Functional programming, we can build a Closure, which is a function object with a persistent local variable scope. in other words, Closures allow that a scope with some or all of its local variables is tied to a function, and that this scope object will persist as long as that function exists.


    In C++, such Closures can be created with the help of lambda expressions due to its capture list in the lambda introducer. a Closure is not the same as a lambda expression, as well as an object (instance) in object orientation is not the same as its class.

    ************************************************************************
    Structure

    [ capture list ](parameter list) -> return_type_declaration { lambda body }

    ************************************************************************
    Generic Lambda Expression (C++14)

    Combination with auto.
    Generalized lambdas are extremely useful in interaction with standard library algorithms, because they are universally applicable.

    ************************************************************************
    Higher-Order Functions

    A higher-order function is a function that takes one or more other functions as arguments, or they can return a function as a result.

    ************************************************************************
    Map, Filter, and Reduce

    Each serious functional programming language must provide at least three useful higher-order functions: map, filter, and reduce (synonym: fold).

    ************************************************************************
    Map

    Map might be the easiest to understand of the three. With the help of this higher-order function, we can apply an operator function to each single element of a list. In C++, this function is provided by the standard library algorithm std::transform (defined in header <algorithm>) that you’ve already seen in some previous code examples.

    ************************************************************************
    Filter

    Also filter is easy. As the name suggests, this higher-order function takes a Predicate (see section about Predicates earlier in this chapter) and a list, and it removes any element from the list that does not satisfy the Predicate’s condition. In C++, this function is provided by the standard library algorithm std::remove_if (defined in header <algorithm>) that you’ve already seen in some previous code examples.

    ************************************************************************
    Reduce (Fold)

    Reduce (synonyms: Fold, Collapse, Aggregate) is the most powerful of the three higher-order functions and might be a bit hard to understand at first glance. Reduce respectively fold is a higher-order function to get a single result value by applying a binary operator on a list of values. In C++, this function is provided by the standard library algorithm std::accumulate (defined in header <numeric>). Some say that std::accumulate is the most powerful algorithm in the standard library.

    ************************************************************************
    Left and Right Fold

    It is the way of how we operate the reduction: by the left or by the right.

    In C++, we can distinguish between a left fold and a right fold. if we use std::accumulate with normal iterators, we get a left fold:
    std::accumulate(begin, end, init_value, binary_operator)
    instead, if we use std::accumulate with a reverse iterator, we get a right fold: std::accumulate(rbegin, rend, init_value, binary_operator)

    ************************************************************************
    Fold Expression in C++17

    What has been added with C++17 is the possibility to reduce the parameter pack directly with the help of a binary operator, that is, to perform a folding.
    The general syntax of C++17 fold expressions are as follows:
    ( ... operator parampack )                     // left fold
    ( parampack operator ... )                     // right fold
    ( initvalue operator ... operator parampack )  // left fold with an init value
    ( parampack operator ... operator initvalue )  // right fold with an init value

    ************************************************************************
    Clean Code in Functional Programming

    The principles of good software design still apply, regardless of the programming style you will use!

    Always code as if the guy who ends up maintaining your code will be a violent psychopath who knows where you live.


















































    */

    return 0;
}
