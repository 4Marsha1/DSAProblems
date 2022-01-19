#include <bits/stdc++.h>
using namespace std;

// O(n2) & Omega(n) Time Complexity
void insSort(int a[], int n)
{
    // Loop through Right Hand (unsorted array)
    for (int i = 1; i < n; i++)
    {
        // Take First element of unsorted array
        int current = a[i];
        int j = i - 1;
        // Loop through the left hand (sorted array) -> R-L
        while (j >= 0 && current < a[j])
        {
            // keep shifting elements towards right
            a[j + 1] = a[j];
            j--;
        }
        // place the current element in its correct position in sorted array
        a[j + 1] = current;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}