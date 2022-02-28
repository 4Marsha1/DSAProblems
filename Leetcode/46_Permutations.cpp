
// https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>
using namespace std;

void permutation(vector<int> nums, int idx, vector<vector<int>> &ans)
{
    if (idx >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int j = idx; j < nums.size(); j++)
    {
        swap(nums[idx], nums[j]);
        permutation(nums, idx + 1, ans);
        swap(nums[idx], nums[j]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    permutation(nums, 0, ans);
    return ans;
}