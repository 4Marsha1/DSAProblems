#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        int N = abs(n);
        if (n >= 0)
            for (int i = 0; i < N; i++)
                ans = ans * x;
        else
            for (int i = 0; i < N; i++)
                ans = ans * (1 / x);
        return ans;
    }
};
