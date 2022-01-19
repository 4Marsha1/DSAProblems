#include <bits/stdc++.h>
using namespace std;

// O(nlogn) & Omega(nlogn) Time Complexity

// Merging Sorted halves
void _merge(int a[], int l, int mid, int r)
{
    // declare 2 arrays LEFT & RIGHT
    int n1 = mid - l + 1, n2 = r - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = a[mid + i + 1];

    // Place elements in a from LEFT & RIGHT
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            a[k] = left[i];
            i++;
            k++;
        }
        else
        {
            a[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

// Merge Sort Algorithm
void mergeSort(int a[], int l, int r)
{
    // if element exists
    if (l < r)
    {
        // take midpoint
        int mid = (l + r) / 2;
        // sort left half
        mergeSort(a, l, mid);
        // sort right half
        mergeSort(a, mid + 1, r);
        // merge sorted halves
        _merge(a, l, mid, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}