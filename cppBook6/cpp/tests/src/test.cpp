#include <cppBook6>
#include <iostream>
#include <string>

using namespace std;

void test()
{
    message();
}

void say(string &message)
{
    cout << "hey lval: " << message << endl;
}

void say(string &&message)
{
    cout << "hey rval: " << message << endl;
}

int main()
{

    test();
    string message = "kokoriko";
    say(message);
    cout << endl;
    say("maMainDansTaGueule");

    return 0;
}
