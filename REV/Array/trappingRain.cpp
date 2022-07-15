class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int maxL[n], maxR[n];
        maxL[0] = height[0];
        maxR[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
            maxL[i] = max(height[i], maxL[i - 1]);
        for (int i = n - 2; i >= 0; i--)
            maxR[i] = max(height[i], maxR[i + 1]);
        int maxW = 0;
        for (int i = 0; i < n; i++)
            maxW += (min(maxL[i], maxR[i]) - height[i]);
        return maxW;
    }
};