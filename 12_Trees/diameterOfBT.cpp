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

// Brute force ---> O(N2) --> O(N) for traversal & O(N) for finding heights
int height(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);
    if (left > right)
        return max(left, lh + rh);
    else
        return max(right, lh + rh);
}

// Optimised----> O(N) ----> Modified maxDepth
int maxDepth(TreeNode *node, int &maxD)
{
    if (node == NULL)
        return 0;
    int lh = maxDepth(node->left, maxD);
    int rh = maxDepth(node->right, maxD);

    maxD = max(maxD, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int maxD = INT_MIN;
    // not required
    int height = maxDepth(root, maxD);
    return maxD;
}