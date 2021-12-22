#include <bits/stdc++.h>
using namespace std;

// ---------------- brute force
const int N = 1e6 + 5;
int main()
{
    // input
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // initialing array to store indices
    int count[N];
    for (int i = 0; i < N; i++)
        count[i] = -1;

    int min_ind = INT_MAX; // store the min index
    for (int i = 0; i < n; i++)
    {
        if (count[arr[i]] != -1) // if index exists (means character is repeating)
        {
            min_ind = min(min_ind, count[arr[i]]); // store the minimum index
        }
        else // if index doesnt exist. update it
        {
            count[arr[i]] = i;
        }
    }
    if (min_ind == INT_MAX) // if no repeating character
        cout << "-1";
    else // otherwise (1-based indexing)
        cout << min_ind + 1;
}

// ----------------- using Hashmap (optimised)
int main()
{
    // input
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // hashmap (value, index)
    unordered_map<int, int> map;
    int min_ind = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        // if element already exists with some index
        if (map.find(arr[i]) != map.end())
        {
            // find the min of this index and the current min
            min_ind = min(min_ind, map[arr[i]]);
        }
        // if element doesnt exist in the map
        else
        {
            // insert the value - index pair
            map[arr[i]] = i;
        }
    }
    cout << min_ind + 1;
}