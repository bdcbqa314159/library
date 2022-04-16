#include <cppDSA>
#include <iostream>

using namespace std;

int main()
{

    // Animal dog = Animal();
    // dog.GiveName("dog");
    // cout << "Hi, I am a " << dog.GetName() << endl;

    // Animal dog = Animal("dog");
    // cout << "Hi, I am a " << dog.GetName() << endl;

    Dog dog = Dog("Bulldog");
    cout << dog.GetName() << " is barking: ";
    cout << dog.MakeSound() << endl;

    Dog dog2 = dog;
    cout << dog2.GetName() << " is barking: ";
    cout << dog2.MakeSound() << endl;

    return 0;
}