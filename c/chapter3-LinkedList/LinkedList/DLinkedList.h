/*
* LinkedList with Dummy Node AST Version
*/
#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#include "C:\Users\kim young uk\Desktop\GitHub\DS\c\chapter3-LinkedList\ArrayList\Point.h"

#define TRUE 1
#define FALSE 0

/*
* DLinkedListMain.c
*/
// typedef int LData;

/*
* PointLinkedListMain.c
*/
typedef Point *LData;

// Node
typedef struct _node
{
    LData data;
    struct _node *next;
} Node;

// LinkedList
typedef struct _linkedList
{
    Node *head; // Dummy Node
    Node *cur;  //
    Node *before;
    int numOfData;                   // Number of Nodes
    int (*comp)(LData d1, LData d2); // Sorting Condition
} LinkedList;

typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));

#endif