#include <stdio.h>
#include <string.h>
#include "Duty.h"

void setEmployee(Employee *pemp, int empno, char *name)
{
    pemp->empno = empno;
    strcpy(pemp->name, name);
}

void showEmployee(Employee *pemp)
{
    printf("[Empolyee Number] : %d\n", pemp->empno);
    printf("[Empolyee Name] : %s\n", pemp->name);
}