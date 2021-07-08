#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist)
{
    plist->head = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
    // Create new node
    Node *newNode = (Node *)malloc(sizeof(Node));

    // node setting
    newNode->data = data;
    newNode->next = plist->head;
    newNode->prev = NULL;

    // setting prev
    if (plist->head != NULL)
    {
        plist->head->prev = newNode;
    }

    // head setting
    plist->head = newNode;

    // increse number of nodes
    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
    if (plist->head == NULL)
    {
        // no node
        return FALSE;
    }

    // setting current node
    plist->cur = plist->head;
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List *plist, Data *pdata)
{
    if (plist->cur->next == NULL)
    {
        // end node
        return FALSE;
    }

    // set next node
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}

int LPrevious(List *plist, Data *pdata)
{
    if (plist->cur->prev == NULL)
    {
        // end node
        return FALSE;
    }

    // set prev node
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;

    return TRUE;
}

int LCount(List *plist)
{
    return plist->numOfData;
}