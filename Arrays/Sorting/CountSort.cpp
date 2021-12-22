#include <bits/stdc++.h>

using namespace std;

//  Function Prototypes
void CountSort(int n, int arr[]);

int main()
{
    // Input size and array
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Function Call to sort the array
    CountSort(n, arr);

    // Print the sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to sort using count sort
void CountSort(int n, int arr[])
{
    // find the maxelement of the array for Count Array Size
    int maxElement = arr[0];
    for (int i = 1; i < n; i++)
        maxElement = max(arr[i], maxElement);
    maxElement++;

    // Initialise a count Array to maintain frequency
    int countArray[maxElement] = {0};
    for (int i = 0; i < n; i++)
    {
        countArray[arr[i]]++;
    }

    // Update the count Array to hold position of each element (1 indexed)
    for (int i = 1; i < maxElement; i++)
    {
        countArray[i] = countArray[i] + countArray[i - 1];
    }

    // traverse the array from right, and place the element in a new array as per position-1
    int sortedArray[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int pos = countArray[arr[i]] - 1;
        countArray[arr[i]]--;
        sortedArray[pos] = arr[i];
    }

    // transfer the new array to the original array
    for (int i = 0; i < n; i++)
        arr[i] = sortedArray[i];
}