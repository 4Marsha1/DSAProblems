#include <bits/stdc++.h>
using namespace std;

// find sum of elements between k1th and k2th smallest elements

// function for kth smallest element
int kthSmallest(int a[], int n, int k)
{
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(a[i]);
        if (maxHeap.size() > k)
            maxHeap.pop();
    }
    return maxHeap.top();
}

int main()
{
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Find k1th & k2th Smallest elements
    int first = kthSmallest(a, n, k1);
    int second = kthSmallest(a, n, k2);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // if element lies between k1th & k2th smallest elements, then add
        // (k1,k2) --> exclusive
        if (a[i] > first && a[i] < second)
            sum += a[i];
    }
    cout << sum;
}