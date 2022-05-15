#include<stdio.h>
#include<stdlib.h>

#define TRUE 1;
#define FALSE 0;
typedef int ElementType;


struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    ElementType element;
    Position next;
};

List CreateList()
{
    Position ptr =  malloc(sizeof(struct Node));
    ptr->next = NULL;
    return ptr;
}

List MakeEmpty(List L)
{
    Position ptr = L->next;
    Position tmp;
    while(ptr)
    {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
    return L;
}

int IsEmpty(List L)
{
    return L->next == NULL;
}

Position Find(ElementType X,List L)
{
    Position ptr = L->next;
    while (ptr)
    {
        if(ptr->element == X)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void Delete(ElementType X,List L)
{
    Position ptr,tmp;
    ptr = L;
    while (ptr->next)
    {
        if(ptr->next->element == X)
        {
            tmp = ptr->next;
            ptr->next = tmp->next;
            free(tmp);
            return;
        }
        ptr = ptr->next;
    }
}

Position FindPrevious(ElementType X,List L)
{
    Position ptr = L;
    while (ptr->next && ptr->next->element!=X)
    {
        ptr = ptr->next;
    }
    return ptr;
}

void Insert(ElementType X,List L,Position P)
{
    Position ptr = malloc(sizeof(struct Node));
    ptr->element = X;
    ptr->next = P->next;
    P->next = ptr;
}

void DeleteList(List L)
{
    Position ptr = L->next;
    Position tmp;
    while(ptr)
    {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
    free(L);
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    if(L)
        return L->next;
}   

Position Advance(Position P)
{
    if(P)
        return P->next;
}

ElementType Retrieve(Position P)
{
    if(P)
        return P->element;
}
void PrintList(List L)
{
    if(!IsEmpty(L))
    {
        Position P;
        P = L->next;
        while (P != NULL)
        {
            printf("####%d####\n",P->element);
            P = P->next;
        }
        
    }
    else
        printf("LinkList is Empty!!!\n");
    
}

void ShowElement(Position P)
{
    if(P)
        printf("####%d####\n",P->element);
}

int main()
{
    List L1 = CreateList();
    Insert(3,L1,L1);
    Insert(2,L1,L1);
    Insert(1,L1,L1);
    Delete(3,L1);
    PrintList(L1);
    
    return 0;
}