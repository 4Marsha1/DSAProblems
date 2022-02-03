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

ListNode *reverse(ListNode *head)
{
    ListNode *curr = head, *prev = NULL, *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    ListNode *slow = head, *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = reverse(slow);
    ListNode *Head = head;
    while (slow != NULL)
    {
        if (Head->val != slow->val)
            return false;
        Head = Head->next;
        slow = slow->next;
    }
    return true;
}
