
// https://leetcode.com/problems/compare-version-numbers/

#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2)
{
    int ind_1 = 0, ind_2 = 0, n1 = version1.size(), n2 = version2.size();
    while (ind_1 < n1 || ind_2 < n2)
    {
        int a = 0, b = 0;
        while (ind_1 < n1 && version1[ind_1] == '0')
            ind_1++;

        while (ind_2 < n2 && version2[ind_2] == '0')
            ind_2++;
        while (ind_1 < n1 && version1[ind_1] != '.')
        {
            a = a * 10 + version1[ind_1] - '0';
            ind_1++;
        }
        while (ind_2 < n2 && version2[ind_2] != '.')
        {
            b = b * 10 + version2[ind_2] - '0';
            ind_2++;
        }
        if (a != b)
            return a > b ? 1 : -1;
        ind_1++;
        ind_2++;
    }
    return 0;
}