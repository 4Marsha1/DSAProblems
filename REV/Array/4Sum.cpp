vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    if (nums.size() == 0)
        return ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int l = j + 1, r = n - 1;
            long newTarget = (long)target - nums[i] - nums[j];
            while (l < r)
            {
                if (nums[l] + nums[r] == newTarget)
                {
                    vector<int> temp(4);
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[l];
                    temp[3] = nums[r];
                    ans.push_back(temp);
                    while (l < r && nums[l] == temp[2])
                        ++l;
                    while (l < r && nums[r] == temp[3])
                        --r;
                }
                else if (nums[l] + nums[r] > newTarget)
                    --r;
                else
                    ++l;
            }
            while (j + 1 < n && nums[j] == nums[j + 1])
                ++j;
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
            ++i;
    }
    return ans;
}