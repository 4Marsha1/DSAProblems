#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // largest in terms of frequency needs to go first ==> maxHeap

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[a[i]]++;

    priority_queue<pair<int, int>> maxHeap;
    vector<int> ans;
    for (auto i = freq.begin(); i != freq.end(); i++)
    {
        maxHeap.push({i->second, i->first});
    }

    while (!maxHeap.empty())
    {
        int cnt = maxHeap.top().first;
        while (cnt > 0)
        {
            ans.push_back(maxHeap.top().second);
            cnt--;
        }
        maxHeap.pop();
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}