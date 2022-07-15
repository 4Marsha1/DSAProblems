#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Left Boundary
// Leaf Nodes
// Right Boundary in Reverse

bool isLeaf(Node *node)
{
    if (node->left == NULL and node->right == NULL)
        return true;
    return false;
}
void traverseLeftBoundary(Node *root, vector<int> &ds)
{
    Node *cur = root;
    while (cur)
    {
        if (!isLeaf(cur))
            ds.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}
void traverseRightBoundary(Node *root, vector<int> &ds)
{
    Node *cur = root;
    while (cur)
    {
        if (!isLeaf(cur))
            ds.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
}
void traverseLeaves(Node *root, vector<int> &ds)
{
    if (isLeaf(root))
    {
        ds.push_back(root->data);
        return;
    }
    if (root->left)
        traverseLeaves(root->left, ds);
    if (root->right)
        traverseLeaves(root->right, ds);
}
vector<int> boundary(Node *root)
{
    vector<int> left;
    vector<int> leaf;
    vector<int> right;
    left.push_back(root->data);
    if (isLeaf(root))
    {
        return left;
    }
    traverseLeftBoundary(root->left, left);
    traverseRightBoundary(root->right, right);
    traverseLeaves(root, leaf);
    for (int i = 0; i < leaf.size(); i++)
        left.push_back(leaf[i]);
    for (int i = right.size() - 1; i >= 0; i--)
        left.push_back(right[i]);
    return left;
}