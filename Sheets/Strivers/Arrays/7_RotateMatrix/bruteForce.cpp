#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        vector<vector<int>> ans;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int j = m - 1; j >= 0; --j)
            {
                temp.push_back(matrix[j][i]);
            }
            ans.push_back(temp);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                matrix[i][j] = ans[i][j];
            }
        }
    }
};