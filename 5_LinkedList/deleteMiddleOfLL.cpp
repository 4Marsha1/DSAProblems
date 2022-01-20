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

// Required Function
ListNode *deleteMiddleNode(ListNode *&head)
{
    ListNode *slow = head, *fast = head;
    ListNode *prev = slow;
    while (fast != NULL and fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete (slow);
    return head;
}

// boiler Plate
ListNode *insert(ListNode *&head, int x)
{
    ListNode *new_node = new ListNode(x);
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    else
    {
        ListNode *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        return temp;
    }
}
void display(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    ListNode *head = NULL;
    for (int i = 0; i < 6; i++)
    {
        int x;
        cin >> x;
        insert(head, x);
    }
    display(head);
    deleteMiddleNode(head);
    display(head);
}