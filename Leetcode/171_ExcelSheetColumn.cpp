
// https://leetcode.com/problems/excel-sheet-column-number/

#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string columnTitle)
{
    int num = 0, n = columnTitle.length();
    for (int i = n - 1; i >= 0; i--)
    {
        num += (int)(columnTitle[i] - 'A' + 1) * pow(26, n - i - 1);
    }
    return num;
}