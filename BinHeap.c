#include<stdio.h>
#include<stdlib.h>

#define MAXDATA 1000
#define True 1
#define False 0

typedef int ElementType;

struct HeapStruct;

typedef struct HeapStruct* Heap;
typedef Heap MaxHeap;
typedef Heap Min Heap;

struct HeapStruct
{
    ElementType *Data;
    int Size;
    int Capacity;
};

MaxHeap CreatHeap(int Maxsize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Data = (ElementType *)malloc((Maxsize+1)*sizeof(ElementType));
    H->Capacity = Maxsize;
    H->Size = 0;
    H->Data[0] = MAXDATA;

    return H;
}

int IsFull(MaxHeap H)
{
    return(H->Size == H->Capacity);
}

int IsEmpty(MaxHeap H)
{
    return (H->Size == 0);
}

int Insert(MaxHeap H, ElementType X)
{
    int i;
    if(IsFull(H))
    {
        printf("最大堆已满\n");
        return False;
    }
    
    i = ++(H->Size);
    for(;H->Data[i/2] < X; i/=2)
        H->Data[i] = H->Data[i/2];
    H->Data[i] = X;
    return True;
}

ElementType DeleteMax(MaxHeap H)
{
    int Parent, Child; 
    ElementType MaxItem, X;
    if(IsEmpty(H))
    {
        printf("最大堆已空\n");
        return False;
    }
    MaxItem = H->Data[1];
    X = H->Data[H->Size--];//提末尾节点到有一个
    for(Parent = 1; Parent*2 < H->Size; Parent = Child)//找出末尾节点应该在的位置
    {
        Child = Parent*2;
        if( (Child != H->Size) && (H->Data[Child] < H->Data[Child+1]))
            Child++;
        if(X >= H->Data[Child])
            break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;

    return MaxItem;
}
