#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Taking Inputs from the user
    int n, key;
    cin >> n >> key;

    // Taking the Input array
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Iterating linearly and checking to find a match
    for (int i = 0; i < n; i++)
    {
        // if Key is found in the array
        if (arr[i] == key)
        {
            cout << "Found\n";
            return 0;
        }
    }

    // If Key not found
    cout << "Not Found\n";
    return 1;
}