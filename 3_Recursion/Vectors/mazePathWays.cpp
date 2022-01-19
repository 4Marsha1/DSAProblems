#include <bits/stdc++.h>
using namespace std;

int getMazePathsWays(int n, int m)
{
    if (n == 1 || m == 1)
        return 1;
    return getMazePathsWays(n - 1, m) + getMazePathsWays(n, m - 1);
}

int main()
{
    int n = 3, m = 3;
    cout << getMazePathsWays(n, m);
}