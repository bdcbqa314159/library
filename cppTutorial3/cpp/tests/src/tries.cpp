#include <cppTutorial3>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
// Input 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
void testingTries()
{
    Trie t;

    string words[] = {"hello", "he", "apple", "aple", "news"};
    for (auto word : words)
    {
        t.insert(word);
    }

    string key;
    cin >> key;
    cout << t.search(key) << endl;

    return;
}

int main()
{
    testingTries();
    return 0;
}