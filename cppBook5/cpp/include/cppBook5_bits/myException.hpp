#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <string>

using namespace std;

class Exception
{
    string mTag, mProblem;

public:
    Exception(string tagString, string ProbString);
    void PrintDebug() const;
};

#endif