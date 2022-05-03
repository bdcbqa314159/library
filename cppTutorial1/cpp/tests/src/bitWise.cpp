#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    int color = 0x123456;
    int red = (color & 0xFF0000) >> 16;
    int blue = (color & 0x00FF00) >> 8;
    int green = (color & 0x0000FF);

    cout << hex << red << endl;
    cout << hex << blue << endl;
    cout << hex << green << endl;

    return 0;
}