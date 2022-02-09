#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> nums);
int BS(vector<int> nums, int start, int end, int k);

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int idx = findMin(nums);
    int left = BS(nums, 0, idx - 1, target);
    int right = BS(nums, idx, n - 1, target);
    return max(left, right);
}

int findMin(vector<int> nums)
{
    int n = nums.size();
    if (nums[0] < nums[n - 1])
        return 0;
    int start = 0, end = n - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] < nums[end])
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}
int BS(vector<int> nums, int start, int end, int k)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == k)
            return mid;
        else if (nums[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}