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

// Brute force ------> O(N2): O(N) for traversal, O(N) for finding height
int height(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
bool isBalanced(TreeNode *root)
{
    if (root == NULL)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1)
        return false;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    if (!left || !right)
        return false;

    return true;
}

// optimised Approach ----> O(N) ---> modified maxDepth
int check(TreeNode *node)
{
    if (node == NULL)
        return 0;
    int lh = check(node->left);
    if (lh == -1)
        return -1;
    int rh = check(node->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}
bool isBalanced(TreeNode *root)
{
    return check(root) == -1 ? false : true;
}