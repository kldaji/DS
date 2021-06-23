/*
* LinkedList with Dummy Node AST Sorted Version
*/

#include <stdio.h>
#include "DLinkedList.h"
#include "DLinkedList.c"

// ascending order
int comp(int d1, int d2)
{
    if (d1 < d2)
        return 0;
    else
        return 1;
}

int main()
{
    // Declare Variable
    List list;
    int data;

    // Init List
    ListInit(&list);

    // Set Sort Rule
    SetSortRule(&list, comp);

    // Insert datas
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    // Current Number of Datas
    printf("현재 데이터 수 : %d\n", LCount(&list));

    // Print All Datas
    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
        {
            printf("%d ", data);
        }
    }
    printf("\n");

    // Remove Target Datas
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
    printf("\n");

    // Current Number of Datas
    printf("현재 데이터 수 : %d\n", LCount(&list));
    // Print All Datas
    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
        {
            printf("%d ", data);
        }
    }
    printf("\n");

    return 0;
}