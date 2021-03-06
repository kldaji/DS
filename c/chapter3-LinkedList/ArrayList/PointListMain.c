#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "ArrayList.c"
#include "Point.h"
#include "Point.c"

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
