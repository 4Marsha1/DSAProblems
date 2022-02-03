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

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->val == ptr->next->val)
        {
            ListNode *temp = ptr->next;
            ptr->next = temp->next;
            delete (temp);
        }
        else
            ptr = ptr->next;
    }
    return head;
}
