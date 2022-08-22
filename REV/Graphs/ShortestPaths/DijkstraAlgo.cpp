#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, INT_MAX);

    dis[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int currentDis = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for (auto it : adj[prev])
        {
            int next = it.first;
            int nextDis = it.second;
            if (dis[next] > currentDis + nextDis)
            {
                dis[next] = currentDis + nextDis;
                pq.push({dis[next], next});
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << i << " " << dis[i] << endl;
}