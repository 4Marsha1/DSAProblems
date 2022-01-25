#include <bits/stdc++.h>
using namespace std;

// 1. --------- Single recursive Call
// sum of 1-N
int sum_recursion(int n)
{
    if (n == 0)
        return 0;
    return n + sum_recursion(n - 1);
}

// N!
int factorial_recursion(int n)
{
    if (n == 1)
        return 1;
    return n * factorial_recursion(n - 1);
}

// 2. ------ Multiple recursive calls
int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    int last = fibonacci(n - 1);       // Left Call
    int secondLast = fibonacci(n - 2); // Right Call
    return last + secondLast;
}

int main()
{
    int n;
    cin >> n;
    cout << sum_recursion(n) << endl;
    cout << factorial_recursion(n) << endl;
}