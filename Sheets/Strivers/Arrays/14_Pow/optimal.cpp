#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        double y = myPow(x, n / 2);
        if (n % 2 == 0)
            return y * y;
        else if (n < 0)
            return 1 / x * y * y;
        return x * y * y;
    }
};