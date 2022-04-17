#include <cppDSA>
#include <iostream>

/* Note we use here the framework from leetcode and the DS Stack from here.
Personnaly I don't like the algorithm given in this book for this problem. :) */

using namespace std;

bool helper(char c1, char c2)
{
    if (c1 == '(' && c2 == ')')
        return true;
    if (c1 == '{' && c2 == '}')
        return true;
    if (c1 == '[' && c2 == ']')
        return true;
    return false;
}

bool IsValid(char expression[])
{
    int n = strlen(expression);
    Stack<char> st = Stack<char>();

    for (int i = 0; i < n; i++)
    {
        if (st.size() != 0)
        {
            char li = st.Top();
            if (helper(li, expression[i]))
            {
                st.Pop();
                continue;
            }
        }
        st.Push(expression[i]);
    }

    return st.size() == 0;
}

int main()
{
    char expr[1000];
    cout << "Please type the parenthesis expression ";
    cout << "then press ENTER!" << endl;
    cin >> expr;

    bool bo = IsValid(expr);

    cout << endl;
    cout << "The " << expr << " expression is ";
    if (bo)
        cout << "valid";
    else
        cout << "invalid";
    cout << endl;

    return 0;
}