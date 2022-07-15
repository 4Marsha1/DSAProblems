int fidx(vector<int> &arr, int idx, int n, int x)
{
    if (idx == n)
        return -1;
    if (arr[idx] == x)
        return idx;
    return fidx(arr, idx + 1, n, x);
}
int lidx(vector<int> &arr, int idx, int n, int x)
{
    if (idx == n)
        return -1;
    int lx = lidx(arr, idx + 1, n, x);
    if (lx != -1)
        return lx;
    else
    {
        if (arr[idx] == x)
            return idx;
        return -1;
    }
}
vector<int> firstAndLast(vector<int> &arr, int n, int x)
{
    int f = fidx(arr, 0, n, x);
    int l = lidx(arr, 0, n, x);
    if (f == -1)
        return {l};
    if (l == -1)
        return {f};
    return {f, l};
}