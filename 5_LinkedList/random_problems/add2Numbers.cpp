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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int sum = 0;
    ListNode *new_list = new ListNode();
    ListNode *dum = new_list;
    while (l1 || l2)
    {
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        ListNode *new_node = new ListNode(sum % 10);
        sum /= 10;
        new_list->next = new_node;
        new_list = new_list->next;
    }
    if (sum != 0)
    {
        ListNode *new_node = new ListNode(sum);
        new_list->next = new_node;
        new_list = new_list->next;
    }
    return dum->next;
}