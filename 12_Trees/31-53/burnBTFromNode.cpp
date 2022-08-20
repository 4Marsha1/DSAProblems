/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int getTime(map<TreeNode *, TreeNode *> &mpp, TreeNode *target)
{
    queue<TreeNode *> q;
    map<TreeNode *, int> vis;
    q.push(target);
    vis[target] = 1;
    int maxi = 0;
    while (!q.empty())
    {
        int size = q.size();
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left && !vis[node->left])
            {
                flag = 1;
                q.push(node->left);
                vis[node->left] = 1;
            }
            if (node->right && !vis[node->right])
            {
                flag = 1;
                q.push(node->right);
                vis[node->right] = 1;
            }
            if (mpp[node] && !vis[mpp[node]])
            {
                flag = 1;
                q.push(mpp[node]);
                vis[mpp[node]] = 1;
            }
        }
        if (flag)
            maxi++;
    }
    return maxi;
}
TreeNode *getParent(TreeNode *A, map<TreeNode *, TreeNode *> &mpp, int B)
{
    queue<TreeNode *> q;
    TreeNode *res;
    q.push(A);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->val == B)
            res = node;
        if (node->left)
        {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}
int Solution::solve(TreeNode *A, int B)
{
    map<TreeNode *, TreeNode *> mpp;
    TreeNode *target = getParent(A, mpp, B);
    int time = getTime(mpp, target);
    return time;
}
