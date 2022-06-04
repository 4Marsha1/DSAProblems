#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, long long temp[], int left, int mid, int right)
{
    long long cnt = 0;
    int i = left, j = mid, k = left;
    while (i <= mid - 1 && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            cnt += (mid - i);
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return cnt;
}

long long mergeSort(long long *arr, long long temp[], int left, int right)
{
    long long cnt = 0;
    if (left < right)
    {
        int mid = (left + (right - left) / 2);
        cnt += mergeSort(arr, temp, left, mid);
        cnt += mergeSort(arr, temp, mid + 1, right);
        cnt += merge(arr, temp, left, mid + 1, right);
    }
    return cnt;
}

long long getInversions(long long *arr, long long temp[], int n)
{
    // Write your code here.
    return mergeSort(arr, temp, 0, n - 1);
}

int main()
{
    int n;
    cin >> n;
    long long a[n], temp[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << getInversions(a, temp, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}