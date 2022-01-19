#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int j = 0;
    while (j < m)
    {
        if (arr2[j] < arr1[n - 1])
        {
            int t = arr2[j];
            arr2[j] = arr1[n - 1];
            arr1[n - 1] = t;
            sort(arr1, arr1 + n);
            sort(arr2, arr2 + m);
        }
        else
            j++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    merge(a, b, n, m);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    for (int i = 0; i < m; i++)
        cout << b[i] << " ";
}