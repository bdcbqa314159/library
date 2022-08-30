#ifndef GUEST_H
#define GUEST_H

#include <string>

using namespace std;

class Guest
{

public:
    string name, roomType, arrivalDate;
    int numberOfNights;
    double telephoneBill;
    virtual double CalculateBill();
};

class SpecialGuest : public Guest
{

public:
    double CalculateBill();
};

#endif