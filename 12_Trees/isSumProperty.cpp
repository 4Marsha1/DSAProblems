#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

int isSumProperty(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL and root->right == NULL)
        return true;
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;
    return ((root->data == child) && isSumProperty(root->left) &&
            isSumProperty(root->right));
}