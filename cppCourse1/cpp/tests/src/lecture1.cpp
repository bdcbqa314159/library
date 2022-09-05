#include <cppCourse1>
#include <iostream>

using namespace std;

void intro()
{
    int z = INT_MAX;
    cout << "This is the max: " << z;
    int z_1 = z + 1;

    cout << "And this is the max + 1 = " << z_1 << endl;
    cout << "Such an amazing result :p" << endl;

    int y = INT_MIN;
    cout << "This is the minimum: " << y << endl;

    cout << boolalpha << endl;
    cout << "z > z+1 : " << (z > z_1) << endl;
}

int main()
{
    cout << "Some stuff about arithmetic within programming." << endl;

    cout << "Normalized floating point number" << endl;
    cout << " x = (-1)^s * (1 + c/(2^p)) * 2^e" << endl;
    cout << " s in {0,1} ; 0<=c<2^p ; e_min < e < e_max" << endl;

    return 0;
}
