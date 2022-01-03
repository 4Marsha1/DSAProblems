#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    int j = n - 1;
    int t = arr[j];
    j--;
    while (j >= 0)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = t;
}