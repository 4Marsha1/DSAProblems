void func(string s, vector<string> &ans, string res)
{
    if (s.length() == 0)
    {
        // for unique entries in duplicate string
        auto it = find(ans.begin(), ans.end(), res);
        if (it != ans.end())
            return;
        ans.push_back(res);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        func(s.substr(0, i) + s.substr(i + 1), ans, res + ch);
    }
}
vector<string> find_permutation(string s)
{
    vector<string> ans;
    func(s, ans, "");
    return ans;
}