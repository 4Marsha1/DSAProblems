#include <bits/stdc++.h>
using namespace std;

bool isCycle(int node, vector<int> &vis, vector<int> adj[])
{
    // node, prev
    queue<pair<int, int>> q;
    q.push({node, -1});
    vis[node] = 1;
    while (!q.empty())
    {
        int curr = q.front().first;
        int prev = q.front().second;
        q.pop();
        for (auto it : adj[curr])
        {
            if (!vis[it])
            {
                q.push({it, curr});
                vis[it] = 1;
            }
            else if (prev != it)
            {
                return true;
            }
        }
    }
    return false;
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
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (isCycle(i, vis, adj))
            {
                cout << "Cycle";
                return 0;
            }
        }
    }
    cout << "No Cycle";
    return 0;
}