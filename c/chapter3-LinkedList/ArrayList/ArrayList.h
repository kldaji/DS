#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include "Point.h"
#include "NameCard.h"

#define TRUE 1
#define FALSE 0

// Fixed Size
#define LIST_LEN 100

/*
** ListMain.c
*/
// typedef int LData;

/*
** PointListMain.c
*/
// typedef Point *LData;

/*
** NameCardListMain.c
*/
typedef NameCard *LData;

// ArrayList Structure
typedef struct __ArrayList
{
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition;
} ArrayList;

// Rename
typedef ArrayList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

#endif
