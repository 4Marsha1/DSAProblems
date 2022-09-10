class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<int> cnt(n, 0);
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < roads.size(); i++)
        {
            cnt[roads[i][0]]++;
            cnt[roads[i][1]]++;
            graph[roads[i][0]][roads[i][1]] = 1;
            graph[roads[i][1]][roads[i][0]] = 1;
        }
        int ans = 0;
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph.size(); j++)
            {
                if (i != j)
                {
                    int rank = cnt[i] + cnt[j] - graph[i][j];
                    ans = max(ans, rank);
                }
            }
        }
        return ans;
    }
};