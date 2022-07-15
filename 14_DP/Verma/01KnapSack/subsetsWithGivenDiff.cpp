#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int> arr, vector<vector<int>> &dp, int n, int sum)
{
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;
    for (int j = 1; j < sum + 1; j++)
        dp[0][j] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}

int main()
{
    vector<int> arr;
    int n, diff;
    cin >> n >> diff;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    };

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    subsets(arr, dp, n, sum);

    vector<int> range;
    for (int i = 0; i < (sum + 1) / 2; i++)
        if (dp[n][i] > 0)
            range.push_back(i);
    int cnt = 0;
    for (int i = 0; i < range.size(); i++)
    {
        if (sum - 2 * range[i] == diff)
            cnt += dp[n][i];
    }
    cout << cnt;
}