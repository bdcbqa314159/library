#include "../include/cppDSA_bits/strings.hpp"
#include <algorithm>
#include <cmath>

bool IsAnagram(std::string s1, std::string s2)
{

    /*
        Not case sensitive / No care about spaces (Very important details).
    */

    std::transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

    s1.erase(std::remove(s1.begin(), s1.end(), ' '), s1.end());
    s2.erase(std::remove(s2.begin(), s2.end(), ' '), s2.end());

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    return s1 == s2;
}

bool IsPalindrome(std::string s1)
{

    std::transform(s1.begin(), s1.end(), s1.begin(), ::toupper);

    s1.erase(std::remove(s1.begin(), s1.end(), ' '), s1.end());

    int left = 0, right = s1.size() - 1;

    while (right > left)
    {
        if (s1[left++] != s1[right--])
            return false;
    }
    return true;
}

bool FancyIsPalindrome(std::string s1)
{

    std::transform(s1.begin(), s1.end(), s1.begin(), ::toupper);

    s1.erase(std::remove(s1.begin(), s1.end(), ' '), s1.end());

    int left = 0, right = s1.size();

    return std::equal(s1.begin(), s1.begin() + s1.size() / 2, s1.rbegin());
}

std::string DecimalToBinaryString(int decimalNumber)
{
    std::string binaryString = "0";

    if (decimalNumber > 0)
    {
        div_t dv{};
        dv.quot = decimalNumber;
        do
        {
            dv = div(dv.quot, 2);
            binaryString = std::to_string(dv.rem) + binaryString;
        } while (dv.quot);
    }
    return binaryString;
}

int BinaryStringToDecimal(std::string s1)
{

    int decNumber = 0, n;

    std::string::reverse_iterator it;

    for (it = s1.rbegin(), n = 0; it != s1.rend(); ++it, ++n)
    {
        char c = *it;
        if (c == '1')
            decNumber += std::pow(2, n);
    }
    return decNumber;
}

std::vector<std::string> GenerateSubsequences(std::string s1)
{

    std::vector<std::string> vecString;
    int strLen = s1.size();

    int bitCounter = std::pow(2, strLen);

    for (int i = 1; i < bitCounter; i++)
    {
        std::string subsequence = "";

        for (int j = 0; j < strLen; j++)
        {
            if (i & (1 << j))
                subsequence += s1[j];
        }

        vecString.push_back(subsequence);
    }

    return vecString;
}

bool IsSubSequence(std::string s1, std::string s2, int x, int y)
{

    if (x == 0)
        return true;
    if (y == 0)
        return false;

    if (s1[x - 1] == s2[y - 1])
        return IsSubSequence(s1, s2, x - 1, y - 1);

    else
        return IsSubSequence(s1, s2, x, y - 1);
}

std::vector<int> SearchPattern(std::string target, std::string pattern)
{

    std::vector<int> vecIndex;
    int strLen = target.size();
    int patLen = pattern.size();

    if (patLen <= strLen)
    {
        for (int i = 0; i <= strLen - patLen; i++)
        {
            int j;
            for (j = 0; j < patLen; j++)
            {
                if (target[i + j] != pattern[j])
                    break;
            }
            if (j == patLen)
                vecIndex.push_back(i);
        }
    }
    return vecIndex;
}