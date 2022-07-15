oid func(vector<int> nums, int idx, int n, vector<vector<int>> &ans, vector<int> res)
{
    ans.push_back(res);
    for (int i = idx; i < n; i++)
    {
        if (i > idx && nums[i] == nums[i - 1])
            continue;
        res.push_back(nums[i]);
        func(nums, i + 1, n, ans, res);
        res.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> res;
    sort(nums.begin(), nums.end());
    func(nums, 0, nums.size(), ans, res);
    return ans;
}