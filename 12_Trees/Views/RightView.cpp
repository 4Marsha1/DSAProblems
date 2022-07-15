#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<TreeNode *, int>> q;
    map<int, int> levelNode;
    q.push({root, 0});
    while (!q.empty())
    {
        TreeNode *node = q.front().first;
        int y = q.front().second;
        q.pop();
        levelNode[y] = node->val;
        if (node->left)
            q.push({node->left, y + 1});
        if (node->right)
            q.push({node->right, y + 1});
    }
    for (auto it : levelNode)
        ans.push_back(it.second);
    return ans;
}