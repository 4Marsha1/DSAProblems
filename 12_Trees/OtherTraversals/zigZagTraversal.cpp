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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    deque<TreeNode *> q;
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    q.push_back(root);
    bool order = false;
    while (!q.empty())
    {
        vector<int> level;
        int n = q.size();
        order = !order;
        cout << order << " ";
        for (int i = 0; i < n; i++)
        {
            TreeNode *node;
            if (!order)
            {
                node = q.front();
                q.pop_front();
                if (node->right)
                    q.push_back(node->right);
                if (node->left)
                    q.push_back(node->left);
            }
            else
            {
                node = q.back();
                q.pop_back();
                if (node->left)
                    q.push_front(node->left);
                if (node->right)
                    q.push_front(node->right);
            }
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}