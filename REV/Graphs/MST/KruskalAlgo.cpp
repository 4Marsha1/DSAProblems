#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u;
    int v;
    int wt;
    node(int a, int b, int c)
    {
        u = a;
        v = b;
        wt = c;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int node, vector<int> &parent)
{
    if (node == parent[node])
        return node;
    return parent[node] = findPar(parent[node], parent);
}

void unioN(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else
        parent[v] = u;
    rank[u]++;
}

// TC--> O(NlogN), SC--> O(N)
int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(node(u, v, w));
    }
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findPar(it.v, parent) != findPar(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unioN(it.u, it.v, parent, rank);
        }
    }
    cout << cost << endl;
    for (auto it : mst)
        cout << it.first << " - " << it.second << endl;
}