#include <stdio.h>
#include "ArrayList.h"
#include "ArrayList.c"

int main()
{
    // Declare Variables
    List list;
    int data;

    // Init
    ListInit(&list);

    // Insert Datas
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    printf("Current Number of Data : %d\n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    // Remove 22
    if (LFirst(&list, &data))
    {
        if (data == 22)
            LRemove(&list);

        while (LNext(&list, &data))
        {
            if (data == 22)
                LRemove(&list);
        }
    }

    printf("Current Number of Data : %d\n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    return 0;
}