#include <stdio.h>

// Binary Search Recursion Implementation
int BSearchRecur(int ar[], int first, int last, int target)
{
    int mid;

    // Not exist
    if (first > last)
        return -1;

    mid = (first + last) / 2;

    if (ar[mid] == target)
        return mid;
    else if (target > ar[mid])
        return BSearchRecur(ar, mid + 1, last, target);
    else
        return BSearchRecur(ar, first, mid - 1, target);
}

// Binary Search Loop Implementation
int BSearchLoop(int ar[], int len, int target)
{
    int first = 0;
    int last = len - 1;
    int mid;

    while (first <= last)
    {
        mid = (first + last) / 2;

        if (target == ar[mid])
            return mid;

        if (target < ar[mid])
            first = mid + 1;
        else
            last = mid - 1;
    }

    // Not exist
    return -1;
}

int main()
{
    // sorted array
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);

    if (idx == -1)
        printf("7 is not exist\n");
    else
        printf("7 exists at %d\n", idx);

    idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);

    if (idx == -1)
        printf("4 is not exist\n");
    else
        printf("4 exists at %d\n", idx);

    return 0;
}