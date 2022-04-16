#include <cppDSA>
#include <iostream>

using namespace::std;

int main()
{
    int i;
    std::cout<<"Please enter an integer value: ";
    std::cin>>i;
    std::cout<<"The value you entered is "<<i<<endl;
    if (i>100)
        cout<<"and it is greater than 100";
    else
        cout<<"and it is equal or less than 100";
    cout<<endl;
    return 0;
}
