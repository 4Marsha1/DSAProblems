void func(vector<int> nums, int idx, int n, vector<vector<int>> &ans, vector<int> res)
{
    if (idx == n)
    {
        ans.push_back(res);
        return;
    }
    res.push_back(nums[idx]);
    func(nums, idx + 1, n, ans, res);
    res.pop_back();
    func(nums, idx + 1, n, ans, res);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> res;
    func(nums, 0, nums.size(), ans, res);
    return ans;
}