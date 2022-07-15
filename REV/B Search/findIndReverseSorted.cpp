#include <bits/stdc++.h>
using namespace std;

int Bsearch(int a[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int n, key;
    cin >> n >> key;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    cout << Bsearch(a, n, key);
}