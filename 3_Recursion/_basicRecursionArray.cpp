#include <bits/stdc++.h>
using namespace std;

// reverse an array
void reverse(int a[], int i, int n)
{
    if (i >= n / 2)
        return;
    int t = a[i];
    a[i] = a[n - 1 - i];
    a[n - 1 - i] = t;
    reverse(a, i + 1, n);
}

// check for palindrome
bool isPalindrome(string s, int i)
{
    if (i >= s.length() / 2)
        return true;
    if (s[i] != s[s.length() - 1 - i])
        return false;
    return isPalindrome(s, i + 1);
}

int main()
{
    int a[] = {1, 4, 7, 9, 2};
    reverse(a, 0, 5);

    string s = "ababa";
    cout << isPalindrome(s, 0);
}