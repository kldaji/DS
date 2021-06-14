#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "ArrayList.c"
#include "NameCard.h"
#include "NameCard.c"

int main()
{
    List list;
    NameCard *pcard;

    ListInit(&list);

    pcard = MakeNameCard("KIM", "010-1111-1111");
    LInsert(&list, pcard);

    pcard = MakeNameCard("LEE", "010-2222-2222");
    LInsert(&list, pcard);

    pcard = MakeNameCard("PARK", "010-3333-3333");
    LInsert(&list, pcard);

    if (LFirst(&list, &pcard))
    {
        if (!NameCompare(pcard, "KIM"))
            ShowNameCardInfo(pcard);
        else
        {
            while (LNext(&list, &pcard))
            {
                if (!NameCompare(pcard, "KIM"))
                {
                    ShowNameCardInfo(pcard);
                    break;
                }
            }
        }
    }

    if (LFirst(&list, &pcard))
    {
        if (!NameCompare(pcard, "LEE"))
            ChangePhoneNum(pcard, "010-3333-3333");
        else
        {
            while (LNext(&list, &pcard))
            {
                if (!NameCompare(pcard, "LEE"))
                {
                    ChangePhoneNum(pcard, "010-3333-3333");
                    break;
                }
            }
        }
    }

    if (LFirst(&list, &pcard))
    {
        if (!NameCompare(pcard, "PARK"))
        {
            pcard = LRemove(&list);
            free(pcard);
        }
        else
        {
            while (LNext(&list, &pcard))
            {
                if (!NameCompare(pcard, "PARK"))
                {
                    pcard = LRemove(&list);
                    free(pcard);
                    break;
                }
            }
        }
    }

    if (LFirst(&list, &pcard))
    {
        ShowNameCardInfo(pcard);

        while (LNext(&list, &pcard))
            ShowNameCardInfo(pcard);
    }

    return 0;
}