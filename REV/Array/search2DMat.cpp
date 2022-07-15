bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int x = -1, n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        if (target <= matrix[i][m - 1])
        {
            x = i;
            break;
        }
    }
    if (x == -1)
        return false;
    for (int i = 0; i < m; i++)
        if (matrix[x][i] == target)
            return true;
    return false;
}