#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int ind = abs(nums[i]) - 1;
        if (nums[ind] > 0)
            nums[ind] = -nums[ind];
    }
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            ans.push_back(i + 1);
    }
    return ans;
}