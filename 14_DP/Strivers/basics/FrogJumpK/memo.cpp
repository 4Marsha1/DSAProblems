#include <bits/stdc++.h>
using namespace std;
int frog(int en[], int n, int k, int mn, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    for (int i = 1; i <= k; i++)
    {
        if (n >= i)
        {
            mn = min(mn, frog(en, n - i, k, mn, dp) + abs(en[n] - en[n - i]));
        }
    }
    return dp[n] = mn;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int en[n];
    for (int i = 0; i < n; i++)
        cin >> en[i];
    vector<int> dp(n, -1);
    int mn = INT_MAX;
    cout << frog(en, n - 1, k, mn, dp);
}