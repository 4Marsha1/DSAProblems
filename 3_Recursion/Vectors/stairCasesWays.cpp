#include <bits/stdc++.h>
using namespace std;

int getPathsWays(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 4;
    return getPathsWays(n - 1) + getPathsWays(n - 2) + getPathsWays(n - 3);
}

int main()
{
    int n = 3;
    cout << getPathsWays(n);
}