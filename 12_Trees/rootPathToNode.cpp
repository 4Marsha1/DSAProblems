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

bool findPath(TreeNode *root, vector<int> &ans, int B)
{
    if (root == NULL)
        return false;
    ans.push_back(root->val);
    if (root->val == B)
        return true;
    if (findPath(root->left, ans, B) || findPath(root->right, ans, B))
        return true;
    ans.pop_back();
    return false;
}
vector<int> solve(TreeNode *A, int B)
{
    vector<int> ans;
    if (A == NULL)
        return ans;
    findPath(A, ans, B);
    return ans;
}