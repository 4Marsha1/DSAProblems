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

vector<int> ans;
void postorder(TreeNode *node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    ans.push_back(node->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    postorder(root);
    return ans;
}