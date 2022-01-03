#include <bits/stdc++.h>
using namespace std;

// hashing
int getPairsCount(int arr[], int n, int k)
{
    // map to store frequency
    unordered_map<int, int> map;
    int cnt = 0;
    // update the frequency
    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    for (int i = 0; i < n; i++)
    {
        cnt += map[k - arr[i]];
        if (k - arr[i] == arr[i])
            cnt--;
    }
    // divide by 2, as we counted pairs twice
    return cnt / 2;
}

// more efficient hashing
int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> map;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (map.find(k - arr[i]) != map.end())
            cnt += map[k - arr[i]];
        map[arr[i]]++;
    }
    return cnt;
}