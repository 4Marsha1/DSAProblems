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

// Brute Force --------> hashing
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    unordered_set<ListNode *> hash;
    ListNode *dumA = headA;
    ListNode *dumB = headB;
    while (dumA != NULL)
    {
        hash.insert(dumA);
        dumA = dumA->next;
    }
    while (dumB != NULL)
    {
        if (hash.find(dumB) != hash.end())
        {
            return dumB;
        }
        dumB = dumB->next;
    }
    return NULL;
}

// Better Solution
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    ListNode *dumA = headA;
    ListNode *dumB = headB;
    int lenA = 0, lenB = 0;
    while (dumA != NULL)
    {
        lenA++;
        dumA = dumA->next;
    }
    while (dumB != NULL)
    {
        lenB++;
        dumB = dumB->next;
    }
    dumA = headA;
    dumB = headB;
    if (lenB > lenA)
    {
        int diff = lenB - lenA;
        for (int i = 0; i < diff; i++)
            dumB = dumB->next;
    }
    else
    {
        int diff = lenA - lenB;
        for (int i = 0; i < diff; i++)
            dumA = dumA->next;
    }
    while (dumA != dumB)
    {
        if (dumA == dumB)
            return dumA;
        dumA = dumA->next;
        dumB = dumB->next;
    }
    return dumA;
}

// optimal solution
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    ListNode *dumA = headA;
    ListNode *dumB = headB;
    while (dumA != dumB)
    {
        if (dumA == NULL)
            dumA = headB;
        else
            dumA = dumA->next;
        if (dumB == NULL)
            dumB = headA;
        else
            dumB = dumB->next;
    }
    return dumA;
}
