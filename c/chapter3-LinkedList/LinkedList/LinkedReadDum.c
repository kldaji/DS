/*
* Pointer : tail
* Dummy Node(head) Version 
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

    // Create Dummy Node
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    tail = head;

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

        tail->next = newNode;
        tail = newNode;
    }

    printf("\n");

    // Print ALl Datas
    if (head->next == NULL)
        printf("저장된 자연수가 존재하지 않습니다.\n");
    else
    {
        Node *cur = head->next;
        while (cur != NULL)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
    }
    printf("\n");

    // Free All Datas
    if (head->next == NULL)
        return 0;
    else
    {
        Node *delNode = head;
        Node *delNextNode = delNode->next;

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