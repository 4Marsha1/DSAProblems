class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = (start + (end - start) / 2);
            // Index 1 to n-2 (non edge case)
            if (mid > 0 && mid < n - 1)
            {
                // if mid element is greatet than both neighbours
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                    return mid;
                // else if left element is greater, then left side is promising
                else if (nums[mid - 1] > nums[mid])
                    end = mid - 1;
                // else if right element is greater, then right side is promising
                else if (nums[mid + 1] > nums[mid])
                    start = mid + 1;
            }
            // edge cases
            else if (mid == 0)
            {
                if (nums[0] > nums[1])
                    return 0;
                else
                    return 1;
            }
            else if (mid == n - 1)
            {
                if (nums[n - 1] > nums[n - 2])
                    return n - 1;
                else
                    return n - 2;
            }
        }
        return -1;
    }
};