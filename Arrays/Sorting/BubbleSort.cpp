#include <bits/stdc++.h>

using namespace std;

// Function Prototypes
void swap(int *x, int *y);
void bubbleSort(int n, int arr[]);

int main()
{
    // Input size and array
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Sort function call
    bubbleSort(n, arr);

    // Output sorted array
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

// Function to sort using bubble sort
void bubbleSort(int n, int arr[])
{
    // keep count of swaps made
    int swaps = 0;
    // loop from 0 to n-1
    for (int i = 0; i < n; i++)
    {
        // loop from 0 to second last (in first iteration)
        // loop from 0 to third last (in second iteration as last spot now contains correct element)
        for (int j = 0; j < n - 1 - i; j++)
        {
            // check if corresponing elements are in correct order
            if (arr[j] > arr[j + 1])
            {
                // swap to make a pair in correct order
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
        // if in the 1st iteration, no swaps are made
        // means array is already sorted, so break off
        if (i == 0 && swaps == 0)
            break;
    }
}