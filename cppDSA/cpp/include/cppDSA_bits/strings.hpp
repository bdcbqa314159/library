#ifndef STRINGS_H
#define STRINGS_H
#include <string>
#include <vector>

bool IsAnagram(std::string s1, std::string s2);
bool IsPalindrome(std::string s1);
bool FancyIsPalindrome(std::string s1);

std::string DecimalToBinaryString(int decimalNumber);

int BinaryStringToDecimal(std::string s1);

std::vector<std::string> GenerateSubsequences(std::string s1);

bool IsSubSequence(std::string s1, std::string s2, int x, int y);

std::vector<int> SearchPattern(std::string target, std::string pattern);

#endif