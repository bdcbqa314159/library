#include <iostream>
#include <string>

using namespace std;

class Animal
{

private:
    string name;

public:
    Animal()
    {
        cout << "Animal created" << endl;
    }

    Animal(const Animal &other) : name(other.name)
    {
        cout << "Animal creted with copy constructor" << endl;
        // cout << "Every const method can be called here!" << endl;
    }

    ~Animal()
    {
        cout << "Destructor called" << endl;
    }

    void setName(string name) { this->name = name; }

    void speak() const
    {
        cout << "My name is " << name << endl;
    }
};

class Person
{
    string name;

public:
    Person()
    {
    }
    Person(const Person &other) : name(other.name)
    {
    }

    ~Person()
    {
    }

    void setName(string name)
    {
        this->name = name;
    }

    void speak() const
    {
        cout << "Person: my name is " << name << endl;
    }
};

void workingConst();
void workingWithCopyConstructor();

Animal *createAnimal()
{
    Animal *pAnimal = new Animal();
    pAnimal->setName("Bertie");
    return pAnimal;
}

int main()
{

    cout << "==========" << endl;

    cout << "==========" << endl;
    cout << "Working with the new keyword." << endl;
    Animal *pCat = new Animal();
    pCat->setName("Felix");
    pCat->speak();
    delete pCat;

    Animal *pCat1 = nullptr;

    cout << "Size of a pointer:" << endl;
    cout << sizeof(pCat) << endl;
    cout << "Size of a long:" << endl;
    cout << sizeof(long) << endl;
    cout << "For substraction between pointers, we need to cast into a long primitive datatype." << endl;

    delete pCat1;

    cout << "==========" << endl;
    cout << "Returning objects with functions" << endl;
    cout << "Something very bad to do: returning a reference on a local variable within the scope of a function." << endl;
    Animal *frog = createAnimal();
    frog->speak();

    delete frog;

    cout << "==========" << endl;
    cout << "Allocating memory" << endl;
    Animal *pAnimal = new Animal;
    int *pInt = new int;

    delete pAnimal;
    delete pInt;

    Animal *pAnimals = new Animal[10];
    pAnimals[5].setName("George");
    pAnimals[5].speak();

    delete[] pAnimals;

    char *pMem = new char[1000];
    delete[] pMem;

    cout << "Mini exercise:" << endl;
    Person *Persons = new Person[26];
    char c = 'a';
    for (int i = 0; i < 26; i++, c++)
    {
        string name(1, c);
        Persons[i].setName(name);
    }

    for (int i = 0; i < 26; i++)
    {
        Persons[i].speak();
    }

    return 0;
}

void workingConst()
{
    const double PI = 3.14159;
    cout << PI << endl;
    cout << "Can't change the value above because it is declared as const" << endl;

    Animal animal;
    animal.setName("Freddy");
    animal.speak();

    int value = 8;
    int *pValue = &value;
    cout << *pValue << endl;

    cout << "Changing value of pointers" << endl;
    int number = 11;
    pValue = &number; // error int *const pValue = &value; & const int *const pValue = &value;
    cout << *pValue << endl;
    *pValue = 12; // error with const int *pValue = &value; & const int *const pValue = &value;
    cout << number << endl;
}

void workingWithCopyConstructor()
{
    cout << "Working with copy constructors" << endl;

    Animal a;
    a.setName("Y");
    cout << "The default copy constructor tries to copy the first animal" << endl;
    Animal b = a;
    cout << "Just after copy:" << endl;
    b.speak();
    b.setName("Z");
    a.speak();
    b.speak();
}