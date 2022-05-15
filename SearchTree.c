#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct TreeNode;
typedef struct TreeNode * Position;
typedef Position SearchTree;

struct TreeNode
{
    ElementType element;
    SearchTree left;
    SearchTree right;
};

SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

Position Find(SearchTree T,ElementType X)
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

Position FindMin(SearchTree T)
{
    if(T == NULL)
        return NULL;
    else if(T->left == NULL)
        return T;
    else return FindMin(T->left);
}

Position FindMax(SearchTree T)
{
    if(T != NULL)
    {
        while (T->right != NULL)
            T = T->right;
    }
    return T;
}

SearchTree Insert(SearchTree T,ElementType X)
{
    if(T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        T->element = X;
        T->left = NULL;
        T->right = NULL;
        //printf("CHILL!!\n");
    }
    else if(X < T->element)
        T->left = Insert(T->left,X);
    else if(X > T->element)
        T->right = Insert(T->right,X);

    //printf("CHILLasdasdasd!!\n");
    return T;
}

SearchTree Delete(SearchTree T,ElementType X)
{
    Position TmpCell;
    if(T == NULL)
    {
        printf("ERROR!!!Element not found\n");
        return NULL;
    }
    else if(X < T->element)
        T->left = Delete(T->left,X);
    else if(X > T->element)
        T->right = Delete(T->right,X);
    else if(T->left && T->right)
    {
        TmpCell = FindMin(T->right);
        T->element = TmpCell->element;
        T->right = Delete(T->right,T->element);
    }
    else{
        TmpCell = T;
        if(T->left == NULL)
            T = T->right;
        else if(T->right == NULL)
            T = T->left;
            free(TmpCell);
    }
    return T;
}


int main()
{
    SearchTree T1 = NULL;
    //MakeEmpty(T1);
    T1 = Insert(T1,5);
    T1 = Insert(T1,2);
    T1 = Insert(T1,7);
    T1 = Insert(T1,1);
    T1 = Insert(T1,3);
    
    T1 = Delete(T1,1);
    SearchTree tmp = FindMin(T1);
    printf("####%d####\n",tmp->element);
    return 0;
}