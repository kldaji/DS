/*
* LinkedList with Dummy Node AST Version
*/
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List *plist)
{
    // Create Dummy Node
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;

    plist->comp = NULL;
    plist->numOfData = 0;
}

void FInsert(List *plist, LData data)
{
    // Create New Node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    // Link
    newNode->next = plist->head->next;
    plist->head->next = newNode;

    (plist->numOfData)++;
}

void SInsert(List *plist, LData data)
{
    // Create New Node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    // Pointer of Dummy Node
    Node *cur = plist->head;

    // Find Correct Index
    while (cur->next != NULL && plist->comp(data, cur->next->data) != 0)
        cur = cur->next;

    // Link
    newNode->next = cur->next;
    cur->next = newNode;

    (plist->numOfData)++;
}

void LInsert(List *plist, LData data)
{
    if (plist->comp == NULL)
    {
        // No sorting
        FInsert(plist, data);
    }
    else
    {
        SInsert(plist, data);
    }
}

int LFirst(List *plist, LData *pdata)
{
    if (plist->head->next == NULL)
        return FALSE; // Fail

    plist->before = plist->head;
    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE; // Success
}

int LNext(List *plist, LData *pdata)
{
    if (plist->cur->next == NULL)
        return FALSE; // Fail

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE; // Success
}

LData LRemove(List *plist)
{
    Node *rpos = plist->cur;
    LData rdata = rpos->data;

    plist->before->next = rpos->next;
    plist->cur = plist->before;

    free(rpos);

    (plist->numOfData)--;
    return rdata;
}
int LCount(List *plist)
{
    return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}