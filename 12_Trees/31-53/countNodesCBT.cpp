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

// BRUTE FORCE O(N)
class Solution
{
public:
    void count(TreeNode *root, int &cnt)
    {
        if (root == NULL)
            return;
        cnt++;
        count(root->left, cnt);
        count(root->right, cnt);
    }
    int countNodes(TreeNode *root)
    {
        int cnt = 0;
        count(root, cnt);
        return cnt;
    }
};

// OPTIMISED O((logN)^2)
class Solution
{
public:
    int findHeightLeft(TreeNode *root)
    {
        int h = 0;
        while (root)
        {
            h++;
            root = root->left;
        }
        return h;
    }
    int findHeightRight(TreeNode *root)
    {
        int h = 0;
        while (root)
        {
            h++;
            root = root->right;
        }
        return h;
    }
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        if (lh == rh)
            return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};