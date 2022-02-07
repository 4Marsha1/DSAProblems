#include <bits/stdc++.h>
using namespace std;

void printAllS(int a[], int ind, int sum, int target, int n, vector<int> &ds)
{
    // base case
    if (ind == n)
    {
        if (sum == target)
        {
            for (auto x : ds)
                cout << x << " ";
            cout << endl;
        }
        return;
    }
    // Dont Pick
    printAllS(a, ind + 1, sum, target, n, ds);

    // Pick
    sum += a[ind];
    ds.push_back(a[ind]);
    printAllS(a, ind + 1, sum, target, n, ds);
    sum -= a[ind];
    ds.pop_back();
}

int main()
{
    int n, target;
    cin >> n >> target;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ds;
    printAllS(a, 0, 0, target, n, ds);
}