#include <bits/stdc++.h>
using namespace std;

bool printOneS(int a[], int ind, int sum, int target, int n, vector<int> &ds)
{
    // base case
    if (ind == n)
    {
        if (sum == target)
        {
            for (auto x : ds)
                cout << x << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    // Dont Pick
    if (printOneS(a, ind + 1, sum, target, n, ds) == true)
        return true;

    // Pick
    sum += a[ind];
    ds.push_back(a[ind]);
    if (printOneS(a, ind + 1, sum, target, n, ds) == true)
        return true;
    sum -= a[ind];
    ds.pop_back();

    return false;
}

int main()
{
    int n, target;
    cin >> n >> target;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ds;
    printOneS(a, 0, 0, target, n, ds);
}