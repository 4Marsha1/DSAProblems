// BRUTE FORCE
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
        return true;
    return false;
}

// FREQUENCY
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    unordered_map<char, int> map;
    for (int i = 0; i < s.length(); i++)
    {
        map[s[i]]++;
        map[t[i]]--;
    }
    for (auto it : map)
    {
        if (it.second)
            return false;
    }
    return true;
}