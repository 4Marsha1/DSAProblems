/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = 0;
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;
        while (l1 != NULL || l2 != NULL)
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
            head->next = new ListNode(sum % 10);
            sum /= 10;
            head = head->next;
        }
        if (sum != 0)
        {
            head->next = new ListNode(sum % 10);
            sum /= 10;
            head = head->next;
        }
        return ptr->next;
    }
};