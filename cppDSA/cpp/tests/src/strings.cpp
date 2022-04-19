#include <cppDSA>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Anagram()
{

    cout << "Anagram" << endl;
    string s1, s2;
    cout << "Input string 1 -> ";
    getline(cin, s1);
    cout << "Input string 2 -> ";
    getline(cin, s2);

    bool anagram = IsAnagram(s1, s2);
    cout << "'" << s1 << "' and '";
    cout << s2 << "' are ";
    if (anagram)
        cout << "anagrams.";
    else
        cout << "NOT anagrams.";
    cout << endl;

    return;
}

void Palindrome()
{

    string s1;
    cout << "Palindrome" << endl;
    cout << "Input string -> ";
    getline(cin, s1);
    cout << "'" << s1 << "' is ";
    if (IsPalindrome(s1))
        cout << "a palindrome.";
    else
        cout << "NOT a palindrome.";

    cout << endl;
    cout << "With fancy function:" << endl;

    cout << "'" << s1 << "' is ";
    if (FancyIsPalindrome(s1))
        cout << "a palindrome.";
    else
        cout << "NOT a palindrome.";

    cout << endl;

    return;
}

void DecimalToString()
{

    cout << "Decimal To Binary String" << endl;
    int decNum;
    cout << "Input a decimal number -> ";
    cin >> decNum;

    string binaryString = DecimalToBinaryString(decNum);
    cout << "Binary string of " << decNum;
    cout << " is '" << binaryString;
    cout << "'" << endl;

    return;
}

void StringToDecimal()
{

    cout << "Binary String To Decimal" << endl;
    string binaryString;
    cout << "Input a binary string -> ";
    getline(cin, binaryString);

    int decNumber = BinaryStringToDecimal(binaryString);
    cout << "Decimal of " << binaryString;
    cout << " is '" << decNumber;
    cout << "'" << endl;

    return;
}

void SubsequenceGenerator()
{

    cout << "Subsequence Generator" << endl;
    string s1;
    cout << "Input string -> ";
    getline(cin, s1);
    vector<string> myVector = GenerateSubsequences(s1);

    cout << "All the subsequences of " << s1 << ": " << endl;
    for (vector<string>::iterator it = myVector.begin(); it != myVector.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return;
}

void SubsequenceString()
{

    cout << "Subsequence String" << endl;
    cout << "Check if 1st string is a ";
    cout << "subsequence of 2nd string" << endl;
    string s1;
    cout << "Input 1st string -> ";
    getline(cin, s1);

    string s2;
    cout << "Input 2nd string -> ";
    getline(cin, s2);

    cout << "'" << s1 << "' is ";
    if (IsSubSequence(s1, s2, s1.size(), s2.size()))
    {
        cout << "subsequence";
    }
    else
    {
        cout << "NOT subsequence";
    }
    cout << " of '" << s2 << "'" << endl;

    return;
}

void PatternSearch()
{

    cout << "Pattern Searching" << endl;
    string target;
    cout << "Input target string -> ";
    getline(cin, target);

    string pattern;
    cout << "Input pattern string -> ";
    getline(cin, pattern);

    vector<int> myVector = SearchPattern(target, pattern);
    cout << "'" << pattern << "' is ";
    if (myVector.size() > 0)
    {
        cout << "found at index ";
        for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
            cout << *it << " ";
    }
    else
    {
        cout << "NOT found.";
    }
    cout << endl;

    return;
}

int main()
{
    Anagram();
    Palindrome();
    DecimalToString();
    StringToDecimal();
    SubsequenceGenerator();
    SubsequenceString();
    PatternSearch();

    return 0;
}