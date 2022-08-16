#include <cppTutorial1>
#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <initializer_list>
#include <functional>
#include <algorithm>
#include <memory>

using namespace std;
using namespace placeholders;

// auto for return types
template <class T>
auto functionTest(T value) -> decltype(value)
{
    return 7;
}

int get()
{
    return 999;
}

auto functionTest2() -> decltype(get())
{
    return get();
}

void cpp11Features1()
{
    cout << "----------------------" << endl;
    cout << "Features of c++ 11! " << endl;
    cout << "----------------------" << endl;

    cout << "=================================" << endl;
    cout << "Decltype, Typeid, Name Mangling" << endl;
    cout << "=================================" << endl;

    int value;
    cout << typeid(value).name() << endl;

    double value1;
    cout << typeid(value1).name() << endl;

    string value2;
    cout << typeid(value2).name() << endl;

    cout << "Declaration with decltype" << endl;
    decltype(value2) name = "Bob";
    cout << typeid(name).name() << endl;

    cout << "=================================" << endl;
    cout << "Auto keyword" << endl;
    cout << "=================================" << endl;

    auto value4 = 7;
    cout << value4 << endl;

    cout << functionTest2() << endl;

    cout << "=================================" << endl;
    cout << "Range Based Loops" << endl;
    cout << "=================================" << endl;

    cout << "**** Read the code not the output ****" << endl;
    auto texts = {"one", "two", "three"};

    for (auto text : texts)
    {
        cout << text << endl;
    }

    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(20);
    numbers.push_back(12);
    numbers.push_back(3);
    numbers.push_back(4);

    cout << endl;

    for (auto number : numbers)
    {
        cout << number << endl;
    }

    cout << endl;

    string hello = "Helllooooo";
    for (auto c : hello)
        cout << c << endl;

    cout << endl;

    cout << "=================================" << endl;
    cout << "Nested Template Class" << endl;
    cout << "=================================" << endl;

    // We want a circular structure.

    ring<string> textring(3);

    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");

    for (int i = 0; i < textring.size(); i++)
    {
        cout << textring.get(i) << endl;
    }

    cout << "=================================" << endl;
    cout << "Make class iterable" << endl;
    cout << "=================================" << endl;

    for (ring<string>::iterator it = textring.begin(); it != textring.end(); it++)
        cout << *it << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << "With auto" << endl;
    cout << "=================================" << endl;
    cout << endl;

    for (auto value : textring)
        cout << value << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << "C++98 initialization" << endl;
    cout << "=================================" << endl;
    cout << endl;
    cout << "NOTE: go have a look into the code." << endl;

    int values[] = {1, 2, 3, 4};
    cout << values[0] << endl;

    class C
    {
    public:
        string text;
        int id;
    };

    C c1 = {"Hello", 7}; // This work only if the attributes are public.
    cout << c1.text << endl;

    struct S
    {
        string text;
        int id;
    };

    S s1 = {"Goodbye", 45};
    cout << s1.text << endl;

    // Some nasty stuff:

    struct
    {
        string text;
        int id;
    } r1 = {"Hello@", 23};

    cout << r1.text << endl;

    vector<string> strings;
    strings.push_back("One");
    strings.push_back("Two");
    strings.push_back("Three");
    strings.push_back("Four");

    cout << endl;
    cout << "=================================" << endl;
    cout << "C++11 initialization" << endl;
    cout << "=================================" << endl;
    cout << endl;
    cout << "NOTE: go have a look into the code." << endl;

    int x{4};
    cout << x << endl;

    string y{"Hello"};
    cout << y << endl;

    int *pInt = new int[3]{1, 2, 3};
    cout << pInt[1] << endl;

    int *pSomething{&x};
    cout << *pSomething << endl;

    cout << "nullptr is from c++11!" << endl;
    // We can initialize attributes from the beginning but it implies the implementation of the constructors (classes speaking)

    vector<string> zz{"one", "two", "three"};

    cout << zz[1] << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << "Initializer list" << endl;
    cout << "=================================" << endl;
    cout << endl;

    class init
    {
    public:
        init(initializer_list<string> texts)
        {
            for (auto value : texts)
            {
                cout << value << endl;
            }
        }

        void print(initializer_list<string> l)
        {
            for (auto value : l)
            {
                cout << value << endl;
            }
        }
    };

    init t{"apple", "orange", "banana"};

    t.print({"one", "three", "zeta"});

    class ID
    {
        int id{3};
        string name{"Mike"};

    public:
        ID() = default;

        ID(const ID &other) = default; // We can put delete here instead default but it can lead to some problems.

        ID &operator=(const ID &other) = default;

        ID(int id) : id(id)
        {
        }

        void print()
        {
            cout << id << " : " << name << endl;
        }
    };
}

