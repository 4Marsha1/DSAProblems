#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
        minHeap.push(a[i]);

    int ans = 0;
    while (minHeap.size() > 1)
    {
        int x = minHeap.top();
        minHeap.pop();
        int y = minHeap.top();
        minHeap.pop();
        ans += x + y;
        minHeap.push(x + y);
    }
    cout << ans;
}