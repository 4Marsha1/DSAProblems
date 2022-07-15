#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int en[n];
    for (int i = 0; i < n; i++)
        cin >> en[i];
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int mn = INT_MAX;
        for (int j = 1; j <= k; j++)
            if (i >= j)
                mn = min(mn, dp[i - j] + abs(en[i] - en[i - j]));
        dp[i] = mn;
    }
    cout << dp[n - 1];
}