#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    // Recursive Base Condition
    if (n == 0 || W == 0)
        return 0;
    // Choice Diagram
    if (wt[n - 1] <= W)
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
    else
        return knapSack(W, wt, val, n - 1);
}