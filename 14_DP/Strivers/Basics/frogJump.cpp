// RECURSION
int func(int idx, vector<int> &en)
{
    if (idx == 0)
        return 0;
    int right = 1000000000;
    int left = func(idx - 1, en) + abs(en[idx] - en[idx - 1]);
    if (idx > 1)
        right = func(idx - 2, en) + abs(en[idx] - en[idx - 2]);
    return min(left, right);
}
int frogJump(int n, vector<int> &en) return func(n - 1, en);

// MEMOIZATION (TOP DOWN)
int func(int idx, vector<int> &en, vector<int> &dp)
{
    if (idx == 0)
        return dp[0] = 0;
    if (dp[idx] != -1)
        return dp[idx];
    int right = 1000000000;
    int left = func(idx - 1, en, dp) + abs(en[idx] - en[idx - 1]);
    if (idx > 1)
        right = func(idx - 2, en, dp) + abs(en[idx] - en[idx - 2]);
    return dp[idx] = min(left, right);
}
int frogJump(int n, vector<int> &en)
{
    vector<int> dp(n, -1);
    return func(n - 1, en, dp);
}

// TABULATION (BOTTOM UP)
int frogJump(int n, vector<int> &en)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int right = 1000000000;
        int left = dp[i - 1] + abs(en[i] - en[i - 1]);
        if (i > 1)
            right = dp[i - 2] + abs(en[i] - en[i - 2]);
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}