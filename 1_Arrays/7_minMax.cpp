#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int min;
    int max;
};

// Return 2 values from one function
struct Pair getPair(int arr[], int n)
{
    struct Pair minMax;
    if (n == 1)
    {
        minMax.min = arr[0];
        minMax.max = arr[0];
        return minMax;
    }
    if (arr[0] < arr[1])
    {
        minMax.min = arr[0];
        minMax.max = arr[1];
    }
    else
    {
        minMax.min = arr[1];
        minMax.max = arr[0];
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] > minMax.max)
        {
            minMax.max = arr[i];
        }
        else if (arr[i] < minMax.min)
        {
            minMax.min = arr[i];
        }
    }
    return minMax;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    struct Pair p = getPair(arr, n);
    cout << p.min << " " << p.max;
}