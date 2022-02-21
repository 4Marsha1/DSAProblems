#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, key;
    cin >> n >> k >> key;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // K closest ====> K smallest in terms of difference
    priority_queue<pair<int, int>> maxHeap;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push({abs(key - a[i]), a[i]});
        if (maxHeap.size() > k)
            maxHeap.pop();
    }
    while (!maxHeap.empty())
    {
        cout << maxHeap.top().second << " ";
        maxHeap.pop();
    }
}