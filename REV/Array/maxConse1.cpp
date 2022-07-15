class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int len = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            len++;
            if (nums[i] == 0)
                len = 0;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};