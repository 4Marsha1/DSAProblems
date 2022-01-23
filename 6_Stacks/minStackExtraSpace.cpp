#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> s;
    stack<int> ss;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        s.push(val);
        if (ss.empty() || val <= ss.top())
            ss.push(val);
    }

    void pop()
    {
        if (!ss.empty() && !s.empty())
            if (s.top() == ss.top())
                ss.pop();
        if (!s.empty())
            s.pop();
    }

    int top()
    {
        if (s.empty())
            return -1;
        return s.top();
    }

    int getMin()
    {
        if (ss.empty())
            return -1;
        return ss.top();
    }
};