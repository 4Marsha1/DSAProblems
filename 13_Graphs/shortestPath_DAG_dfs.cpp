#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            topoSort(it.first, adj, vis, st);
        }
    }
    st.push(node);
}

void shortestPath(stack<int> &st, vector<pair<int, int>> adj[], int V)
{
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + it.second < dist[it.first])
            {
                dist[it.first] = dist[node] + it.second;
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
    vector<int> vis(n + 1, 0);
    stack<int> st;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topoSort(i, adj, vis, st);
        }
    }
    shortestPath(st, adj, n);
}