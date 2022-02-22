#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // minHeap, as the smallest element needs to go first

    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(a[i]);
        if (minHeap.size() > k)
        {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
    }

    while (!minHeap.empty())
    {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}