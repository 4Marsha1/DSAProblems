#include <bits/stdc++.h>
using namespace std;

bool safeSpot(vector<vector<int>> chess, int row, int col)
{
    // For a cell to be safe:
    // No Queen vertically, and both diagonally

    //  Check for vertical
    for (int i = row - 1, j = col; i >= 0; i--)
    {
        if (chess[i][j] == 1)
            return false;
    }
    //  Check for left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (chess[i][j] == 1)
            return false;
    }
    // Check for right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++)
    {
        if (chess[i][j] == 1)
            return false;
    }
    // If safe, return true
    return true;

    // Dont check for same row and below cells
}

void printNQueens(vector<vector<int>> chess, string qsf, int row)
{
    // base case
    if (row == chess.size())
    {
        cout << qsf + "." << endl;
        return;
    }

    // ROW as NODES and COL as EDGES
    for (int col = 0; col < chess.size(); col++)
    {
        // Check is its a safe cell
        if (safeSpot(chess, row, col) == true)
        {
            // Place the Queen
            chess[row][col] = 1;
            // ADD THE PATH & move to next row
            printNQueens(chess, qsf + to_string(row) + "-" + to_string(col) + ", ", row + 1);
            // On RETURNING Remove the QUEEN
            chess[row][col] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> chess(n, vector<int>(n));

    printNQueens(chess, "", 0);
}