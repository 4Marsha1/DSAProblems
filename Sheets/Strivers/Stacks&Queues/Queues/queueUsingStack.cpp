// 2 STACKS
class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int x = s1.top();
        s1.pop();
        return x;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

// O(1) AMORTISED
class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (!s2.empty())
        {
            int x = s2.top();
            s2.pop();
            return x;
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            int x = s2.top();
            s2.pop();
            return x;
        }
    }

    int peek()
    {
        if (!s2.empty())
        {
            return s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};