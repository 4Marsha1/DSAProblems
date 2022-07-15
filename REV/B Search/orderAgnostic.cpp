#include <bits/stdc++.h>
using namespace std;

int BsearchA(int a[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int BsearchD(int a[], int n, int key)
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
    if (n == 0)
        return false;
    if (n == 1)
    {
        if (a[0] == key)
            return 0;
        else
            return -1;
    }
    if (a[0] < a[1])
        cout << BsearchA(a, n, key);
    else
    {
        cout << BsearchD(a, n, key);
    }
}