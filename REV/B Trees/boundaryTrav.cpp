class Solution
{
public:
    bool isLeaf(Node *root)
    {
        if (root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    void travL(Node *root, vector<int> &left)
    {
        Node *cur = root;
        while (cur)
        {
            if (!isLeaf(cur))
                left.push_back(cur->data);
            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
    void travR(Node *root, vector<int> &right)
    {
        Node *cur = root;
        while (cur)
        {
            if (!isLeaf(cur))
                right.push_back(cur->data);
            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
    }
    void travLeaf(Node *root, vector<int> &leaf)
    {
        if (isLeaf(root))
        {
            leaf.push_back(root->data);
            return;
        }
        if (root->left)
            travLeaf(root->left, leaf);
        if (root->right)
            travLeaf(root->right, leaf);
    }
    vector<int> boundary(Node *root)
    {
        vector<int> left;
        vector<int> right;
        vector<int> leaf;
        left.push_back(root->data);
        if (isLeaf(root))
            return left;
        travL(root->left, left);
        travR(root->right, right);
        travLeaf(root, leaf);
        for (int i = 0; i < leaf.size(); i++)
            left.push_back(leaf[i]);
        for (int i = right.size() - 1; i >= 0; i--)
            left.push_back(right[i]);
        return left;
    }
};