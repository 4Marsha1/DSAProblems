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

int maxPath(TreeNode *node, int &maxPS)
{
    if (node == NULL)
        return 0;
    int lsum = max(0, maxPath(node->left, maxPS));
    int rsum = max(0, maxPath(node->right, maxPS));
    maxPS = max(maxPS, node->val + lsum + rsum);
    return node->val + max(lsum, rsum);
}
int maxPathSum(TreeNode *root)
{
    int maxPS = INT_MIN;
    int sum = maxPath(root, maxPS);
    return maxPS;
}