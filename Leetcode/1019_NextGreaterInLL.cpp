#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nextLargerNodes(ListNode *head)
{
    vector<int> ans;
    ListNode *ptr = head;
    while (ptr->next != NULL)
    {
        ListNode *dum = ptr->next;
        while (dum != NULL)
        {
            if (dum->val > ptr->val)
            {
                ans.push_back(dum->val);
                break;
            }
            dum = dum->next;
        }
        if (dum == NULL)
            ans.push_back(0);
        ptr = ptr->next;
    }
    ans.push_back(0);
    return ans;
}