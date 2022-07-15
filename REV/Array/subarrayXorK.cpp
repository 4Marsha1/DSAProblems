int Solution::solve(vector<int> &A, int B)
{
    int x = 0, cnt = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < A.size(); i++)
    {
        x = x ^ A[i];
        if (x == B)
            cnt++;
        if (map.find(x ^ B) != map.end())
            cnt += map[x ^ B];
        map[x]++;
    }
    return cnt;
}