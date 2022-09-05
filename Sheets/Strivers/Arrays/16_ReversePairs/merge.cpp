class Solution
{
public:
    int mergesort(int l, int r, vector<int> &arr, vector<int> &temp)
    {
        if (l >= r)
        {
            return 0;
        }
        int mid = l + ((r - l) / 2);
        int ans = mergesort(l, mid, arr, temp);
        ans += mergesort(mid + 1, r, arr, temp);
        ans += merge(l, mid + 1, r, arr, temp);
        return ans;
    }
    int merge(int l, int mid, int r, vector<int> &arr, vector<int> &temp)
    {
        int i = l, j = mid, k = l;
        int ans = 0;
        while (i <= mid - 1 && j <= r)
        {
            if (arr[i] / 2 + max(0, arr[i] % 2) <= arr[j])
            {
                i++;
            }
            else
            {
                ans += mid - i;
                j++;
            }
        }
        i = l;
        j = mid;
        while (i <= mid - 1 && j <= r)
        {
            if (arr[i] < arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid - 1)
            temp[k++] = arr[i++];
        while (j <= r)
            temp[k++] = arr[j++];
        for (int idx = l; idx <= r; idx++)
            arr[idx] = temp[idx];
        return ans;
    }
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp(n);
        return mergesort(0, n - 1, nums, temp);
    }
};