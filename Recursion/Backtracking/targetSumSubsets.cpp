#include <bits/stdc++.h>
using namespace std;

// Pick / Dont Pick Method

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar)
{
    if (idx == arr.size())
    {
        if (sos == tar)
        {
            cout << set + "." << endl;
        }
        return;
    }
    // Pick
    printTargetSumSubsets(arr, idx + 1, set + to_string(arr[idx]) + ", ", sos + arr[idx], tar);
    // Dont Pick
    printTargetSumSubsets(arr, idx + 1, set, sos, tar);
}

int main()
{
    int n, target;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cin >> target;
    printTargetSumSubsets(arr, 0, "", 0, target);
}