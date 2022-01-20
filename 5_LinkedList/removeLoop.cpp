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

ListNode *removeCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head, *entry = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (slow->next != entry->next)
            {
                slow = slow->next;
                entry = entry->next;
            }
            slow->next = NULL;
            return head;
        }
    }
    return head;
}
