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

ListNode *merge(ListNode *h1, ListNode *h2)
{
    if (h1 == NULL or h2 == NULL)
    {
        return (h1 == NULL) ? h2 : h1;
    }
    if (h1->val < h2->val)
    {
        h1->next = merge(h1->next, h2);
        return h1;
    }
    else
    {
        h2->next = merge(h1, h2->next);
        return h2;
    }
}

ListNode *mergeSort(ListNode *head)
{
    if (head == NULL or head->next == NULL)
        return head;
    // finding midpoint
    ListNode *slow = head, *fast = head;
    ListNode *prev = slow;
    while (fast != NULL and fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    // Sorting left half (0 -> mid-1)
    ListNode *h1 = mergeSort(head);
    // Sorting right half (mid -> n-1)
    ListNode *h2 = mergeSort(slow);
    // Merging sorted halves
    return merge(h1, h2);
}