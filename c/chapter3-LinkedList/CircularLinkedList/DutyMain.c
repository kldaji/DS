#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Duty.h"
#include "Duty.c"
#include "CLinkedList.h"
#include "CLinkedList.c"

Employee *whoIsNext(List *plist, char *name, int day)
{
    int i, num;

    Employee *ret;

    num = LCount(plist);

    LFirst(plist, &ret);

    if (strcmp(ret->name, name) != 0)
    {
        for (i = 0; i < num - 1; i++)
        {
            LNext(plist, &ret);

            if (strcmp(ret->name, name) == 0)
                break;
        }

        if (i >= num - 1)
            return NULL;
    }

    for (i = 0; i < day; i++)
        LNext(plist, &ret);

    return ret;
}

int main()
{
    int i;
    Employee *pemp;

    List list;
    ListInit(&list);

    pemp = (Employee *)malloc(sizeof(Employee));
    setEmployee(pemp, 1111, "Terry");
    LInsert(&list, pemp);

    pemp = (Employee *)malloc(sizeof(Employee));
    setEmployee(pemp, 2222, "Jery");
    LInsert(&list, pemp);

    pemp = (Employee *)malloc(sizeof(Employee));
    setEmployee(pemp, 3333, "Hary");
    LInsert(&list, pemp);

    pemp = (Employee *)malloc(sizeof(Employee));
    setEmployee(pemp, 4444, "Sunny");
    LInsert(&list, pemp);

    pemp = whoIsNext(&list, "Terry", 3);
    showEmployee(pemp);

    pemp = whoIsNext(&list, "Sunny", 15);
    showEmployee(pemp);

    if (LFirst(&list, &pemp))
    {
        free(pemp);

        for (i = 0; i < LCount(&list); i++)
            if (LNext(&list, &pemp))
                free(pemp);
    }

    return 0;
}
