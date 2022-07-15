/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans;
    vector<int> in, pre, post;
    stack<pair<BinaryTreeNode *, int>> st;
    if (root == NULL)
        return ans;
    st.push({root, 1});
    while (!st.empty())
    {
        BinaryTreeNode *node = st.top().first;
        int num = st.top().second;
        st.pop();
        if (num == 1)
        {
            pre.push_back(node->data);
            num++;
            st.push({node, num});
        }
        else if (num == 2)
        {
            in.push_back(node->data);
            num++;
            st.push({node, num});
        }
        else
        {
            post.push_back(node->val);
        }
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}