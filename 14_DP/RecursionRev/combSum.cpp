void func(vector<int> a, int n, vector<int> res, int idx, int k, vector<vector<int>> &ans)
{
    if (idx == n)
    {
        if (k == 0)
            ans.push_back(res);
        return;
    }
    if (a[idx] <= k)
    {
        res.push_back(a[idx]);
        func(a, n, res, idx, k - a[idx], ans);
        res.pop_back();
    }
    func(a, n, res, idx + 1, k, ans);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> res;
    func(candidates, candidates.size(), res, 0, target, ans);
    return ans;
}