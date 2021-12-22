#include <bits/stdc++.h>
using namespace std;

int main()
{
    // input
    int n;
    cin >> n;
    char arr[n + 1];
    cin >> arr;

    // check if first and last charcter are same
    // check if second and second last character are same
    // and so on ....
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            cout << "Not Palindrome";
            return 0;
        }
    }
    cout << "Palindrome";
}