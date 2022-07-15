#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int en[n];
    for (int i = 0; i < n; i++)
        cin >> en[i];
    vector<int> dp(n);
    int left, right = INT_MAX;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        left = dp[i - 1] + abs(en[i] - en[i - 1]);
        if (i > 1)
            right = dp[i - 2] + abs(en[i] - en[i - 2]);
        dp[i] = min(left, right);
    }
    cout << dp[n - 1];
}