#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist)
{
    // Dummy nodes
    plist->head = (Node *)malloc(sizeof(Node));
    plist->tail = (Node *)malloc(sizeof(Node));

    // set next & prev
    plist->head->next = plist->tail;
    plist->head->prev = NULL;

    plist->tail->next = NULL;
    plist->tail->prev = plist->head;

    plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
    // Create new node
    Node *newNode = (Node *)malloc(sizeof(Node));

    // node setting
    newNode->data = data;
    newNode->prev = plist->tail->prev;
    newNode->next = plist->tail;
    plist->tail->prev->next = newNode;
    plist->tail->prev = newNode;

    // increse number of nodes
    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
    if (plist->head->next == plist->tail)
    {
        // no node
        return FALSE;
    }

    // setting current node
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List *plist, Data *pdata)
{
    if (plist->cur->next == plist->tail)
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
    if (plist->cur->prev == plist->head)
    {
        // end node
        return FALSE;
    }

    // set prev node
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;

    return TRUE;
}

int LRemove(List *plist)
{
    Node *rpos = plist->cur;
    Data ret = rpos->data;

    rpos->prev->next = rpos->next;
    rpos->next->prev = rpos->prev;

    plist->cur = plist->cur->prev;

    free(rpos);
    (plist->numOfData)--;

    return ret;
}

int LCount(List *plist)
{
    return plist->numOfData;
}