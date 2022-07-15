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

// @TODO: SOLUTION 1
bool lca(TreeNode *root, TreeNode *p, vector<TreeNode *> &path)
{
    if (root == NULL)
        return false;
    path.push_back(root);
    if (root == p)
        return true;
    if (lca(root->left, p, path) || lca(root->right, p, path))
        return true;
    path.pop_back();
    return false;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> path1;
    vector<TreeNode *> path2;
    lca(root, p, path1);
    lca(root, q, path2);
    TreeNode *node;
    for (int i = 0; i < path1.size() && i < path2.size(); ++i)
    {
        if (path1[i] == path2[i])
        {
            node = path1[i];
        }
        else
        {
            break;
        }
    }
    return node;
}

// @TODO: SOLUTION 2
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}