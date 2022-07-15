class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n == 0)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int left = i + 1, right = n - 1;
            int target = -1 * nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] == target)
                {
                    vector<int> temp(3);
                    temp[0] = nums[i];
                    temp[1] = nums[left];
                    temp[2] = nums[right];
                    ans.push_back(temp);
                    while (left < right && nums[left] == temp[1])
                        ++left;
                    while (left < right && nums[right] == temp[2])
                        --right;
                }
                else if (nums[left] + nums[right] > target)
                    --right;
                else
                    left++;
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                ++i;
        }
        return ans;
    }
};