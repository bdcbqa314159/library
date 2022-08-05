#include <cppTutorial3>
#include <iostream>

using namespace std;

void testingLinkedLists()
{
    List l;
    l.push_front(1);
    l.push_front(0);
    l.push_back(2);

    l.show();
    l.reverse();
    l.show();
}

int main()
{
    testingLinkedLists();

    return 0;
}
