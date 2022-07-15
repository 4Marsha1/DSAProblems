void func(vector<int> a, int idx, int n, vector<vector<int>> &ans, vector<int> res, int k)
{
    if (k == 0)
    {
        ans.push_back(res);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (i > idx && a[i] == a[i - 1])
            continue;
        if (a[i] > k)
            break;
        res.push_back(a[i]);
        func(a, i + 1, n, ans, res, k - a[i]);
        res.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> res;
    sort(candidates.begin(), candidates.end());
    func(candidates, 0, candidates.size(), ans, res, target);
    return ans;
}