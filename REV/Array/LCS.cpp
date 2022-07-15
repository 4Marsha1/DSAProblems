int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
        map[nums[i]] = i;
    int len = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(nums[i] + 1) != map.end())
            continue;
        else
        {
            int cnt = 0, curr = nums[i];
            while (map.find(curr) != map.end())
            {
                cnt++;
                curr--;
            }
            len = max(len, cnt);
        }
    }
    return len;
}