#include <bits/stdc++.h>
using namespace std;

void shortestPath(int V, vector<int> adj[], vector<int> &ans)
{
    queue<int> q;
    q.push(0);
    ans[0] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        int currDistance = ans[node];
        for (auto it : adj[node])
            if (currDistance + 1 < ans[it])
            {
                ans[it] = currDistance + 1;
                q.push(it);
            }
    }
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
    vector<int> ans(n, INT_MAX);
    shortestPath(n, adj, ans);
    for (auto it : ans)
        cout << it << " ";
}