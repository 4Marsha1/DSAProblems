#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
        mn = min(mn, nums[i]);
    for (int i = 0; i < n; i++)
        nums[i] += abs(mn);
    for (int i = 0; i < n; i++)
        sum += nums[i];
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int diff = INT_MAX;
    vector<int> range;
    for (int i = 0; i < sum + 1; i++)
        if (dp[n][i] == true)
            range.push_back(i);
    for (int i = 0; i < range.size(); i++)
        diff = min(diff, abs(sum - 2 * range[i]));

    return diff;
}