#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Queue;

struct Node
{
    ElementType element;
    PtrToNode next;
    PtrToNode rear;
};

int IsEmpty(Queue Q)
{
    return Q->next == NULL;
}

Queue CreateQueue()
{
    Queue Q = malloc(sizeof(struct Node));
    Q->next = NULL;
    Q->rear = Q;
}

void EnQueue(ElementType X,Queue Q)
{
    PtrToNode ptr = malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->element = X;
    Q->rear->next = ptr;
    Q->rear = ptr;
}

ElementType Front(Queue Q)
{
    if(!IsEmpty(Q))
    {
        return Q->next->element;
    }
    else
    {
        printf("This Queue Is Empty!!!\n");
        return 0;
    }
}

void DeQueue(Queue Q)
{
    if(!IsEmpty(Q))
    {
        PtrToNode tmp = Q->next;
        Q->next = tmp->next;
        free(tmp);
    }
    else
        printf("This Queue Is Empty!!!\n");
}

int main()
{
    Queue Q1 = CreateQueue();
    EnQueue(3,Q1);
    EnQueue(2,Q1);
    DeQueue(Q1);

    printf("%d\n",Front(Q1));
}