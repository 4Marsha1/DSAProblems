// MOST UNIQUE WAY
int *findTwoElement(int *A, int n)
{
    int flag[n] = {0};
    int ans[2];
    int *x = ans;
    for (int i = 0; i < n; i++)
    {
        int ind = abs(A[i]) - 1;
        if (A[ind] < 0 && flag[ind] == 1)
            ans[0] = (ind + 1);
        A[ind] = -A[ind];
        flag[ind] = 1;
    }
    for (int i = 0; i < n; i++)
        if (flag[i] == 0)
            ans[1] = (i + 1);
    return x;
}