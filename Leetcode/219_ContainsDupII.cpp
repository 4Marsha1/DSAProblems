
// https://leetcode.com/problems/contains-duplicate-ii/

#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(nums[i]) != map.end())
        {
            if (abs(i - map[nums[i]]) <= k)
                return true;
        }
        map[nums[i]] = i;
    }
    return false;
}