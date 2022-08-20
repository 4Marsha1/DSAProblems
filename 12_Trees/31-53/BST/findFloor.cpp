int floorInBST(TreeNode<int> *root, int X)
{
    if (root == NULL)
        return -1;
    int floor = -1;
    while (root)
    {
        if (root->val == X)
            return root->val;
        else if (root->val > X)
            root = root->left;
        else
        {
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}