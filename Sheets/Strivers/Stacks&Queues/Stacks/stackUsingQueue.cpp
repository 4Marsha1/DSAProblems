// 2 QUEUES
class MyStack
{
public:
    queue<int> q1, q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop()
    {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

// 1 QUEUE
class MyStack
{
public:
    queue<int> q1;
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
        for (int i = 0; i < q1.size() - 1; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop()
    {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};