#include <cppTutorial1>
#include <iostream>
#include <string>
#include <exception>

using namespace std;

void goesWrong()
{
    bool error1Detected = true;
    bool error2Detected = false;

    if (error1Detected)
    {
        throw bad_alloc();
    }

    if (error2Detected)
    {
        throw exception();
    }
}

class MyException : public exception
{

public:
    virtual const char *what() const throw()
    {
        return "Something bad happened!";
    }
};

class Test
{
public:
    void goesWrong()
    {
        throw MyException();
    }
};

class CanGoWrong
{

public:
    CanGoWrong()
    {
        char *pMemory = new char[999999999999999999];
        delete[] pMemory;
    }
};

void mightGoWrong()
{
    bool error = false;
    bool error1 = true;

    if (error)
    {
        throw "Something went wrong";
    }

    if (error1)
    {
        throw string("Something else went wrong");
    }
}

void usesMightGoWrong()
{
    mightGoWrong();
}

void testingExceptions()
{
    try
    {
        usesMightGoWrong();
    }

    catch (int e)
    {
        cout << "Error code :" << e << endl;
    }

    catch (char const *e)
    {
        cout << "Error message: " << e << endl;
    }

    catch (string &e)
    {
        cout << "String error message " << e << endl;
    }

    cout << "Still running" << endl;
}

void exceptionWithCustomClass()
{
    try
    {
        CanGoWrong wrong;
    }

    catch (bad_alloc &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
}

void testingCustomException()
{

    Test test;

    try
    {
        test.goesWrong();
    }

    catch (MyException &e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    try
    {
        goesWrong();
    }

    catch (bad_alloc &e)
    {
        cout << "catching bad_alloc: " << e.what() << endl;
    }

    catch (exception &e)
    {
        cout << "catching exception: " << e.what() << endl;
    }

    return 0;
}

/*
No matter if there are nested functions, the exceptions are thrown out from the stack waiting to be catched.

Must be careful with the order : always subclasses first!

*/