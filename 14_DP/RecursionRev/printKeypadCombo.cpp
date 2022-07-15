oid func(int a[], int idx, int N, vector<string> &ans, string res, string codes[])
{
    if (idx == N)
    {
        ans.push_back(res);
        return;
    }
    string ch = codes[a[idx]];
    for (int i = 0; i != ch.length(); i++)
    {
        func(a, idx + 1, N, ans, res + ch[i], codes);
    }
}
vector<string> possibleWords(int a[], int N)
{
    string codes[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    func(a, 0, N, ans, "", codes);
    return ans;
}