#include <stdio.h>
#include "ArrayList.h"

// Init ArrayList
void ListInit(List *plist)
{
    plist->numOfData = 0;
    plist->curPosition = -1;
}

void LInsert(List *plist, LData data)
{
    // ArrayList Full Condition
    if (plist->numOfData >= LIST_LEN)
    {
        puts("Array is full\n");
        return;
    }

    // Insert data
    plist->arr[plist->numOfData] = data;
    (plist->numOfData)++;
}

// Get First Data
int LFirst(List *plist, LData *pdata)
{
    // ArrayList Empty Condition
    if (plist->numOfData == 0)
        // Fail
        return FALSE;

    //  Peek First Data
    plist->curPosition = 0;
    *pdata = plist->arr[0];

    // Success
    return TRUE;
}

// Get Next Data
int LNext(List *plist, LData *pdata)
{
    // Out-of-Range Check Condition
    if (plist->curPosition >= (plist->numOfData) - 1)
        // Fail
        return FALSE;

    // Get Next Data
    (plist->curPosition)++;
    *pdata = plist->arr[plist->curPosition];

    // Success
    return TRUE;
}

LData LRemove(List *plist)
{
    // Removed Data
    int rpos = plist->curPosition;
    int num = plist->numOfData;
    int i;
    LData rdata = plist->arr[rpos];

    // Shift Datas
    for (i = rpos; i < num - 1; i++)
        plist->arr[i] = plist->arr[i + 1];

    (plist->numOfData)--;
    (plist->curPosition)--;

    // Retrun removed data
    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}