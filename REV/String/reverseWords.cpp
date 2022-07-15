string reverseWords(string s)
{
    stack<string> st;
    string word = "";
    for (int i = 0; i <= s.length(); i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            if (word != "")
                st.push(word);
            word = "";
        }
        else
            word += s[i];
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top() + ' ';
        st.pop();
    }
    return ans.substr(0, ans.size() - 1);
}