#include <stdio.h>
#include "Point.h"

// Set Point Position
void SetPointPos(Point *ppos, int xpos, int ypos)
{
    ppos->xpos = xpos;
    ppos->ypos = ypos;
}

// Show Point
void ShowPointPos(Point *ppos)
{
    printf("[%d,%d] \n", ppos->xpos, ppos->ypos);
}

// Compare Point
int PointComp(Point *pos1, Point *pos2)
{
    if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)
        return 0;
    else if (pos1->xpos == pos2->xpos) // Problem : even if y values are different, point can be removed.
        return 1;
    else if (pos1->ypos == pos2->ypos)
        return 2;
    else
        return -1;
}
