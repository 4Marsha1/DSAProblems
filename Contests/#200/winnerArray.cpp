class Solution
{
public:
    int getWinner(vector<int> &A, int k)
    {
        int n = A.size(), i = 0, j = 1, zero = 0, one = 0;

        while (i < n && j < n)
        {
            if (A[i] < A[j])
            {
                i = max(i, j) + 1;
                zero = 0;
                one++;
            }
            else
            {
                j = max(i, j) + 1;
                one = 0;
                zero++;
            }
            if (zero >= k)
                return A[i];
            if (one >= k)
                return A[j];
        }
        if (i < n && zero >= 0)
            return A[i];
        if (j < n && one >= 0)
            return A[j];
        return 0;
    }
};