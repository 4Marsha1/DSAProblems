void func(vector<int> arr, int idx, int n, vector<int> &sum, int s)
{
    if (idx == n)
    {
        sum.push_back(s);
        return;
    }
    func(arr, idx + 1, n, sum, s + arr[idx]);
    func(arr, idx + 1, n, sum, s);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> sum;
    func(arr, 0, N, sum, 0);
    sort(sum.begin(), sum.end());
    return sum;
}