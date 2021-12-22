#include <bits/stdc++.h>

using namespace std;

//  Function Prototypes
void swap(int *x, int *y);
int Partition(int arr[], int l, int r);
void QuickSort(int arr[], int l, int r);

int main()
{
    // Input size and array
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Function Call to sort the array
    QuickSort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to swap 2 integers
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// Function to
// 1. place all elements smaller than pivot to left, larger than pivot to right
// 2. return the pivot element
// N.B: takes the last element as pivot here. We can take any element as pivot, just keep consistency throughout
int Partition(int arr[], int l, int r)
{
    // last element of the subarray [l,r] is taken as pivot
    int pivot = arr[r];
    // pointer initialised to l-1
    int i = l - 1;
    // traverse through the subarray except last element (as last is pivot itself)
    for (int j = l; j < r; j++)
    {
        // if current element is smaller than pivot
        // move the i pointer one step forward and swap current element with ith element
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // if i points to the last element of the smaller subarray
    // then (i+1) is the pivot position
    // so place the pivot at its position and return (i+1)
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}

// Function to sort using QuickSort
void QuickSort(int arr[], int l, int r)
{
    // if elements exist
    if (l < r)
    {
        // find the pivot
        int pivot = Partition(arr, l, r);
        // Sort the left side of pivot
        QuickSort(arr, l, pivot - 1);
        // Sort the right side of pivot
        QuickSort(arr, pivot + 1, r);
    }
}