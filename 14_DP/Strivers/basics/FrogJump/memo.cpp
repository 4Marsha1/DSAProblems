#include <bits/stdc++.h>
using namespace std;
int frog(int en[], int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int right = INT_MAX;
    int left = frog(en, n - 1, dp) + abs(en[n] - en[n - 1]);
    if (n > 1)
        right = frog(en, n - 2, dp) + abs(en[n] - en[n - 2]);
    return dp[n] = min(left, right);
}
int main()
{
    int n;
    cin >> n;
    int en[n];
    for (int i = 0; i < n; i++)
        cin >> en[i];
    vector<int> dp(n, -1);
    cout << frog(en, n - 1, dp);
}