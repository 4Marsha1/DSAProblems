#include <bits/stdc++.h>
using namespace std;

// using stack
bool ispar(string s)
{
    // Your code here
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] == ')' || s[i] == '}' || s[i] == ']') && st.empty())
            return false;
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        if (s[i] == ')')
        {
            if (st.top() == '(')
                st.pop();
            else
                return false;
        }
        if (s[i] == '}')
        {
            if (st.top() == '{')
                st.pop();
            else
                return false;
        }
        if (s[i] == ']')
        {
            if (st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}
