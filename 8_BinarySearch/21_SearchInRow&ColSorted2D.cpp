#include <bits/stdc++.h>
using namespace std;

// start from the right corner
// if current element is key, return true
// else if current element > key, then key exists towards left---> hence j--
// else if current element < key, then key exists below ---> hence i++
bool search(vector<vector<int>> matrix, int n, int m, int x)
{
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        int current = matrix[i][j];
        if (current == x)
            return true;
        else if (current > x)
            j--;
        else
            i++;
    }
    return false;
}