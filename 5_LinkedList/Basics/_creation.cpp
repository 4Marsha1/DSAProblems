#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
};

// pass by reference
void insertNode(Node **head, int x)
{
    Node *new_node = new Node(x);
    if (*head == NULL)
        *head = new_node;
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

// pass by value
Node *insertNode(Node *&head, int x)
{
    Node *new_node = new Node(x);
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        return temp;
    }
}

void displayLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        insertNode(&head, x);
    }
    displayLL(head);
    return 0;
}