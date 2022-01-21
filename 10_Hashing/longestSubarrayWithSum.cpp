#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSum(int a[], int n, int k)
{
    unordered_map<int, int> map;
    int start = 0, end = -1, curSum = 0, maxLen = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curSum += a[i];
        if (curSum == k)
        {
            start = 0;
            end = i;
            maxLen = max(maxLen, end - start + 1);
        }
        if (map.find(curSum - k) != map.end())
        {
            start = map[curSum - k] + 1;
            end = i;
            maxLen = max(maxLen, end - start + 1);
        }
        map[curSum] = i;
    }
    if (end == -1)
        return -1;
    return maxLen;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << longestSubarrayWithSum(a, n, k);
}