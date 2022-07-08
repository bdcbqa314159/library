#include "../include/cppTutorial3_bits/strings.hpp"

/*
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string s;
getline(cin, s, '.');
getline(cin, s, '\n') == getline(cin, s);

string s1 = "ljadsflkj";
string s2{"jasdlfkj"};

for (char x: s)
    cout<<x<<",";
cout<<endl;


int n = 5;
vector<string> sarr;
string temp;

while (n--){
    getline(cin, temp);
    sarr.push_back(temp);
}

for (char x: sarr)
    cout<<x<<endl;
cout<<endl;

*/

string compressString(string str)
{
    int n = str.size();
    string out;

    for (int i = 0; i < n; i++)
    {
        int count = 1;

        while (i < n - 1 and str[i + 1] == str[i])
        {
            count++;
            i++;
        }
        out += str[i];
        out += to_string(count);
    }
    if (out.length() > str.length())
        return str;
    return out;
}