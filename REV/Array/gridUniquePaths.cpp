// DP Solution ----> O(nxm) & O(nxm)
int count(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i == m - 1 || j == n - 1)
        return dp[i][j] = 1;
    if (i >= m || j >= n)
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = count(i + 1, j, m, n, dp) + count(i, j + 1, m, n, dp);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return count(0, 0, m, n, dp);
}

// Combinations Solution --> O(n-1) & O(1)
int uniquePaths(int m, int n)
{
    int C = m + n - 2, R = m - 1;
    double ans = 1;
    for (int i = 1; i <= R; i++)
    {
        ans = ans * (C - R + i) / i;
    }
    return (int)ans;
}