int findFloor(vector<long long> a, long long n, long long key)
{
    long long start = 0, end = n - 1, ans = -1;
    while (start <= end)
    {
        long long mid = (start + (end - start) / 2);
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            end = mid - 1;
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}