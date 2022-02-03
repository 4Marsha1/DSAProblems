#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
};

Node *insertNodeAtEnd(Node *&head, int x)
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

Node *insertNodeAtBegin(Node *&head, int x)
{
    Node *new_node = new Node(x);
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    else
    {
        new_node->next = head;
        head = new_node;
        return head;
    }
}

Node *insertNodeAtPos(Node *&head, int x, int pos)
{
    Node *new_node = new Node(x);
    if (pos == 0)
    {
        new_node->next = head;
        head = new_node;
        return head;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;
        new_node->next = temp->next;
        temp->next = new_node;
        return temp;
    }
}

void insertNodeAfterNode(Node *prevNode, int x)
{
    Node *new_node = new Node(x);
    new_node->next = prevNode->next;
    prevNode->next = new_node;
}

Node *deleteNodeAtPos(Node *&head, int pos)
{
    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
        return head;
    }
    else
    {
        Node *temp1 = head;
        for (int i = 0; i < pos - 1; i++)
            temp1 = temp1->next;
        Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete (temp2);
        return temp1;
    }
}

Node *deleteNodeByValue(Node *&head, int val)
{
    Node *temp1 = head;
    if (temp1->data == val)
    {
        head = temp1->next;
        delete (temp1);
        return head;
    }
    while (temp1->next != NULL)
    {
        if (temp1->next->data == val)
        {
            Node *temp2 = temp1->next;
            temp1->next = temp2->next;
            delete (temp2);
            return temp1;
        }
        temp1 = temp1->next;
    }
    return temp1;
}

Node *reverseIterative(Node *&head)
{
    Node *curr = head, *prev = NULL, *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

Node *reverseRecursive(Node *&head)
{
    if (head == NULL)
        return head;
    Node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    head = newHead;
    return head;
}

void printRecursive(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    printRecursive(head->next);
}

void printRecursiveReverse(Node *head)
{
    if (head == NULL)
        return;
    printRecursiveReverse(head->next);
    cout << head->data << " ";
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 6; i++)
    {
        int x;
        cin >> x;
        insertNodeAtEnd(head, x);
    }
    display(head);
    insertNodeAtBegin(head, 10);
    display(head);
    insertNodeAtPos(head, 100, 3);
    display(head);
    insertNodeAfterNode(head->next, 200);
    display(head);
    deleteNodeAtPos(head, 4);
    display(head);
    deleteNodeByValue(head, 5);
    display(head);
    cout << "Recursion" << endl;
    printRecursive(head);
    cout << endl;
    printRecursiveReverse(head);
    cout << endl;
    cout << "Reverse" << endl;
    reverseIterative(head);
    display(head);
    reverseRecursive(head);
    display(head);
}
