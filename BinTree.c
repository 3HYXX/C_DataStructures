#include <stdio.h>
#include <stdlib.h>

#define MAXElement 10000

typedef int ElementType;
typedef struct TreeNode*  ElementType2;

struct TreeNode;
typedef struct TreeNode * PtrToNode;
typedef PtrToNode Tree;

struct TreeNode
{
    ElementType element;
    Tree left;
    Tree right;
};


Tree MakeTree(ElementType X)
{
    Tree T = malloc(sizeof(struct TreeNode));
    T->element = X;
    T->left = NULL;
    T->right = NULL;
    return T;
}

void InsertLeft(Tree T,ElementType X)
{
    if(!T->left)
    {
        Tree L = MakeTree(X);
        T->left = L;
    }
    
}

void InsertRight(Tree T,ElementType X)
{   if(!T->right)
    {
        Tree R = MakeTree(X);
        T->right = R;
    }
    
}

void PreOrderTraversal(Tree T)
{
    if(T)
    {
        printf("####%d####\n",T->element);
        PreOrderTraversal(T->left);
        PreOrderTraversal(T->right);
    }
}

void InOrderTraversal(Tree T)
{
    if(T)
    {
        InOrderTraversal(T->left);
        printf("####%d####\n",T->element);
        InOrderTraversal(T->right);
    }
    
}

void PostOrderTraversal(Tree T)
{
    if(T)
    {
        PostOrderTraversal(T->left);
        PostOrderTraversal(T->right);
        printf("####%d####\n",T->element);
    }
}

//Stack
struct StackRecord;
typedef struct StackRecord* Stack;

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType2* Array;
};

int IsSEmpty(Stack S)
{
    return S->TopOfStack == -1;
}

int IsSFull(Stack S)
{
    return S->TopOfStack == S->Capacity-1;
}

Stack CreateStack(int MaxElements)
{
    Stack S = malloc(sizeof(struct StackRecord));
    S->Array = malloc(sizeof(ElementType2)*MaxElements);
    S->Capacity = MaxElements;
    S->TopOfStack = -1;
    return S;
}

void DisPoseStack(Stack S)
{
    free(S->Array);
    free(S);
}

void MakeEmpty(Stack S)
{
    S->TopOfStack = -1;
}

void Push(ElementType2 X,Stack S)
{
    if(!IsSFull
(S))
    {
        S->Array[++S->TopOfStack] = X;
    }
}

ElementType2 Top(Stack S)
{
    if(!IsSEmpty(S))
        return S->Array[S->TopOfStack];
    else
    {
        printf("This Stack Is Empty!!!!\n");
        return 0;
    }
}

void Pop(Stack S)
{
    if(!IsSEmpty(S))
        S->TopOfStack--;
}
// Stack implementation over


void InOrderTraversalWithStack(Tree T)
{

    Tree T1 = T;
    Stack S =CreateStack(MAXElement);

    while (T1 || !IsSEmpty(S))
    {
        while(T1)
        {
            Push(T1,S);
            T1 = T1->left;
        }
        if(!IsSEmpty(S))
        {
            T1 = Top(S);
            Pop(S);
            printf("####%d####\n",T1->element);
            T1 = T1->right;
        }
    }
    
}

void PreOrderTraversalWithStack(Tree T)
{
    Tree T1 = T;
    Stack S = CreateStack(MAXElement);

    while(T1 || !IsSEmpty(S))
    {
        while(T1)
        {
            Push(T1,S);
            printf("####%d####\n",T1->element);
            T1 = T1->left;
        }
        if(!IsSEmpty(S))
        {
            T1 = Top(S);
            Pop(S);
            T1 = T1->right;
        }
    }
    
}

void PostOrderTraversalWithStack(Tree T)
{
    Tree T1 = T;
    Tree temp = NULL;
    Stack S = CreateStack(MAXElement);

    while(T1 || !IsSEmpty(S))
    {
        while(T1)
        {
            Push(T1,S);
            T1 = T1->left;
        }
        if(!IsSEmpty(S))
        {
            T1 = Top(S);
            Pop(S);
            if(T1->right == NULL || T1->right == temp)
            {
                printf("####%d####\n",T1->element);
                temp = T1;
                T1 = NULL;
            }
            else
            {
                Push(T1,S);
                T1 = T1->right;
            }
        }
    }
}

//Queue
struct QueueRecord;
typedef struct QueueRecord* Queue;

struct QueueRecord
{
    int Capacity;
    int front;
    int rear;
    ElementType2* Array;
};
int IsQEmpty(Queue Q)
{
    return Q->front == Q->rear;
}

int IsQFull(Queue Q)
{
    return (Q->rear+1)%Q->Capacity == Q->front;
}

Queue CreateQueue(int MaxSize)
{
    Queue Q = malloc(sizeof(struct QueueRecord));
    Q->Array = malloc(sizeof(ElementType2)*(MaxSize));
    Q->front = 0;
    Q->rear = 0;
    Q->Capacity = MaxSize;
    return Q;
}

void EnQueue(ElementType2 X ,Queue Q)
{
    if(!IsQFull(Q))
    {
        Q->Array[Q->rear] = X;
        Q->rear = (Q->rear+1)%Q->Capacity;
    }
        
}

ElementType2 Front(Queue Q)
{
    if(!IsQEmpty(Q))
    {
        return Q->Array[Q->front];
    }
    else{
        printf("This Queue Is Empty!!!!\n");
        return 0;
    }
}

void DeQueue(Queue Q)
{
    if(!IsQEmpty(Q))
    {
        Q->front = (Q->front+1)%Q->Capacity;
    }
}
// Queue implementation over

void LevelOrderTraversal(Tree T)
{
    Queue Q = CreateQueue(MAXElement);
    Tree T1 = NULL;
    EnQueue(T,Q);
    while (!IsQEmpty(Q))
    {
        T1 = Front(Q);
        DeQueue(Q);
        printf("####%d####\n",T1->element);
        if(T1->left) EnQueue(T1->left,Q);
        if(T1->right) EnQueue(T1->right,Q);
    }
    
}

void LevelOrderTraversalWithStack(Tree T)
{
    Tree T1 = NULL;
    Stack S1 = CreateStack(MAXElement);
    Stack S2 = CreateStack(MAXElement);

    Push(T,S1);
    while (!IsSEmpty(S1) || IsSEmpty(S2))
    {
        while (!IsSEmpty(S1))
        {
            Push(Top(S1),S2);
            Pop(S1);
        }
        while(!IsSEmpty(S2))
        {
            T1 = Top(S2);
            Pop(S2);
            printf("####%d####\n",T1->element);
            if(T1->left) Push(T1->left,S1);
            if(T1->right) Push(T1->right,S1);
        }
    }
    
    
}

int main()
{
    Tree T = MakeTree(1);
    InsertLeft(T,2);
    InsertRight(T,3);
    InsertLeft(T->left,4);
    InsertRight(T->left,5);
    InsertRight(T->right,6);

    LevelOrderTraversalWithStack(T);

    return 0;
}