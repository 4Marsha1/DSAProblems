#include <bits/stdc++.h>
using namespace std;

void shortestPath(int src, vector<pair<int, int>> adj[], int V)
{
    vector<int> dist(V, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + it.second < dist[it.first])
            {
                dist[it.first] = dist[node] + it.second;
                q.push(it.first);
            }
        }
    }
    for (int i = 0; i < V; i++)
        cout << dist[i] << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    shortestPath(0, adj, n);
}