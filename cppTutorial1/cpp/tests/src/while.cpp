#include <iostream>

using namespace std;
int main()
{
    int i = 0;
    while (true)
    {
        cout << "Hello "
             << " " << i << endl;
        i++;
        if (i == 10)
            break;
    }

    i = 0;
    while (i <= 5)
    {
        cout << "Hello While coder. " << i << endl;
        i++;
    }

    return 0;
}