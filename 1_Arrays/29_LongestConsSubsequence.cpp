#include <bits/stdc++.h>
using namespace std;

// --------------------> O(n) Space and Time complexity
int findLongestConseqSubseq(int arr[], int n)
{
    // Applying Count Sort
    int maxElem = arr[0];
    for (int i = 1; i < n; i++)
        maxElem = max(maxElem, arr[i]);
    maxElem++;

    int count[maxElem] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i < maxElem; i++)
        count[i] += count[i - 1];

    int sortedArray[n];
    for (int i = n - 1; i >= 0; i--)
        sortedArray[--count[arr[i]]] = arr[i];

    // Finding the longest consequtive subsequence (from the sorted array)
    int len = 1, maxLen = 1;
    for (int i = 1; i < n; i++)
    {
        if (sortedArray[i] - sortedArray[i - 1] == 1)
        {
            len++;
            maxLen = max(maxLen, len);
        }
        else if (sortedArray[i] - sortedArray[i - 1] == 0)
            continue;
        else
            len = 1;
    }
    return maxLen;
}