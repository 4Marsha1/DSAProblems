#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<Node *, int>> q;
    map<int, int> levelNode;
    q.push({root, 0});
    while (!q.empty())
    {
        Node *node = q.front().first;
        int y = q.front().second;
        q.pop();
        if (levelNode.find(y) == levelNode.end())
            levelNode[y] = node->data;
        if (node->left)
            q.push({node->left, y + 1});
        if (node->right)
            q.push({node->right, y + 1});
    }
    for (auto it : levelNode)
        ans.push_back(it.second);
    return ans;
}