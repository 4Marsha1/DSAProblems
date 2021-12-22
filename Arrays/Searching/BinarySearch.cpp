#include <bits/stdc++.h>

using namespace std;

// Function Prototype
bool binarySearch(int n, int arr[], int key);

int main()
{
    // Taking size and key inputs
    int n, key;
    cin >> n >> key;

    // Taking array inputs
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Checking if key found in the array
    if (binarySearch(n, arr, key))
    {
        cout << "Found\n";
        return 0;
    }
    else
    {
        cout << "Not Found\n";
        return 1;
    }
}

// function declaration
bool binarySearch(int n, int arr[], int key)
{
    // left and right
    int l = 0, r = n - 1;

    // checking until left crosses right
    while (l <= r)
    {
        // finding mid for current left and right
        int mid = (l + r) / 2;
        // check if mid element is key
        if (arr[mid] == key)
            return true;
        // if mid element is smaller than key, than key must be in right half
        else if (arr[mid] < key)
            l = mid + 1;
        // if mid element is larger than key, than key must be in left half
        else
            r = mid - 1;
    }
    return false;
}