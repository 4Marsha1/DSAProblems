// find the longest word in a sentence

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // input
    int n;
    cin >> n;
    cin.ignore();
    char arr[n + 1];
    // input char array, that contains spaces
    cin.getline(arr, n);
    cin.ignore();

    // modified Kadane's Algo
    int maxLength = 0, currLength = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        // if we find a space, make current length 0
        if (arr[i] == ' ')
            currLength = 0;
        // otherwise, increment current Length and update maxLength as required
        else
        {
            currLength++;
            maxLength = max(maxLength, currLength);
        }
    }
    cout << maxLength;
}