void lambdaTest(void (*pFunc)())
{
    pFunc();
}

void testGreet(void (*f)(string), string name)
{
    f(name);
}

void runDivide(double (*f)(double, double), double a, double b)
{
    auto rval = f(a, b);
    cout << rval << endl;
}

bool check(string &test)
{
    return test.size() == 3;
}

class Checking
{
public:
    bool operator()(string &test)
    {
        return test.size() == 3;
    }
};

void running(function<bool(string &)> f, string name)
{

    cout << f(name) << endl;
}

class mini
{
public:
    mini()
    {
        cout << "constructor" << endl;
    }
    mini(int i)
    {
        cout << "parametrized constructor" << endl;
    }

    mini(const mini &other)
    {
        cout << "copy constructor" << endl;
    }

    mini &operator=(const mini &other)
    {
        cout << "assignment" << endl;
        return *this;
    }
    ~mini()
    {
        cout << "destructor" << endl;
    }

    friend ostream &operator<<(ostream &os, const mini &m);
};

ostream &operator<<(ostream &os, const mini &m)
{
    os << "mini object here" << endl;
    return os;
}

// This could be bad but c++11 opmtimises it.
mini getMini()
{
    return mini();
}

void cpp11Features2()
{
    cout << endl;
    cout << "=================================" << endl;
    cout << "Lambda expressions" << endl;
    cout << "=================================" << endl;
    cout << endl;

    auto func = []()
    { cout << "Hello" << endl; };

    func();

    lambdaTest(func);

    lambdaTest([]()
               { cout << "Hello" << endl; });

    auto pGreet = [](string name)
    { cout << "Hello " << name << endl; };

    pGreet("Kate");

    testGreet(pGreet, "Bernardo");

    auto pDivide = [](double a, double b) -> double
    {
        if (b != 0)
            return a / b;
        return 0;
    };

    cout << pDivide(10.0, 5.) << endl;

    runDivide(pDivide, 54., 89.);

    cout << endl;
    cout << "=================================" << endl;
    cout << "Lambda capture expressions" << endl;
    cout << "=================================" << endl;
    cout << endl;

    int one = 1;
    int two = 2;
    int three = 3;

    // Capturing only one and two by value

    // [one, two]()
    // { cout << "Hello " << one << " , " << two << "." << endl; };

    // Capturing all local variables by value.
    // [=]()
    // {
    //     cout << one << endl;
    // };

    // Capturing all local variables by value but catching three by reference.
    // [=, &three]()
    // {
    //     three = 7;
    //     cout << one << " " << two << " " << endl;
    // };

    // Capturing all local variables by reference.
    // [&]()
    // {
    //     cout << one << endl;
    // };

    // Capturing all local variables by ref but catching three by value.
    // [&, two, three]()
    // {
    //     one = 7;
    //     cout << one << " " << two << " " << endl;
    // };

    cout << endl;
    cout << "=================================" << endl;
    cout << "Capturing this with lambda" << endl;
    cout << "=================================" << endl;
    cout << endl;

    class A
    {
        int one{1}, two{2};

    public:
        void run()
        {
            int three{3};
            int four{4};
            // this is catched by reference, this can be put everywhere BUT [=, this] is not allowed because this is catched by ref.
            // [&, this] works though.
            auto pLambda = [this, three, four]()
            {   cout<<one<<endl;
                cout<<two<<endl;
                cout << "three " << three << " -- four: " << four << endl; };
        }
    };

    A a;
    a.run();

    cout << endl;
    cout << "=================================" << endl;
    cout << "The standard function type" << endl;
    cout << "=================================" << endl;
    cout << endl;

    vector<string> vec = {"one", "three", "four"};

    auto lambda = [](string test)
    { return test.size() == 3; };
    int answer = count_if(vec.begin(), vec.end(), lambda);

    cout << answer << " occurences with length 3." << endl;

    answer = count_if(vec.begin(), vec.end(), check);

    cout << answer << " occurences with length 3." << endl;

    Checking check1;

    answer = count_if(vec.begin(), vec.end(), check1);

    cout << answer << " occurences with length 3." << endl;

    running(lambda, "Mik");

    function<int(int, int)> add = [](int one, int two)
    { return one + two; };

    cout << add(7, 3) << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << "Mutable Keyword" << endl;
    cout << "=================================" << endl;
    cout << endl;

    // What we can't do:
    // int cats = 5;
    // [cats]()
    // {
    //     cats = 8;
    //     cout << cats << endl;
    // }();

    // Instead:

    int cats = 5;
    [cats]() mutable
    {
        // Equals 8 only in this scope
        cats = 8;
        cout << cats << endl;
    }();

    cout << cats << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << "Delegating constructors" << endl;
    cout << "=================================" << endl;
    cout << endl;

    cout << "C++ 11 allows constructors to call them between themselves but it could lead to infinite loops... be careful." << endl;
    cout << "If class A has A(): A(3){} we don't have anymore the default keyword." << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << "Elision and optimization" << endl;
    cout << "=================================" << endl;
    cout << endl;

    cout << "return value optimization! => the compiler simplifies the extra calls caused by the returnig by value functions." << endl;

    mini m = getMini();
    cout << m << endl;

    vector<mini> v;

    v.push_back(mini());
}

