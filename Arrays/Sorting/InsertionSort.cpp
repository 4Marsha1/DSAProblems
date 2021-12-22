#include <bits/stdc++.h>

using namespace std;

// Function Prototype
void insertionSort(int n, int arr[]);

int main()
{
    // Taking input size & array
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Sort function call
    insertionSort(n, arr);

    // Print sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to sort using insertion sort
void insertionSort(int n, int arr[])
{
    // loop from 1st to (n-1)th index
    // right hand / unsorted array
    for (int i = 1; i < n; i++)
    {
        // take the ith element as current element
        int current = arr[i];
        // take the index previous to current index
        int j = i - 1;
        // left hand / sorted array
        // loop from jth to 0th index
        // check if jth element is larger than current element, if yes move all to the right by one
        while (arr[j] > current and j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // place the current element in its position
        arr[j + 1] = current;
        // j+1 because, j is one step behind (as j-- in while loop)
    }
}