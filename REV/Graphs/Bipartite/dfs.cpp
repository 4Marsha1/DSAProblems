class Solution
{
public:
    bool check(int node, vector<int> &color, vector<vector<int>> &graph)
    {
        if (color[node] == -1)
            color[node] = 0;
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                color[it] = !color[node];
                if (!check(it, color, graph))
                    return false;
            }
            else if (color[it] == color[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!check(i, color, graph))
                    return false;
            }
        }
        return true;
    }
};