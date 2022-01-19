#include <bits/stdc++.h>
using namespace std;

// O(n+k) Time Complexity
// O(n+k) Space Complexity
void countSort(int a[], int n)
{
    // find Max Element for Count Array size
    int maxElem = INT_MIN;
    for (int i = 0; i < n; i++)
        maxElem = max(maxElem, a[i]);
    maxElem++;

    // Declare Count array and store count of each elem
    int cnt[maxElem] = {0};
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }
    // Update count array to store relative positions
    for (int i = 1; i < maxElem; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    // Place elements according to position in new array
    int sorted[n];
    for (int i = n - 1; i >= 0; i--)
    {
        sorted[--cnt[a[i]]] = a[i];
    }
    // put elements back in original array
    for (int i = 0; i < n; i++)
        a[i] = sorted[i];
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    countSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}