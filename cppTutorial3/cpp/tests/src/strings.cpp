#include <cppTutorial3>
#include <iostream>
#include <string>
#include <set>

using namespace std;

void testCompressingStrings()
{
    string s1 = "aaaaabbbbbllllllddddd";
    cout << s1 << endl;
    cout << "Compression:" << endl;
    cout << compressString(s1) << endl;
}

int main()
{

    cout << "Hey we are working with strings." << endl;
    testCompressingStrings();

    string v = "asdfdsaljlkjasfoe";
    set<char> mySet(v.begin(), v.end());

    for (char x : mySet)
        cout << x << " ";
    cout << endl;

    return 0;
}
