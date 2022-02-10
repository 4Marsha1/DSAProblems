#include <bits/stdc++.h>
using namespace std;

class MountainArray
{
public:
    int get(int index);
    int length();
};

// Concept :
// In Bitonic array, first part is strictly ascending and second part is strictly descending.
// If we can find the peak index, then the array can be divided into 2 parts.
// 1. [0, index]-- > asceding order
// 2. [index + 1, size - 1]-- > descending order
// Hence apply Binary Search(BS) on first part and,
// binary search for reverse sorted array (RBS) on the second part

int peakElementIndex(MountainArray arr);
int BS(MountainArray arr, int start, int end, int target);
int RBS(MountainArray arr, int start, int end, int target);

int findInMountainArray(int target, MountainArray &arr)
{
    // 1. Find Max Element Index
    int index = peakElementIndex(arr);
    // Search in LEFT array -> ascending order
    int left = BS(arr, 0, index, target);
    // Search in RIGHT array -> descending order
    int right = RBS(arr, index + 1, arr.length() - 1, target);
    if (left == -1 || right == -1)
        return max(left, right);
    else
        return min(left, right);
}

// to find peak element index
int peakElementIndex(MountainArray arr)
{
    int n = arr.length();
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (mid > 0 && mid < n - 1)
        {
            if (arr.get(mid) > arr.get(mid - 1) && arr.get(mid) > arr.get(mid + 1))
                return mid;
            else if (arr.get(mid - 1) > arr.get(mid))
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (mid == 0)
        {
            return arr.get(0) > arr.get(1) ? 0 : 1;
        }
        else if (mid == n - 1)
        {
            return arr.get(n - 1) > arr.get(n - 2) ? n - 1 : n - 2;
        }
    }
    return -1;
}

// Binary Search on ascending array (1st half)
int BS(MountainArray arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (arr.get(mid) == target)
            return mid;
        else if (arr.get(mid) > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

// Binary Search on descending order (2nd half)
int RBS(MountainArray arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (arr.get(mid) == target)
            return mid;
        else if (arr.get(mid) < target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}