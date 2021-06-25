#include <stdio.h>
#include "CLinkedList.h"
#include "CLinkedList.c"

int main()
{
    List list;
    int data, i, nodeNum;

    ListInit(&list);

    LInsert(&list, 3);      // 3
    LInsert(&list, 4);      // 3 4
    LInsert(&list, 5);      // 3 4 5
    LInsertFront(&list, 2); // 2 3 4 5
    LInsertFront(&list, 1); // 1 2 3 4 5

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        // 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5
        for (i = 0; i < LCount(&list) * 3 - 1; i++)
            if (LNext(&list, &data))
                printf("%d ", data);
    }
    printf("\n");

    nodeNum = LCount(&list);

    if (nodeNum != 0)
    {
        LFirst(&list, &data);

        // remove even number
        if (data % 2 == 0)
            LRemove(&list);

        for (i = 0; i < nodeNum; i++)
        {
            LNext(&list, &data);
            if (data % 2 == 0)
                LRemove(&list);
        }
    }

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        // 1 3 5
        for (i = 0; i < LCount(&list) - 1; i++)
            if (LNext(&list, &data))
                printf("%d ", data);
    }

    return 0;
}