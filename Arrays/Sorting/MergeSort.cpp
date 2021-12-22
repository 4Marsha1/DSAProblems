#include <bits/stdc++.h>

using namespace std;

// Function Prototypes
void Merge(int arr[], int l, int mid, int r);
void MergeSort(int arr[], int l, int r);

int main()
{
    // taking inputs
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Calling sort function
    MergeSort(arr, 0, n - 1);

    // Printing sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Funtion to merge the left half and right half
void Merge(int arr[], int l, int mid, int r)
{
    // initialise size of left and right halves
    int n1 = mid - l + 1, n2 = r - mid;
    // two arrays to hold left and right halves
    int left[n1], right[n2];
    // copy the left half of arr to the array left
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    // copy the right half of arr to the array right
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];
    // initialise 3 pointer for starting indices: k for arr, i for left and j for right
    int k = l, i = 0, j = 0;
    // repeat until i or j exceeds array sizes
    while (i < n1 && j < n2)
    {
        // if ith element in left is smaller than jth element in right
        // push ith element in arr and increment i and k
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        // if jth element in right is smaller than ith element in left
        // push jth element in arr and increment j and k
        else
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    // if j exceeded n2 but i havenot
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    // if i exceeded n1 but j havenot
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to sort elements using MergeSort
void MergeSort(int arr[], int l, int r)
{
    // if elements exist
    if (l < r)
    {
        // find the mid of the given array
        int mid = (l + r) / 2;
        // sort the left half
        MergeSort(arr, l, mid);
        // sort the right half
        MergeSort(arr, mid + 1, r);
        // Merge the sorted halves
        Merge(arr, l, mid, r);
    }
}