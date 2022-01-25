#include <bits/stdc++.h>
using namespace std;

void ssOfSumK(vector<int> a, int idx, vector<int> &ans, int sum, int target)
{
    if (idx == a.size())
    {
        if (sum == target)
        {
            for (auto i : ans)
                cout << i << " ";
            cout << endl;
        }
        return;
    }
    ans.push_back(a[idx]);
    ssOfSumK(a, idx + 1, ans, sum + a[idx], target);
    ans.pop_back();
    ssOfSumK(a, idx + 1, ans, sum, target);
}

int main()
{
    vector<int> a = {10, 20, 30, 40, 50};
    vector<int> ans;
    //  input, index, ans, sum, target
    ssOfSumK(a, 0, ans, 0, 70);
}