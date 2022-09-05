class Solution
{
public:
    bool checkDistances(string s, vector<int> &distance)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a'] = (i - freq[s[i] - 'a']);
            // cout<<freq[s[i]-'a']<<endl;
        }
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
                continue;
            if (freq[i] - 1 != distance[i])
                return false;
        }
        return true;
    }
};