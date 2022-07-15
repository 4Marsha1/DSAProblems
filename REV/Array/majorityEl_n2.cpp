int majorityElement(vector<int> &nums)
{
    int curr, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt == 0)
            curr = nums[i];
        if (curr == nums[i])
            cnt++;
        else
            cnt--;
    }
    return curr;
}