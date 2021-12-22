#include <bits/stdc++.h>
using namespace std;

// -----------------------  brute Force
int main()
{
    // input
    int n, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // check for all the pairs
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << arr[i] << " " << arr[j];
                return 0;
            }
        }
    }
    cout << "Not Found";
}

// ------------------  using hashmap (better)
int main()
{
    // input
    int n, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int one, two;

    // use a hashmap to store value and index pairs
    unordered_map<int, int> map; // value, index
    for (int i = 0; i < n; i++)
    {
        // for each iteration, check if target-arr[i] exists in the map
        if (map.find(target - arr[i]) != map.end())
        {
            // if that does, means we found the 2 values
            one = map[target - arr[i]];
            two = i;
            break;
        }
        // else push the new value, index pair in the hashmap
        else
            map[arr[i]] = i;
    }
    cout << arr[one] << " " << arr[two];
}

// ---------------------- 2-pointer Approach (optimised)
// array must be sorted
int main()
{
    // input
    int n, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // 2 pointers, one at begin, other at end
    int low = 0, high = n - 1;
    // while elements exist
    while (low < high)
    {
        // if (low)th and (high)th elements add up to target
        if (arr[low] + arr[high] == target)
        {
            // ans found
            cout << arr[low] << " " << arr[high];
            return 0;
        }
        // if (low)th + (high)th is more than target, means move high a step back
        else if (arr[low] + arr[high] > target)
            high--;
        // if (low)th + (high)th is less than target, means move low a step forward
        else
            low++;
    }
}