#include <cppBook6>
#include <iostream>

using namespace std;

int main()
{
    cout << "Test-Driven Development" << endl;

    /*
    ************************************************************************
    In this chapter, we will not only explain that although the term “Test” is included in Test-Driven Development, it is not primarily about quality assurance. TDD offers many more benefits than just a simple validation of the correctness of the code. Rather I will explain the differences of TDD to what is sometimes called Plain Old Unit Testing (POUT), followed by the discussion of the workflow of TDD in detail, supported by a detailed practical example showing how to do it in C++.

    ************************************************************************
    The Drawback of Plain Old Unit Testing (POUT)

    It is code first, test after.
    This approach has a few disadvantages.
    There is no compulsion to write the unti tests afterwards.
    The resulting code can be difficult to test.
    It is not easy to reach pretty-high test coverage with retrofitted unit tests.

    ************************************************************************
    Test-Driven Developement as a Game Changer

    TDD means that we write the test for a new feature or function always before we write the corresponding production code.

    ************************************************************************
    The Workflow of TDD
    The three steps of TDD are:
    Red: We write one failing unit test.
    Green: We write just enough production code that the nwe test and all previously written tests will pass.
    Refactor: Code duplication and other code smells are eliminated, both from the production code as well as from the unit tests.

    ************************************************************************
    Uncle Bob's Three Rules of TDD

    You are not allowed to write any production code until you have first written a failing unit test.

    You are not allowed to write more of a unit test than is sufficient to fail – and not compiling is failing.

    You are not allowed to write more production code than is sufficient to pass the currently failing unit test.

    ************************************************************************
    TDD by Example: The Roman Numerals Code Kata

    These sections need to be redo with knowledge between boost.test & gtest with cmake.
    ************************************************************************
    TDD Kata: Convert Arabic Numbers to Roman Numerals
    Preparations
    The First Test
    The Second Test
    The Third Test and the Tidying Afterwards
    More Sophisticated Tests with a Custom Assertion
    It's time to Clean Up Again
    Approaching the Finish Line
    Done!
    ************************************************************************
    The Advantages of TDD

    TDD, if done right, forces you to take small steps when writing software.
    TDD established a very fast feedback loop.
    Creating a unit test first helps a developer to really consider what needs to be done.
    With TDD agapless specification arises in the form of executable code.
    The developer deals much more consciously and responsibly with dependencies.
    The emerging production code with TDD will have 100% unit test coverage by default.

    ************************************************************************
    When We Should Not Use TDD

    No doubt: Test-Driven Development is a great practice to guide the design and implementation of a piece of software. Theoretically, it would even be possible to develop almost all parts of a software system this way. And as a kind of positive side effect, the emerging code is 100% tested by default.

    For anything that is more complex than just a few lines of code, software craftsmen can test-drive code as fast as other developers can write code without tests, if not faster.

    TIP: If you want to dive deeper into test-Driven Development with C++, i recommend the excellent book Modern C++ Programming with Test-Driven Development by Jeff langr. Jeff's book offers much deeper insights into tDD and gives you hands-on lessons in the challenges and rewards of doing tDD in C++.

















    */

    return 0;
}
