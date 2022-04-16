#include "../include/cppDSA_bits/random.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int GenerateRandomNumber(int min, int max){
    static const double fraction = 1./(static_cast<double>(RAND_MAX)+1.);
    return min + static_cast<int>((max-min+1)*(rand()*fraction));
}
