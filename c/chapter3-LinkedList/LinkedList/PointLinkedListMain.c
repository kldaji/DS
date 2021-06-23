#include <stdio.h>

#include "DLinkedList.h"
#include "DLinkedList.c"

// Absoulte Path
#include "C:\Users\kim young uk\Desktop\GitHub\DS\c\chapter3-LinkedList\ArrayList\Point.h"
#include "C:\Users\kim young uk\Desktop\GitHub\DS\c\chapter3-LinkedList\ArrayList\Point.c"

// x ascending order
int comp(Point *p1, Point *p2)
{
    if (p1->xpos < p2->xpos)
        return 0;
    else if (p1->xpos == p2->xpos)
    {
        if (p1->ypos < p2->ypos)
            return 0;
        else
            return 1;
    }
    else
        return 1;
}

int main()
{
    // Declare Variables
    List list;
    Point *ppos;
    Point compPos;

    ListInit(&list);

    // Insert Datas
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);

    printf("Current Number of Data : %d\n", LCount(&list));

    // Show All Datas
    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while (LNext(&list, &ppos))
            ShowPointPos(ppos);
    }

    printf("\n");

    // Target Point
    compPos.xpos = 2;
    compPos.ypos = 0;

    if (LFirst(&list, &ppos))
    {
        // Remove
        if (PointComp(ppos, &compPos) == 1)
        {
            ppos = LRemove(&list);
            free(ppos);
        }

        while (LNext(&list, &ppos))
        {
            // Remove
            if (PointComp(ppos, &compPos) == 1)
            {
                ppos = LRemove(&list);
                free(ppos);
            }
        }
    }

    printf("Current Number of Data : %d\n", LCount(&list));

    // Show All Datas
    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while (LNext(&list, &ppos))
            ShowPointPos(ppos);
    }

    printf("\n");

    return 0;
}
