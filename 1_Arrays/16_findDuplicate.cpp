#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int ind = abs(nums[i]);
        if (nums[ind] < 0)
            return ind;
        else
            nums[ind] = -1 * nums[ind];
    }
    return 1;
}