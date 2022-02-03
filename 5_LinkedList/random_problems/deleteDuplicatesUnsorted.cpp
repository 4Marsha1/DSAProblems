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

ListNode *deleteDuplicatesUnsorted(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    unordered_set<int> hash;
    ListNode *curr = head, *prev = NULL;
    while (curr != NULL)
    {
        if (hash.find(curr->val) != hash.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            hash.insert(curr->val);
            prev = curr;
        }
        curr = prev->next;
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
    deleteDuplicatesUnsorted(head);
    display(head);
}