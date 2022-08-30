#include "../include/cppBook5_bits/myException.hpp"
#include <iostream>

Exception::Exception(string tagString, string ProbString) : mTag(tagString), mProblem(ProbString)
{
}

void Exception::PrintDebug() const
{
    cerr << "** Error ( " << mTag << ") **" << endl;
    cerr << "Problem: " << mProblem << endl;
}
