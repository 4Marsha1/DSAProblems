#include <bits/stdc++.h>
using namespace std;

// Naive Approach -------------> O(n) Space and Time
void alternate(int arr[], int n)
{
    sort(arr, arr + n);
    int b[n], j = 0;
    for (int i = 0; i < n; i += 2)
    {
        b[i] = arr[j];
        j++;
    }
    for (int i = 1; i < n; i += 2)
    {
        b[i] = arr[j];
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = b[i];
    }
}

// Optimised Approach -----------> O(1) Space
// ------------------ Revise --------------------------------
void rightRotate(int arr[], int n, int outOfPlace, int curr)
{
    int temp = arr[curr];
    for (int i = curr; i > outOfPlace; i--)
        arr[i] = arr[i - 1];
    arr[outOfPlace] = temp;
}

void alternate(int arr[], int n)
{
    int outOfPlace = -1;
    for (int i = 0; i < n; i++)
    {
        if (outOfPlace >= 0)
        {
            if ((arr[i] >= 0 && arr[outOfPlace] < 0) || (arr[i] < 0 && arr[outOfPlace] >= 0))
            {
                rightRotate(arr, n, outOfPlace, i);
                if (i - outOfPlace >= 2)
                    outOfPlace += 2;
                else
                    outOfPlace = -1;
            }
        }
        if (outOfPlace == -1)
        {
            if ((arr[i] >= 0 && (!(i & 0x01))) || (arr[i] < 0 && (i & 0x01)))
                outOfPlace = i;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    alternate(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}