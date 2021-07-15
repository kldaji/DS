#include <stdio.h>
#include "BinaryTree.h"
#include "BinaryTree.c"

/*
 * 1. Preorder (root -> left -> right)
 * 2. Inorder  (left -> root -> right)
 * 3. Postorder (left -> right -> root)
*/

void ShowIntData(int data);

int main()
{
    BTreeNode *n1 = MakeBTreeNode();
    BTreeNode *n2 = MakeBTreeNode();
    BTreeNode *n3 = MakeBTreeNode();
    BTreeNode *n4 = MakeBTreeNode();
    BTreeNode *n5 = MakeBTreeNode();
    BTreeNode *n6 = MakeBTreeNode();

    SetData(n1, 1);
    SetData(n2, 2);
    SetData(n3, 3);
    SetData(n4, 4);
    SetData(n5, 5);
    SetData(n6, 6);

    /*
          1
       /    \
      2      3
     / \    /
    4   5  6
    */
    MakeLeftSubTree(n1, n2);
    MakeRightSubTree(n1, n3);
    MakeLeftSubTree(n2, n4);
    MakeRightSubTree(n2, n5);
    MakeLeftSubTree(n3, n6);

    PreorderTraverse(n1, ShowIntData);
    printf("\n");
    InorderTraverse(n1, ShowIntData);
    printf("\n");
    PostorderTraverse(n1, ShowIntData);
    printf("\n");
    return 0;
}

void ShowIntData(int data)
{
    printf("%d ", data);
}