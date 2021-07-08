#include <stdio.h>
#include "DBLinkedList.h"
#include "DBLinkedList.c"

int main()
{
    // local variable
    List list;
    int data;

    // list init
    ListInit(&list);

    // insert
    LInsert(&list, 1); // 1
    LInsert(&list, 2); // 1 2
    LInsert(&list, 3); // 1 2 3
    LInsert(&list, 4); // ...
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);

        // while (LPrevious(&list, &data))
        //     printf("%d ", data);
    }
    printf("\n");

    if (LFirst(&list, &data))
    {
        if (data % 2 == 0)
        {
            LRemove(&list);
        }
        while (LNext(&list, &data))
        {
            if (data % 2 == 0)
            {
                LRemove(&list);
            }
        }
    }

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }

    return 0;
}