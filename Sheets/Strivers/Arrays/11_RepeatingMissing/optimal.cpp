#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    int xor1;

    /* Will have only single set bit of xor1 */
    int set_bit_no;

    int i;
    int x = 0; // missing
    int y = 0; // repeated
    int n = A.size();

    xor1 = A[0];

    /* Get the xor of all Aay elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ A[i];

    /* XOR the previous result with numbers from 1 to n */
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    /* Now divide elements into two sets by comparing a rightmost set bit
       of xor1 with the bit at the same position in each element.
       Also, get XORs of two sets. The two XORs are the output elements.
       The following two for loops serve the purpose */

    for (i = 0; i < n; i++)
    {
        if (A[i] & set_bit_no)
            /* A[i] belongs to first set */
            x = x ^ A[i];

        else
            /* A[i] belongs to second set */
            y = y ^ A[i];
    }

    for (i = 1; i <= n; i++)
    {
        if (i & set_bit_no)
            /* i belongs to first set */
            x = x ^ i;

        else
            /* i belongs to second set */
            y = y ^ i;
    }

    // NB! numbers can be swapped, maybe do a check ?
    int x_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == x)
            x_count++;
    }

    if (x_count == 0)
        return {y, x};

    return {x, y};
}
