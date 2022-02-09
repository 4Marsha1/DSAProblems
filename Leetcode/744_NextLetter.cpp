#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    int low = 0, high = letters.size() - 1, mid = 0;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (letters[mid] <= target)
            low = mid + 1;
        else
            high = mid;
    }
    return letters[low] > target ? letters[low] : letters[0];
}