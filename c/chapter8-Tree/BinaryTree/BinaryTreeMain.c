#include <stdio.h>
#include "BinaryTree.h"
#include "BinaryTree.c"

int main()
{
    BTreeNode *n1 = MakeBTreeNode();
    BTreeNode *n2 = MakeBTreeNode();
    BTreeNode *n3 = MakeBTreeNode();
    BTreeNode *n4 = MakeBTreeNode();

    SetData(n1, 1);
    SetData(n2, 2);
    SetData(n3, 3);
    SetData(n4, 4);

    /*
        1
       / \
      2  3
     /
    4
    */
    MakeLeftSubTree(n1, n2);
    MakeRightSubTree(n1, n3);
    MakeLeftSubTree(n2, n4);

    printf("%d\n", GetData(GetLeftSubTree(n1)));                 // 2
    printf("%d\n", GetData(GetLeftSubTree(GetLeftSubTree(n1)))); // 4

    return 0;
}