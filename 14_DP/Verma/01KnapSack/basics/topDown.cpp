#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    // Initialization ----> Recursion base condition
    for (int i = 0; i < n + 1; ++i)
        dp[i][0] = 0;
    for (int j = 0; j < W + 1; ++j)
        dp[0][j] = 0;
    // Choice Diagram
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < W + 1; ++j)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}