#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int x = -1;
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (target <= matrix[i][matrix[i].size() - 1])
            {
                x = i;
                break;
            }
        }
        if (x != -1)
        {
            for (int i = 0; i < matrix[x].size(); ++i)
            {
                if (matrix[x][i] == target)
                    return true;
            }
        }
        return false;
    }
};