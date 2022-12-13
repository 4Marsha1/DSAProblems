class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                for (int k = j + 1; k < arr.size(); k++)
                {
                    if (
                        abs(arr[i] - arr[j]) <= a and
                        abs(arr[j] - arr[k]) <= b and
                        abs(arr[i] - arr[k]) <= c)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};