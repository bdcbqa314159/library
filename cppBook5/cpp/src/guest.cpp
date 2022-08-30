#include "../include/cppBook5_bits/guest.hpp"
#include <iostream>
#include <cassert>

double Guest::CalculateBill()
{
    return telephoneBill + ((double)numberOfNights) * 50.;
}

double SpecialGuest::CalculateBill()
{
    return 45. + ((double)(numberOfNights - 1)) * 40.;
}