// RECURSION
int climbStairs(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

// MEMOIZATION (TOP DOWN)
int func(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return func(n, dp);
}

// TABULATION (BOTTOM UP)
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}