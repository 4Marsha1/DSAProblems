#include <bits/stdc++.h>
using namespace std;

int q[5];
int n = 5;
int front = 0, rear = 0, cnt = 0;

void push(int x)
{
    if (cnt == n)
        cout << "Full" << endl;
    q[rear % n] = x;
    rear++;
    cnt++;
}
int pop()
{
    if (cnt == 0)
        return -1;
    int x = q[front % n];
    q[front % n] = -1;
    front++;
    cnt--;
    return x;
}
int Top()
{
    if (cnt == 0)
        return -1;
    return q[front % n];
}
int size()
{
    return cnt;
}
bool empty()
{
    return cnt == 0;
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