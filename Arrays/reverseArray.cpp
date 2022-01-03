#include <bits/stdc++.h>
using namespace std;

// Iterative Method
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n / 2; i++)
    {
        int t = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = t;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Recursive Method
void reverse(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int t = arr[start];
    arr[start] = arr[end];
    arr[end] = t;
    reverse(arr, start + 1, end - 1);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    reverse(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}