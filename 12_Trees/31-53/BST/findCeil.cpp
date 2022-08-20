int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    int ceil = -1;
    while (root)
    {
        if (root->data == input)
            return root->data;
        else if (root->data > input)
        {
            ceil = root->data;
            root = root->left;
        }
        else
            root = root->right;
    }
    return ceil;
}