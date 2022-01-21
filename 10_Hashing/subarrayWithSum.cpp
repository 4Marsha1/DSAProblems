#include <bits/stdc++.h>
using namespace std;

void subarrayWithSum(int a[], int n, int k)
{
    unordered_map<int, int> map;
    int start = 0, end = -1, curSum = 0;
    for (int i = 0; i < n; i++)
    {
        curSum += a[i];
        if (curSum == k)
        {
            start = 0;
            end = i;
            break;
        }
        if (map.find(curSum - k) != map.end())
        {
            start = map[curSum - k] + 1;
            end = i;
            break;
        }
        map[curSum] = i;
    }
    if (end == -1)
        cout << "Not found" << endl;
    else
        cout << start << " " << end;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    subarrayWithSum(a, n, k);
}