bool subArrayExists(int arr[], int n)
{
    unordered_map<int, int> map;
    int curSum = 0;
    for (int i = 0; i < n; i++)
    {
        curSum += arr[i];
        if (curSum == 0)
            return true;
        if (map.find(curSum) != map.end())
            return true;
        map[curSum] = i;
    }
    return false;
}