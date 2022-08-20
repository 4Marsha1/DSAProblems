// RECURSION
int frog(int a[], int n, int k)
{
    if (n == 0)
        return 0;
    int val = INT_MAX;
    for (int i = 1; i <= k; i++)
        if (n >= i)
            val = min(val, frog(a, n - i, k) + abs(a[n] - a[n - i]));
    return val;
}

// MEMOIZATION (TOP DOWN)
int frog(int a[], int n, int k, vector<int> &dp)
{
    if (n == 0)
        return dp[0] = 0;
    if (dp[n] != -1)
        return dp[n];
    int val = INT_MAX;
    for (int i = 1; i <= k; i++)
        if (n >= i)
            val = min(val, frog(a, n - i, k, dp) + abs(a[n] - a[n - i]));
    return dp[n] = val;
}

// TABULATIOn (BOTTOM UP)

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int val = INT_MAX;
        for (int j = 1; j <= k; j++)
            if (i >= j)
                val = min(val, dp[i - j] + abs(a[i] - a[i - j]));
        dp[i] = val;
    }
    cout << dp[n - 1];
}