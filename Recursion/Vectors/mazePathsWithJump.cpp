#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc)
{

    if (sr == dr || sc == dc)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }

    vector<string> paths;
    // horizontal paths
    for (int i = 1; i <= dc - sc; i++)
    {
        vector<string> hpaths = get_maze_paths(sr, sc + i, dr, dc);
        for (string str : hpaths)
        {
            paths.push_back("h" + to_string(i) + str);
        }
    }
    // vertical paths
    for (int i = 1; i <= dr - sr; i++)
    {
        vector<string> vpaths = get_maze_paths(sr + i, sc, dr, dc);
        for (string str : vpaths)
        {
            paths.push_back("v" + to_string(i) + str);
        }
    }
    // diagonal paths
    for (int i = 1; i <= dc - sc && i <= dr - sr; i++)
    {
        vector<string> dpaths = get_maze_paths(sr + i, sc + i, dr, dc);
        for (string str : dpaths)
        {
            paths.push_back("d" + to_string(i) + str);
        }
    }
    return paths;
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
    vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
    display(ans);

    return 0;
}