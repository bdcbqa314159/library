#include <cppBook6>
#include <iostream>

using namespace std;

int main()
{
    cout << "Clean C++" << endl;

    /*
    ************************************************************************
    Good Names
    Source code files, namespaces, classes, templates, functions, arguments, variables, and constants should have meaningful and expressive names.
    ************************************************************************

    Names Should Be Self-Explanatory
    ->Self documenting code
    Use simple but descriptive and self-explaining names but we need to avoid
    verbose situations
    ************************************************************************
    Use Names from the Domain
    This self-explanatory method allows the understanding of the code even for
    the no technical users.
    ************************************************************************
    Choose Names at an Appropriate Level of Abstraction
    Depper in the level of abstraction we are, longest and expressive names
    for modules we have.
    ************************************************************************
    Avoid Redundancy When Choosing a Name
    Don't repeat the class's name in its attributes
    Don't include the attribute's type in its name
    ************************************************************************
    Avoid Cryptic Abbreviations

    std::size_t idx;           // Bad!
    std::size_t index;         // Good; might be sufficient in some cases
    std::size_t customerIndex; // To be preferred, especially in situations where
                            // several objects are indexed

    const double GOE = 9.80665; // Bad!
    const double gravityOfEarth = 9.80665;
                                            // More expressive, but misleading. The constant is
                                            // not a gravitation, which would be a force in physics.

    const double gravitationalAccelerationOnEarth = 9.80665; // Good.
    constexpr Acceleration gravitationalAccelerationOnEarth = 9.80665_ms2; // Wow!
    ************************************************************************
    Avoid Hungarion Notation and Prefixes
    Examples of Hungarian Notation:
    bool fEnabled;          // f = a boolean flag
    int nCounter;           // n = number type (int, short, unsigned, ...)
    char* pszName;          // psz = a pointer to a zero-terminated string
    std::string strName;    // str = a C++ stdlib string
    int m_nCounter;         // The prefix 'm_' marks that it is a member variable,
                            // i.e. it has class scope.
    char* g_pszNotice;      // That's a global(!) variable. Believe me, I've seen
                            // such a thing.
    int dRange;             // d = double-precision floating point. In this case it's
                            // a stone-cold lie!

    BUT: Do not use Hungarian notation, or any other prefix-based notation, encoding the type of a variable in its name!
    ************************************************************************
    Avoid Using the Same Name for Different Purposes
    The concept is all in the title and goes with the single responsability principle.


    ************************************************************************
    Comments
    Their usage has to be reduced, we need more a self-explanatory naming for every module.
    ************************************************************************
    Let The Code Tell a Story
    Code should tell a story and be self-explanatory. Comments must be avoided whenever possible.
    If there is a need to put a comment it is maybe because the code is not that clear.
    Any fool can write code that a computer can understand. Good programmers weite code that humans can understand.
    ************************************************************************
    Do Not Comment Obvious Things
    If everything is clear then no comments.
    ************************************************************************
    Don't Disable Code With Comments
    Except for the purpose to try out something quickly, don't use comments to disable code. There is a version control system!
    ************************************************************************
    Don't Write Block Comments
    Even the copyright block is not useful anymore since 1989 (Berne Convention)
    ************************************************************************
    Don't Use Comment to Substitute Version Control
    Everything is in the title!
    ************************************************************************
    The Rare Cases Where Comments Are Useful
    When you need an extra summary for no experts who might read the code.
    When we need to deviate from DRY and rewrite something, a good comment to explain this choice.

    All in all we need:
    Make sure that your comments add value to the code.
    Explain always the Why, not the How.
    Try to be as short and expressive as possible.

    One Tip: Comments should change to red! A comment in the source code should be somethin special, which should attract the attention of the developer.
    ************************************************************************
    Documentation Generation from Source Code
    A very double edge situation because before code generation we need to put some verbose comments which is against we already said above. See Doxygen for more information.


    ************************************************************************
    Functions
    The principles are more or less the same here.
    ************************************************************************
    One Thing, No More!
    Functions should do one thing, They should do it well. They should do it only.
    ************************************************************************
    Let Them Be Small
    Functions should be pretty small. Ideally 4-5 lines, maximum 12-15 lines. but no more.
    ************************************************************************
    But the Call Time Overhead!
    A function call nowadays is not slow anymore.
    ************************************************************************
    Function Naming
    The name of a function should start with a verb. Predicates, that is, statements about an object that can be true or false, should start with "is" or "has."

    void CustomerAccount::grantDiscount(DiscountValue discount); void Subject::attachObserver(const Observer& observer);
    void Subject::notifyAllObservers() const;
    int Bottling::getTotalAmountOfFilledBottles() const;
    bool AutomaticDoor::isOpen() const;
    bool CardReader::isEnabled() const;
    bool DoubleLinkedList::hasMoreElements() const;

    ************************************************************************
    Use Intention-Revealing Names

    The name of a function should express its intention/purpose, and not explain how it works.
    ************************************************************************
    Arguments and Return Values
    They have to be very clear and not too many within the function.
    ************************************************************************
    Number of Arguments
    Real functions should have as few arguments as possible. One argument is the ideal number. Member functions (methods) of a class often have no arguments. Usually those functions are manipulating the internal state state of the object, or they are used to query something from the object.
    ************************************************************************
    Avoid Flag Arguments
    One solution could be to provide separte, well-named functions instead or it could be a specialization.
    From c++11 using override with virtual functions become very handy.
    ************************************************************************
    Avoid Output Arguments
    At ALL costs.
    If we need to output several elements we can use tuple, make tuple & get<int>(theTuple).
    ************************************************************************
    Don't Pass or Return 0 (NULL, nullptr)
    If it is inevitable to return a regular pointer as the result from a function or method, do not return nullptr!
    Always we need to point to a valid address.
    ************************************************************************
    Strategies to Avoid Regular Pointers
    Prefer simple object construction on the stack instead of on the heap.
    From this in old C++:

    Customer* createDefaultCustomer() {
        Customer* customer = new Customer();
        // Do something more with customer, e.g. configuring it, and at the end... return customer;
    }

    To this with C++11:
    Customer createDefaultCustomer() {
        Customer customer;
        // Do something with customer, and at the end...
        return customer;
    }

    Under the hood we have the move semantics.

    ************************************************************************
    In a function's argument list, use (const) references instead of pointers

    void function(Type* argument);
    ...you should use C++ references, like this:
    void function(Type& argument);
    ************************************************************************
    If it is inevitable to deal with a pointer to a resource, use a smart one.
    ************************************************************************
    If an API returns a raw pointer
    Then we have an "it-depends problem."
    ************************************************************************

    The Power of const correctness
    Const correctness is a powerful approach for better and safer code C++.
    It saves time because any violation of const cause compile-time errors.
    Pay attention to const correctness. Use const as much as possible, and choose always a proper  declaration of variables or objects as mutable or immutable.

    Tip: Ther is as simple rule of thumb to read const qualifiers in the right manner. If you read them from right to left, then any appearing const qualifier modifies the thing to the left of it. Exception: If there is nothing on the left, for example, at the beginning of a declaration, then const mofifies the thing to its right hand.

    const also can be used within (non-static) member-function of a class as const.
    ************************************************************************

    About Old C-style in C++ Projects
    Nowadays you cannearly completely do without C programming in modern C++.

    ************************************************************************
    Prefer C++ Strings and Streams over Old C-style char*
    Apart from a few exceptions, strings in a modern C++ program should be represented by C++ strings taken from the Standard Library.
    Exceptions:
    If you just need a fixed array of fixed characters, then std::string provides little advantage.
    We can use:
    const char* const PUBLISHER = "Apress Media LLC";
    Another exception is compatibility with C-style API's respectively libraries.
    Some API's still use old char arrays to keep backwards compatibility.
    Far from these exceptions we should use strings.
    ************************************************************************
    Avoid Using printf(), sprintf(), gets(), etc.
    Don't use sprintf(). Since C++11 we can use std::to_string() / std::to_wstring() from <string>.
    Avoid using printf(), and also other unsafe C-functions, such as sprintf(), puts(), etc.
    ************************************************************************
    Prefer Standard Library Containers over Simple C-style Arrays
    Arrays from <array> and declared as std::array<int, 4> A rather than int* A[4]
    ************************************************************************
    Non-member std::begin() AND std::end() [C++11/14]
    #include <vector>
    using namespace std;
    vector<int> aVector;
    auto iter = begin(aVector); //.., instead of auto iter = aVector.begin();

    The advantage of this is that begin(...) can be used with:
    int a[] = {12,3,4,12,67,11,54,90};
    But we don't have a.begin().
    We just need to implement this:
    template <typename Type, std::size_t size>
    Type* begin(Type (&element)[size]) {
        return &element[0];
    }
    template <typename Type, std::size_t size>
    Type* end(Type (&element)[size]) {
        return &element[0] + size;
    }
    ************************************************************************
    Use C++ casts Instead of Old C-Style Casts
    Warning: Type casts are basically bad and should be avoided wherever possible! They are trustworthy indication that there must be, albeit only a relatively tiny, design problem.

    double d{3.14159};
    int i = (int)d; //NO!
    int i = static_cast<int>d; //MUCH BETTER

    This is not flagged by the compiler:

    int32_t i { 200 };                  // Reserves and uses 4 byte memory
    int64_t* pointerToI = (int64_t*)&i; // Pointer points to 8 byte
    *pointerToI = 9223372036854775807;  // Can cause run-time error through stack
                                        // corruption

    int64_t* pointerToI = static_cast<int64_t*>(&i); // Pointer points to 8 byte
    But this is flagged so...

    Some advices though:
    Try to avoid type conversions (casts) under all circumstances.
    Use solely C++ style casts (static_cast<> or const_cast<>), never use old and bad C-style casts.
    Note that dynamic_cast<> should not be used because it is considered bad design.
    -> is a reliable indication that something is wrong within a specialization hierarchy.
    Under all circumstances, never use reinterpret_cast<>. This kind of type conversion marks as unsafe, non-portable, and implementation-dependent cast.
    ************************************************************************
    Avoid Macros
    Just avoid it :)






































    */

    return 0;
}
