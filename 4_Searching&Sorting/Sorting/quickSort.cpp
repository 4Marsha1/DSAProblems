#include <bits/stdc++.h>
using namespace std;

// O(n2) & Omega(nlogn) Time Complexity

// Finding pivot element &
// placing all elements < pivot to the left of pivot
// placing all elements > pivot to the right of pivot
int partition(int a[], int l, int r)
{
    // take pivot as last element
    int pivot = a[r];
    // take index before the start
    int i = l - 1;
    // loop through all the indices [l,r)
    for (int j = l; j < r; j++)
    {
        // if current element is less the pivot
        if (a[j] < pivot)
        {
            // increment i and swap
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    // [l,i] -> (elements less than pivot)
    // [i+2,r] -> (elements greater than pivot)
    // (i+1)th --> pivot
    // swap (i+1)th and rth element
    // placing pivot in its position
    int t = a[i + 1];
    a[i + 1] = a[r];
    a[r] = t;
    // return pivot index
    return (i + 1);
}

// Quick Sort Algorithm
void quickSort(int a[], int l, int r)
{
    // if elements exist
    if (l < r)
    {
        // find the pivot element
        int pivot = partition(a, l, r);
        // sort the left part of pivot
        quickSort(a, l, pivot - 1);
        // sort the right part of pivot
        quickSort(a, pivot + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}