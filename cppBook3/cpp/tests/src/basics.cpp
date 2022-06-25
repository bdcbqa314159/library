#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int x, y;
    std::cout << "Please enter two numbers: ";
    std::cin >> x >> y;
    int sum = x + y;
    std::cout << "Their sum is " << sum << std::endl;

    return EXIT_SUCCESS;
}

// Some Notes:

/*
Comments :
    // for a single line.
    // /**'/ for multiples lines.

The usage of using namespace std to avoid std:: and make the code lighter.
A single replacement (which is faster) for std::endl : '\n'
*/

// Fundamental types:
/*
Building blocks:
    bool
    char
    short
    int
    long
    float
    double

    Also: enum & void.

*/

// Characters

/*
char a 8-bit structure but it can variate.
litteral: constant value appearing in a program, in c++ we have:
    '\n' newline
    '\b' backspace
    '\'' single quote
    '\\' backslash
    '\t' tab
    '\0' null
    '\"' double quote
*/

// Integers

/*


*/