#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // K Top frequent ====> K Largest in terms of frequency

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[a[i]]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (auto i = freq.begin(); i != freq.end(); i++)
    {
        minHeap.push({i->second, i->first});
        if (minHeap.size() > k)
            minHeap.pop();
    }

    while (!minHeap.empty())
    {
        cout << minHeap.top().second << " ";
        minHeap.pop();
    }
}