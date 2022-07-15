#include <bits/stdc++.h>
using namespace std;

int fOccInf(vector<int> a, int start, int end)
{
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (a[mid] == 1)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (a[mid] > 1)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int start = 0, end = 1;
    while (a[end] != 1)
    {
        start = end;
        end = end * 2;
    }
    cout << fOccInf(a, start, end);
}