class maxi
{
    static const int SIZE = 100;
    int *pBuffer{nullptr};

public:
    maxi()
    {
        cout << "constructor" << endl;
        pBuffer = new int[SIZE]{};

        for (int i = 0; i < SIZE; i++)
            pBuffer[i] = 0;

        memset(pBuffer, 0, sizeof(int) * SIZE);
    }

    maxi(int i)
    {
        cout << "parametrized constructor" << endl;
        pBuffer = new int[SIZE]{};

        for (int j = 0; j < SIZE; j++)
            pBuffer[j] = 7 * i;
    }

    maxi(const maxi &other)
    {
        cout << "copy constructor" << endl;
        pBuffer = new int[SIZE]{};
        memcpy(pBuffer, other.pBuffer, SIZE * sizeof(int));
    }

    // move constructor
    maxi(maxi &&other)
    {
        cout << "Move constructor." << endl;
        pBuffer = other.pBuffer;
        other.pBuffer = nullptr;
    }

    maxi &operator=(maxi &&other)
    {
        delete[] pBuffer;

        pBuffer = other.pBuffer;
        other.pBuffer = nullptr;

        return *this;
    }

    maxi &
    operator=(const maxi &other)
    {
        cout << "assignment" << endl;
        pBuffer = new int[SIZE]{};
        memcpy(pBuffer, other.pBuffer, SIZE * sizeof(int));
        return *this;
    }
    ~maxi()
    {
        cout << "destructor" << endl;
        delete[] pBuffer;
    }

    friend ostream &operator<<(ostream &os, const maxi &m);
};

ostream &operator<<(ostream &os, const maxi &m)
{
    os << "maxi object here" << endl;
    return os;
}

// This could be bad but c++11 opmtimises it.
maxi getMaxi()
{
    return maxi();
}

void checkLVal(const mini &val)
{
    cout << "lvalue function" << endl;
}

void checkRVal(mini &&val)
{
    cout << "rvalue function" << endl;
}

class Omega
{
    virtual void hello()
    {
        cout << "Hello" << endl;
    }
};

class omega1 : public Omega
{
};

class omega2 : public Omega
{
};

void cpp11Features3()
{
    cout << endl;
    cout << "=================================" << endl;
    cout << "Constructor and memory" << endl;
    cout << "=================================" << endl;
    cout << endl;

    cout << "Go have a look into maxi class" << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << "RValues & LValues" << endl;
    cout << "=================================" << endl;
    cout << endl;

    // RVal & LVal

    int val = 7;

    int *pVal1 = &val; // Ok val is a lval
    // int *pVal2 = &7; Problem because 7 is a rval and we can't take addresses of rval

    maxi maxi1 = getMaxi();

    maxi *pMax = &maxi1; // maxi1 is a lval.

    // maxi *Max2 = &getTest(); not allowed because the output of a function is rval

    // The difference between rval & lval can't be difficult to catch.

    int *pValue3 = &++val; // Here ok.
    // int *pValue4 = &val++; Problem because there is a temp value which is a rval.

    // int *sum = &(7+val) Poblem because the result is a rval.

    cout << endl;
    cout << "=================================" << endl;
    cout << "LValues references" << endl;
    cout << "=================================" << endl;
    cout << endl;

    mini m = getMini();
    cout << m << endl;

    vector<mini> v;

    v.push_back(mini());

    mini &rMini1 = m; // Ok

    // mini &rMini2 = getMini(); Problem because it is a rval.
    // BUT:

    const mini &rMini2 = getMini(); // Works

    mini m2(mini(1)); // works because we have a rval within m2.

    cout << endl;
    cout << "=================================" << endl;
    cout << "RValues references" << endl;
    cout << "=================================" << endl;
    cout << endl;

    // Linked with temporary values.

    mini &lmini1 = m;
    // mini &&rmini1 = m1; Problem because we have a rval ref bind with lval.
    mini &&rmini1 = getMini();

    checkLVal(m);
    checkRVal(getMini());
    checkRVal(mini());

    cout << endl;
    cout << "=================================" << endl;
    cout << "Move constructors" << endl;
    cout << "=================================" << endl;
    cout << endl;

    vector<maxi> vec2;
    vec2.push_back(maxi());

    cout << endl;
    cout << "=================================" << endl;
    cout << "Move assignment operators" << endl;
    cout << "=================================" << endl;
    cout << endl;

    maxi z = getMaxi();

    cout << endl;
    cout << "=================================" << endl;
    cout << "Static Casting" << endl;
    cout << "=================================" << endl;
    cout << endl;

    Omega O;
    omega1 o;

    // A way to cast
    float y = 3.45;
    cout << int(y) << endl;
    // A way to do it with static cast:
    cout << static_cast<int>(y) << endl;

    Omega *pp = &o;

    // This works but it is dangerous
    omega1 *pp1 = static_cast<omega1 *>(&O);

    omega1 *pp2 = &o;

    omega1 *pp3 = static_cast<omega1 *>(pp1);

    // static_cast helps the compiling process but it is up to the engineer to make the whole code working.

    Omega &&p = Omega();

    // Omega &&p2 = O; Does not work, instead:

    Omega &&p2 = static_cast<Omega &&>(O);

    cout << endl;
    cout << "=================================" << endl;
    cout << "Dynamic Casting" << endl;
    cout << "=================================" << endl;
    cout << endl;

    Omega *oo = &O;
    omega1 *ooo = dynamic_cast<omega1 *>(oo);

    if (ooo == nullptr)
    {
        cout << "Invalid cast" << endl;
    }

    else
    {
        cout << ooo << endl;
    }
}

