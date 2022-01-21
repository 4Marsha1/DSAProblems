#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++)
        set.insert(nums[i]);
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (set.find(nums[i] + 1) != set.end())
            continue;
        else
        {
            int cnt = 1;
            int currentElem = nums[i];
            while (set.find(currentElem - 1) != set.end())
            {
                currentElem -= 1;
                cnt++;
            }
            maxLen = max(maxLen, cnt);
        }
    }
    return maxLen;
}