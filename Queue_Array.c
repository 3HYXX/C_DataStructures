#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;

struct QueueRecord;
typedef struct QueueRecord* Queue;

struct QueueRecord
{
    int Capacity;
    int front;
    int rear;
    ElementType* Array;
};

int IsEmpty(Queue Q)
{
    return Q->front == Q->rear;
}

int IsFull(Queue Q)
{
    return (Q->rear+1)%Q->Capacity == Q->front;
}

Queue CreateQueue(int MaxSize)
{
    Queue Q = malloc(sizeof(struct QueueRecord));
    Q->Array = malloc(sizeof(ElementType)*(MaxSize));
    Q->front = 0;
    Q->rear = 0;
    Q->Capacity = MaxSize;
    return Q;
}

void EnQueue(ElementType X ,Queue Q)
{
    if(!IsFull(Q))
    {
        Q->Array[Q->rear] = X;
        Q->rear = (Q->rear+1)%Q->Capacity;
    }
        
}

ElementType Front(Queue Q)
{
    if(!IsEmpty(Q))
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
    if(!IsEmpty(Q))
    {
        Q->front = (Q->front+1)%Q->Capacity;
    }
}

int main()
{
    Queue Q1 = CreateQueue(10);
    EnQueue(3,Q1);
    EnQueue(2,Q1);
    //DeQueue(Q1);

    printf("%d\n",Front(Q1));
}