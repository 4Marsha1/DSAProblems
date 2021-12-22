#include <bits/stdc++.h>

using namespace std;

// Function Prototypes
void selectionSort(int n, int arr[]);
void swap(int *x, int *y);

int main()
{
    // Input size and array
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Sort the array
    selectionSort(n, arr);

    // Print the sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to Swap 2 integers
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// Function to sort using selection sort
void selectionSort(int n, int arr[])
{
    // Loop through 0 to n-1
    for (int i = 0; i < n; i++)
    {
        // take the ith index as min
        int min = i;
        // loop from ith to (n-1)th index
        for (int j = i; j < n; j++)
        {
            // if element at jth index is smaller than min: update min
            if (arr[j] < arr[min])
                min = j;
        }
        // swap  the min element with ith element
        swap(&arr[min], &arr[i]);
    }
}