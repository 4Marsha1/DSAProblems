#include <bits/stdc++.h>
using namespace std;

void print1N(int i, int n)
{
    if (i > n)
        return;
    cout << i << " ";
    print1N(i + 1, n);
}

void printN1(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printN1(n - 1);
}

void print1Nbacktrack(int n)
{
    if (n == 0)
        return;
    print1Nbacktrack(n - 1);
    cout << n << " ";
}

void printN1backtrack(int i, int n)
{
    if (i > n)
        return;
    printN1backtrack(i + 1, n);
    cout << i << " ";
}

int main()
{
    int n;
    cin >> n;
    print1N(1, n);
    cout << endl;
    printN1(n);
    cout << endl;
    print1Nbacktrack(n);
    cout << endl;
    printN1backtrack(1, n);
    cout << endl;
}