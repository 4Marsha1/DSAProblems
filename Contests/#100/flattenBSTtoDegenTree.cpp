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

// Increasing Order Search Tree

class Solution
{
public:
    void findIn(TreeNode *root, vector<int> &in)
    {
        if (root == NULL)
            return;
        findIn(root->left, in);
        in.push_back(root->val);
        findIn(root->right, in);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> in;
        findIn(root, in);
        TreeNode *node = new TreeNode(in[0]);
        TreeNode *nodePtr = node;
        for (int i = 1; i < in.size(); i++)
        {
            TreeNode *newNode = new TreeNode(in[i]);
            node->right = newNode;
            node = node->right;
        }
        return nodePtr;
    }
};