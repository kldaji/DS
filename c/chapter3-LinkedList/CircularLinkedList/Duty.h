#ifndef __DUTY_H__
#define __DUTY_H__

typedef struct _employee
{
    int empno;
    char name[30];
} Employee;

void setEmployee(Employee *pemp, int empno, char *name);

void showEmployee(Employee *pemp);

#endif