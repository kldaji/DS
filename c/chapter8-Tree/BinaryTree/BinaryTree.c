#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// Create New Node
BTreeNode *MakeBTreeNode()
{
    BTreeNode *newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Get Node Data
BTData GetData(BTreeNode *bt)
{
    return bt->data;
}

// Set Node Data
void SetData(BTreeNode *bt, BTData data)
{
    bt->data = data;
}

// go to left
BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
    return bt->left;
}

// go to right
BTreeNode *GetRightSubTree(BTreeNode *bt)
{
    return bt->right;
}

// set left
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
    if (main->left != NULL)
        free(main->left);

    main->left = sub;
}

// set right
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    if (main->right != NULL)
        free(main->right);

    main->right = sub;
}

// preorder
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

// inorder
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

// postorder
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

// Delete node and it's all children
void DeleteTree(BTreeNode *bt)
{
    if (bt == NULL)
        return;

    DeleteTree(bt->left);
    DeleteTree(bt->right);
    free(bt);
}