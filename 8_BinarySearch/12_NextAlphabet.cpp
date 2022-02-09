#include <bits/stdc++.h>
using namespace std;

char nextAlphabet(char a[], int n, char k)
{
    int start = 0, end = n - 1;
    char ans = '#';
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (a[mid] <= k)
            start = mid + 1;
        else if (a[mid] > k)
        {
            ans = a[mid];
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    char k;
    cin >> n >> k;
    char a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << nextAlphabet(a, n, k);
}