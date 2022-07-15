#include <bits/stdc++.h>
using namespace std;

bool subsEqualK(int a[], int idx, int n, vector<int> &ans, int k, int sum)
{
    if (idx == n)
    {
        if (sum == k)
        {
            for (auto it : ans)
                cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    ans.push_back(a[idx]);
    if (subsEqualK(a, idx + 1, n, ans, k, sum + a[idx]))
        return true;

    ans.pop_back();
    if (subsEqualK(a, idx + 1, n, ans, k, sum))
        return true;

    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ans;
    subsEqualK(a, 0, n, ans, k, 0);
}