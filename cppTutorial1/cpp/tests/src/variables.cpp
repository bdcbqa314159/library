#include <iostream>

using namespace std;

int main()
{
    cout << "Working with variables." << endl;

    cout << "Hello" << endl;
    int numberCats = 5;
    int numberDogs = 7;

    cout << "How many cats?" << endl;
    cout << "There is " << numberCats << " cats" << endl;
    cout << "Number of Dogs : " << numberDogs << endl;

    cout << "Total number of animals: " << numberCats + numberDogs << endl;

    cout << "New dog acquired!" << endl;
    numberDogs++;
    cout << "Number of dogs: " << numberDogs << endl;
    int totalAnimals = numberCats + numberDogs;
    cout << "New total of animals: " << totalAnimals << endl;
    cout << "End of the mini project." << endl;

    return 0;
}