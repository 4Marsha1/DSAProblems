#include <bits/stdc++.h>
using namespace std;

void shortestPath(int src, vector<int> adj[], int V)
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
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
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
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    shortestPath(0, adj, n);
}