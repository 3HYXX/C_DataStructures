#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;

struct StackRecord;
typedef struct StackRecord* Stack;

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType* Array;
};

int IsEmpty(Stack S)
{
    return S->TopOfStack == -1;
}

int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity-1;
}

Stack CreateStack(int MaxElements)
{
    Stack S = malloc(sizeof(struct StackRecord));
    S->Array = malloc(sizeof(ElementType)*MaxElements);
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

void Push(ElementType X,Stack S)
{
    if(!IsFull(S))
    {
        S->Array[++S->TopOfStack] = X;
    }
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    else
    {
        printf("This Stack Is Empty!!!!\n");
        return 0;
    }
}

void Pop(Stack S)
{
    if(!IsEmpty(S))
        S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
    if(!IsEmpty(S))
    {
        return S->Array[S->TopOfStack--];
    }
    else
    {
        printf("This Stack Is Empty!!!!\n");
        return 0;
    }
}

int main()
{
    Stack S1 = CreateStack(10);
    Push(4,S1);
    Push(5,S1);
    //Pop(S1);
    MakeEmpty(S1);
    Push(7,S1);


    printf("%d\n",TopAndPop(S1));
    printf("%d\n",Top(S1));
}