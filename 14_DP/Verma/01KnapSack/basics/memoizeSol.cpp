#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    // Base Condition
    if (n == 0 || W == 0)
        return 0;
    // Check if value already Exists -------> Memoization
    if (dp[n][W] != -1)
        return dp[n][W];
    // Choice Diagram
    if (wt[n - 1] <= W)
        return dp[n][W] = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1, dp), knapsack(W, wt, val, n - 1, dp));
    else
        return dp[n][W] = knapsack(W, wt, val, n - 1, dp);
}
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return knapsack(W, wt, val, n, dp);
}