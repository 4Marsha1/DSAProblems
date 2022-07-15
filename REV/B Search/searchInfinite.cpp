#include <bits/stdc++.h>
using namespace std;

int bInf(vector<int> a, int start, int end, int k)
{
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (a[mid] == k)
            return mid;
        else if (a[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int start = 0, end = 1;
    while (a[end] < k)
    {
        start = end;
        end = end * 2;
    }
    cout << bInf(a, start, end, k);
}