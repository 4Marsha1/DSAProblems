#include <iostream>
#include <vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector<string> getMazePaths(int sr, int sc, int dr, int dc)
{

    if (sr == dr || sc == dc)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }

    vector<string> hpaths = getMazePaths(sr, sc + 1, dr, dc);
    vector<string> vpaths = getMazePaths(sr + 1, sc, dr, dc);
    vector<string> ans;

    for (string str : hpaths)
        ans.push_back("h" + str);
    for (string str : vpaths)
        ans.push_back("v" + str);
    return ans;
}

void display(vector<string> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans = getMazePaths(1, 1, n, m);
    display(ans);

    return 0;
}