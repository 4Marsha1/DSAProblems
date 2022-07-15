// Good Solution

// keeping track with a map value
void func(vector<int> a, int n, vector<vector<int>> &ans, vector<int> res, vector<int> &map)
{
    if (res.size() == n)
    {
        ans.push_back(res);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (map[i] == -1)
        {
            map[i] = 1;
            res.push_back(a[i]);
            func(a, n, ans, res, map);
            res.pop_back();
            map[i] = -1;
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> res;
    vector<int> map(nums.size(), -1);
    func(nums, nums.size(), ans, res, map);
    return ans;
}

// Better--> SPACE OPTIMISED
void func(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if (idx >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        func(nums, idx + 1, ans);
        swap(nums[idx], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    func(nums, 0, ans);
    return ans;
}
