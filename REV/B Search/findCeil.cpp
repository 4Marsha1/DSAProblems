int ceilingInSortedArray(int n, int x, vector<int> &a)
{
    int start = 0, end = n - 1, ans = -1;
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (a[mid] == x)
            return a[mid];
        else if (a[mid] < x)
            start = mid + 1;
        else
        {
            ans = a[mid];
            end = mid - 1;
        }
    }
    return ans;
}
