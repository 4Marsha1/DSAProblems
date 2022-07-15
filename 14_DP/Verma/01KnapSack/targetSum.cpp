#include <bits/stdc++.h>
using namespace std;

int subset(vector<int> arr, int n, int sum)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][sum];
}
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];
    if (sum < abs(target) || (target + sum) % 2 != 0)
        return 0;
    int newTarget = (sum - target) / 2;
    return subset(nums, n, newTarget);
}