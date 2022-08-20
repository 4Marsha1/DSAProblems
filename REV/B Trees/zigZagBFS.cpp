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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        deque<TreeNode *> q;
        q.push_back(root);
        bool flag = false;
        while (!q.empty())
        {
            TreeNode *node;
            vector<int> level;
            int n = q.size();
            flag = !flag;
            for (int i = 0; i < n; i++)
            {
                if (!flag)
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
};