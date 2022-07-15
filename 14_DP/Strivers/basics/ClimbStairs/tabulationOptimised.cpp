class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1);
        int prev = 1;
        int prev2 = 1;
        for (int i = 2; i <= n; i++)
        {
            int cur = prev2 + prev;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};