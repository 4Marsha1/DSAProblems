#include <bits/stdc++.h>
using namespace std;

// brute force ----------> O(n2)
int rainWaterTrapping(int a[], int n)
{
    int water = 0;
    for (int i = 1; i < n - 1; i++)
    {
        // left array
        int lmax = 0;
        for (int j = 0; j < i; j++)
            lmax = max(lmax, a[j]);
        // right array
        int rmax = 0;
        for (int j = i + 1; j < n; j++)
            rmax = max(rmax, a[j]);
        int minmax = min(rmax, lmax);
        if (minmax - a[i] > 0)
            water += (minmax - a[i]);
    }
    return water;
}

// optimised -------------> O(n)
int rainWaterTrapping(int a[], int n)
{
    int maxL[n], maxR[n];
    // Max So Far in left
    maxL[0] = a[0];
    for (int i = 1; i < n; i++)
        maxL[i] = max(maxL[i - 1], a[i]);
    // Max So Far in Right
    maxR[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        maxR[i] = max(maxR[i + 1], a[i]);
    // Store water holding min(r,l) - a[i]
    int water[n];
    for (int i = 0; i < n; i++)
        water[i] = min(maxL[i], maxR[i]) - a[i];
    // Sigma water
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += water[i];
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << rainWaterTrapping(a, n);
}