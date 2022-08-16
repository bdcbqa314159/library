#include <cppTutorial1>
#include <iostream>

using namespace std;

class Test
{

    int id;
    string name;

public:
    Test() : id(0), name("")
    {
    }

    Test(int id, string name) : id(id), name(name)
    {
    }

    ~Test()
    {
    }

    Test(const Test &other)
    {
        id = other.id;
        name = other.name;
    }

    void print() const
    {
        cout << "id " << id << " --- name : " << name << endl;
    }

    bool operator<(const Test &other) const
    {
        if (name == other.name)
            return id < other.id;
        else
            return name < other.name;
    }

    string getName() const
    {
        return name;
    }

    int getId() const
    {
        return id;
    }

    const Test &operator=(const Test &other)
    {

        if (this != &other)
        {
            id = other.id;
            name = other.name;
        }

        return *this;
    }
};

ostream &operator<<(ostream &out, const Test &obj);

ostream &operator<<(ostream &out, const Test &obj)
{
    out << "ID: " << obj.getId() << " -- Name: " << obj.getName();
    return out;
}

void overloading1()
{

    Test test1(10, "Mike");
    test1.print();

    // Assignement
    Test test2(20, "Mary");
    test2 = test1;
    test2.print();

    // Copy constructor
    Test test3 = test1;

    // Rule of three if you implement copy constructor or assignment operator or custom constructor you will need to implement the three of them
}

void overloading2()
{
    cout << "Overloading << operator : " << endl;
    Test test1(34, "My bro");
    cout << test1 << endl;
    cout << ":-)" << endl;
}

class Complex
{
private:
    double re, im;

public:
    Complex() : re(0), im(0)
    {
    }

    Complex(double re, double im) : re(re), im(im)
    {
    }

    const Complex &operator=(const Complex &other)
    {

        if (this != &other)
        {
            re = other.re;
            im = other.im;
        }

        return *this;
    }

    Complex(const Complex &other) : re(other.re), im(other.im)
    {
    }

    ~Complex()
    {
    }

    double Re() const
    {
        return re;
    }

    double Im() const
    {
        return im;
    }

    bool operator==(const Complex &other)
    {
        return (re == other.Re() && im == other.Im());
    }

    bool operator!=(const Complex &other)
    {
        return !(*this == (other));
    }

    Complex operator*()
    {
        return Complex(re, -im);
    }
};

ostream &operator<<(ostream &os, const Complex &complex)
{
    os << complex.Re() << " + " << complex.Im() << "i";

    return os;
}

Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.Re() + c2.Re(), c2.Im() + c2.Im());
}

Complex operator*(const Complex &c1, const Complex &c2)
{
    double a = c1.Re();
    double b = c2.Re();
    double c = c1.Im();
    double d = c2.Im();

    return Complex(a * b - c * d, a * d + b * c);
}

Complex operator+(const Complex &c1, double x)
{
    const Complex c2(x, 0);
    return c1 + c2;
}

Complex operator*(const Complex &c1, double x)
{
    const Complex c2(x, 0);
    return c1 * c2;
}

Complex operator+(double x, const Complex &c1)
{
    const Complex c2(x, 0);
    return c1 + c2;
}

Complex operator*(double x, const Complex &c1)
{
    const Complex c2(x, 0);
    return c1 * c2;
}

int main()
{
    cout << "Working with my own complex number :)" << endl;
    Complex z(6, 9);
    cout << z << endl;

    return 0;
}