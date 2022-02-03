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

// main function
ListNode *deleteLL(ListNode *&head)
{
    while (head != NULL)
    {
        ListNode *temp = head;
        head = head->next;
        delete (temp);
    }
    return head;
}

// boiler plate
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
    if (temp == NULL)
    {
        cout << "Empty LL";
        return;
    }
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
    deleteLL(head);
    display(head);
}