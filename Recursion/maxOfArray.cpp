#include <iostream>
using namespace std;

int max(int arr[], int idx, int n)
{
    if (idx == n)
        return -1;
    int max_smaller = max(arr, idx + 1, n);
    if (max_smaller > arr[idx])
        return max_smaller;
    else
        return arr[idx];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = max(arr, 0, n);
    cout << p << endl;
}
