#include <bits/stdc++.h>
using namespace std;

int st[5];
int top = -1;

void push(int x)
{
    top++;
    st[top] = x;
}
int pop()
{
    if (top == -1)
        return -1;
    int x = st[top];
    top--;
    return x;
}
int Top()
{
    if (top == -1)
        return -1;
    return st[top];
}
int size()
{
    return top + 1;
}
bool empty()
{
    return top == -1;
}

int main()
{
    push(1);
    push(2);
    push(3);
    cout << Top() << endl;
    cout << pop() << endl;
    cout << Top() << endl;
    cout << empty() << endl;
    cout << size() << endl;
}