// Isyana is given the number of visitors at her local theme park on N consecutive days.
// The number of visitors on the i-th day is Vi. A day is record breaking if it
// satisfies both of the following conditions :
// ● The number of visitors on the day is strictly larger than the number of
//                 visitors on each of the previous days.
// ● Either it is the last day, or the number of visitors on the day is strictly larger
//             than the number of visitors on the following day.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int maxElem = arr[0], cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxElem)
        {
            maxElem = arr[i];
            if (i == n - 1)
                cnt++;
            else if (arr[i] > arr[i + 1])
                cnt++;
        }
    }
    cout << cnt;
}