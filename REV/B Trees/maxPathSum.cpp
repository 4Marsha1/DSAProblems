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
    int func(TreeNode *root, int &maxPS)
    {
        if (root == NULL)
            return 0;
        int ls = max(0, func(root->left, maxPS));
        int rs = max(0, func(root->right, maxPS));
        maxPS = max(maxPS, root->val + ls + rs);
        return root->val + max(ls, rs);
    }
    int maxPathSum(TreeNode *root)
    {
        int maxPS = INT_MIN;
        int x = func(root, maxPS);
        return maxPS;
    }
};