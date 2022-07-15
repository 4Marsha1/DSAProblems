#include <bits/stdc++.h>
using namespace std;

int lastOcc(int a[], int n, int key)
{
    int low = 0, high = n - 1, f = -1;
    while (low < high)
    {
        int mid = (low + (high - low) / 2);
        if (a[mid] == key)
        {
            f = mid;
            low = mid + 1;
        }
        else if (a[mid] < key)
            low++;
        else
            high--;
    }
    return f;
}

int main()
{
    int n, key;
    cin >> n >> key;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << lastOcc(a, n, key);
}