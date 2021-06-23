/*
* Pointer : head, tail
* The simplest LinkedList Version
*/

#include <stdio.h>
#include <stdlib.h>

// Node
typedef struct _node
{
    int data;
    struct _node *next;
} Node;

int main()
{
    // Declare Variables
    Node *head = NULL;
    Node *tail = NULL;

    Node *newNode = NULL;
    // Input Data
    int readData;

    while (1)
    {
        printf("자연수 입력 : ");
        scanf("%d", &readData);

        // break condition
        if (readData < 1)
            break;

        // Create new Node
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        // Link new Node
        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        // Set tail
        tail = newNode;
    }

    printf("\n");

    // Print ALl Datas
    if (head == NULL)
        printf("저장된 자연수가 존재하지 않습니다.\n");
    else
    {
        Node *cur = head;
        printf("%d ", cur->data);

        while (cur->next != NULL)
        {
            cur = cur->next;
            printf("%d ", cur->data);
        }
    }
    printf("\n");

    // Free All Datas
    if (head == NULL)
        return 0;
    else
    {
        Node *delNode = head;
        Node *delNextNode = head->next;
        printf("%d을(를) 삭제합니다.\n", delNode->data);
        free(delNode);

        while (delNextNode != NULL)
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;
            printf("%d을(를) 삭제합니다.\n", delNode->data);
            free(delNode);
        }
    }
    return 0;
}