#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

struct Node
{
    ElementType element;
    PtrToNode next;
};

int IsEmpty(Stack S)
{
    return S->next == NULL;
}

Stack CreateStack(void)
{
    PtrToNode ptr = malloc(sizeof(struct Node));
    ptr->next = NULL;
    return ptr;
}

void Push(ElementType X,Stack S)
{
    PtrToNode ptr = malloc(sizeof(struct Node));
    ptr->element = X;
    ptr->next = S->next;
    S->next = ptr;
}

ElementType Top(Stack S)
{
    if(S->next)
        return S->next->element;
}

void Pop(Stack S)
{   if(S->next)
    {
        PtrToNode tmp = S->next;
        S ->next = S->next->next;
        free(tmp);
    } 
}

void DisPoseStack(Stack S)
{
    while(!IsEmpty(S))
        Pop(S);
    free(S);
}

void MakeEmpty(Stack S)
{
    while(!IsEmpty(S))
    {
        Pop(S);
    }
}

int main()
{
    Stack S1 = CreateStack();
    Push(2,S1);
    Push(3,S1);
    Pop(S1);
    printf("####%d####\n",Top(S1));
}
