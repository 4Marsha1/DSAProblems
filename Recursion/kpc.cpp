#include <iostream>
#include <string>
#include <vector>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getKPC(string s)
{
    if (s.length() == 0)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }

    string ros = s.substr(1);
    vector<string> rest = getKPC(ros);
    vector<string> ans;

    string ch = codes[s[0] - '0'];
    for (int i = 0; i < ch.length(); i++)
    {
        char chcode = ch[i];
        for (string rstr : rest)
        {
            ans.push_back(chcode + rstr);
        }
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = getKPC(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans)
    {
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}