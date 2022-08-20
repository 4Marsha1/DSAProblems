/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int func(TreeNode *root, int &maxD)
    {
        if (root == NULL)
            return 0;
        int lh = func(root->left, maxD);
        int rh = func(root->right, maxD);
        maxD = max(maxD, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxD = INT_MIN;
        int x = func(root, maxD);
        return maxD;
    }
};