#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// Modified Dutch Algo
void seperateInt(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] < 0)
        {
            swap(&arr[low], &arr[mid]);
            mid++;
            low++;
        }
        else
        {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    seperateInt(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}