#include <bits/stdc++.h>
using namespace std;

int largestSub01(int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] == 0)
            a[i] = -1;
    unordered_map<int, int> map;
    int maxLen = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0)
            maxLen = i + 1;
        else
        {
            if (map.find(sum) != map.end())
                maxLen = max(maxLen, i - map[sum]);
            else
                map[sum] = i;
        }
    }
    return maxLen;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << largestSub01(a, n);
}