#include <bits/stdc++.h>
using namespace std;

// O(n2) & Omega(n) Time Complexity
void bubSort(int a[], int n)
{
    // loop through the entire array
    for (int i = 0; i < n; i++)
    {
        // keep a count of swaps
        int cnt = 0;
        // loop till the (n-i-1)th element
        for (int j = 0; j < n - i - 1; j++)
        {
            // if consequtive elements are out of order
            if (a[j] > a[j + 1])
            {
                // swap the elements and increment no of swaps
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                cnt++;
            }
        }
        // if in any iteration, no swaps made, therefore array sorted
        // so break off
        if (cnt == 0)
            break;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bubSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}