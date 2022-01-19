#include <bits/stdc++.h>
using namespace std;

// O(n2) & Omega(n2) Time Complexity
void selSort(int a[], int n)
{
    // loop through the entire array
    for (int i = 0; i < n; i++)
    {
        // find the min element in the unsorted array
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        // swap the min element with the ith element
        int t = a[min];
        a[min] = a[i];
        a[i] = t;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    selSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}