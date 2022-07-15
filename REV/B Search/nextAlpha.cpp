char nextGreatestLetter(vector<char> &letters, char target)
{
    int low = 0, high = letters.size() - 1;
    char ans = letters[0];
    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (letters[mid] <= target)
            low = mid + 1;
        else
        {
            ans = letters[mid];
            high = mid - 1;
        }
    }
    return ans;
}