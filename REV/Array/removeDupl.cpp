class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        int i = 0, j = 1, cnt = 1;
        while (j < nums.size())
        {
            if (nums[i] == nums[j])
                j++;
            else
            {
                i++;
                nums[i] = nums[j];
                cnt++;
            }
        }
        return cnt;
    }
};