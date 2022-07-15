void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    // BRUTE FORCE
    vector<vector<int>> dup(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            dup[j][m - i - 1] = matrix[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            matrix[i][j] = dup[i][j];
    }

    // BETTER
    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
    // reverse rows
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}