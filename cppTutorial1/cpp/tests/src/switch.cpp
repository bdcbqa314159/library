#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    int choice{};
    cout << "Enter your choice >> " << flush;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Choice 1" << endl;
        break;
    case 2:
        cout << "Choice 2" << endl;
        break;
    default:
        cout << "Unknown choice sorry" << endl;
        break;
    }

    cout << "Warning: switch only works with int & char!" << endl;
    cout << "Warning no.2 : never forget the breaks!" << endl;
    cout << "Warning no.3 : no variables in the cases, only if it is a const variable." << endl;

    return 0;
}