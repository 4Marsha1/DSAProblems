#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<Node *, int>> q;
    map<int, int> lineNode;
    q.push({root, 0});
    while (!q.empty())
    {
        Node *node = q.front().first;
        int x = q.front().second;
        q.pop();
        lineNode[x] = node->data;
        if (node->left)
            q.push({node->left, x - 1});
        if (node->right)
            q.push({node->right, x + 1});
    }
    for (auto it : lineNode)
        ans.push_back(it.second);
    return ans;
}