class myTestF
{
};

void checkMyTest(myTestF &test)
{
    cout << "lvalue" << endl;
}

void checkMyTest(myTestF &&test)
{
    cout << "rvalue" << endl;
}

template <typename T>
void call(T &&arg)
{
    checkMyTest(forward<T>(arg));
}

int adding(int a, int b, int c)
{
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
}

int runRun(function<int(int, int)> f)
{
    return f(7, 3);
}

class T
{
public:
    int adding(int a, int b, int c)
    {
        cout << a << ", " << b << ", " << c << endl;
        return a + b + c;
    }
};

void cpp11Features4()
{
    cout << endl;
    cout << "=================================" << endl;
    cout << "Dynamic Casting" << endl;
    cout << "=================================" << endl;
    cout << endl;

    Omega a;
    omega1 b;
    omega2 c;

    Omega *aa = &b;
    omega2 *cc = static_cast<omega2 *>(aa);

    if (aa == nullptr)
    {
        cout << "Invalid cast" << endl;
    }

    else
    {
        cout << aa << endl;
    }

    myTestF test;
    auto &&t = test;

    call(test);

    cout << endl;
    cout << "=================================" << endl;
    cout << "Binding" << endl;
    cout << "=================================" << endl;
    cout << endl;

    cout << adding(3, 4, 5) << endl;
    // using placeholders

    auto calculate = bind(adding, 3, 4, 5);

    cout << calculate() << endl;

    auto calculate1 = bind(adding, _1, _2, _3);
    cout << calculate1(34, 12, 4) << endl;

    auto calculate2 = bind(adding, _2, 100, _1);
    cout << runRun(calculate2) << endl;

    T myT;

    auto calculate3 = bind(&T::adding, myT, _1, 100, _2);

    cout << runRun(calculate3) << endl;
}

class myTemp
{
    unique_ptr<T[]> pT;

public:
    myTemp() : pT(new T[2])
    {
    }
};

int main()
{
    cout << endl;
    cout << "=================================" << endl;
    cout << "unique pointer" << endl;
    cout << "=================================" << endl;
    cout << endl;

    unique_ptr<int> pTest(new int);

    cout << "Finished with unique pointer" << endl;

    *pTest = 7;

    unique_ptr<mini> pMini(new mini);

    cout << *pMini << endl;

    // auto_ptr was here before c++11 but now is deprecated.

    myTemp tmp;

    cout << endl;
    cout << "=================================" << endl;
    cout << "shared ptr" << endl;
    cout << "=================================" << endl;
    cout << endl;

    shared_ptr<mini> pMini1(new mini());

    cout << "finished" << endl;

    shared_ptr<mini> pMini3(nullptr);

    {
        shared_ptr<mini> pMini2 = make_shared<mini>();

        pMini3 = pMini2;
    }

    cout << "Finishing shared ptr" << endl;

    // the pointer is deleted when all the occurrences are out of the scope.

    return 0;
}
