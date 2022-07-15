#include <bits/stdc++.h>
using namespace std;

void dfsOfGraph(int node, vector<int> &vis, vector<int> adj[], vector<int> &ans)
{
    ans.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            dfsOfGraph(it, vis, adj, ans);
}
vector<int> dfs(int v, vector<int> adj[])
{
    vector<int> ans;
    vector<int> vis(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
            dfsOfGraph(i, vis, adj, ans);
    }
    return ans;
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
    vector<int> ans = dfs(m, adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}