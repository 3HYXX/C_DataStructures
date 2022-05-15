#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct AvlNode;
typedef struct AvlNode * Position;
typedef Position AvlTree;

struct AvlNode
{
    ElementType element;
    AvlTree left;
    AvlTree right;
    int height;
};

int Height(Position P)
{
    if(P == NULL)
        return -1;
    else
        return P->height;
}

AvlTree MakeEmpty(AvlTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}


Position Find(AvlTree T,ElementType X)
{
    if(T == NULL)
        return NULL;
    if(X < T->element)
        return Find(T->left,X);
    else if(X > T->element)
        return Find(T->right,X);
    else
        return T;
}

Position FindMin(AvlTree T)
{
    if(T == NULL)
        return NULL;
    else if(T->left == NULL)
        return T;
    else return FindMin(T->left);
}

Position FindMax(AvlTree T)
{
    if(T != NULL)
    {
        while (T->right != NULL)
            T = T->right;
    }
    return T;
}

int Max(int a,int b)
{
    if( a > b)
        return a;
    else
        return b;
}

AvlTree SingleLeftRotatation(AvlTree A)
{
    AvlTree B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = Max(Height(A->left),Height(A->right)) + 1;
    B->height = Max(Height(B->left),A->height) + 1;

    return B;
}

AvlTree SingleRightRotatation(AvlTree A)
{
    AvlTree B = A->right;
    A->right = B->left;
    B->left = A;

    A->height = Max(Height(A->left),Height(A->right)) + 1;
    B->height = Max(Height(B->right),A->height) + 1;

    return B;
}

AvlTree DoubleLeftRightRotation(AvlTree A)
{
    A->left = SingleRightRotatation(A->left);
    return SingleLeftRotatation(A);
}

AvlTree DoubleRightLeftRotation(AvlTree A)
{
    A->right = SingleLeftRotatation(A->right);
    return SingleRightRotatation(A);
}

AvlTree Insert(AvlTree T,ElementType X)
{
    if(T == NULL)
    {
        T = malloc(sizeof(struct AvlNode));
        T->element = X;
        T->left = T->right = NULL;
        T->height = 0;
    }
    else if(X < T->element)
    {
        T->left = Insert(T->left,X);
        if(Height(T->left) - Height(T->right) == 2)
        {
            if(X < T->left->element)
                T = SingleLeftRotatation(T);
            else
                T = DoubleLeftRightRotation(T);
        }
    }
    else if(X > T->element)
    {
        T->right = Insert(T->right,X);
        if(Height(T->left) - Height(T->right) == -2)
        {
            if(X > T->right->element)
                T = SingleRightRotatation(T);
            else
                T = DoubleRightLeftRotation(T);
        }
    }
    T->height = Max(Height(T->left),Height(T->right)) + 1;
    return T;
}

int main()
{
    AvlTree T = NULL;
    T = Insert(T,8);
    T = Insert(T,10);
    T = Insert(T,4);
    T = Insert(T,1);
    T = Insert(T,3);

    AvlTree tmp = FindMin(T);
    //printf("####%d####\n",tmp->element);
    printf("####%d####\n",T->left->element);
    return 0;
}