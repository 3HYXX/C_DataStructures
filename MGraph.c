#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 10
typedef int WeightType;
typedef int Vertex;

typedef struct ENode* PtrToENode;
struct ENode
{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode* PtrToGNode;
struct GNode
{
    int Nv;//顶点数
    int Ne;//边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    //DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph CreateGraph(int VertexNum)
{
    Vertex V,W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for(V=0;V<Graph->Nv;V++)
        for(W = 0;W<Graph->Nv;W++)
            Graph->G[V][W] = 0; //或INFINITY
}

void InsertEdge(MGraph Graph, Edge E)
{
    //插入边V1 V2
    Graph->G[E->V1][E->V2] = E->Weight;

    //若为无向图
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;

    scanf("%d",&Nv);
    Graph = CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if(Graph->Ne!=0)
    {
        E = (Edge)malloc(sizeof(struct ENode));
        for (i = 0; i < Graph->Ne; i++)
        {
            scanf("%d %d %d", &E->V1,&E->V2,&E->Weight);;
            InsertEdge(Graph,E);
        }
    }
    /*如果顶点有数据 读入数据
    for(V = 0;V<Graph->Nv; V++)
        scanf("%c",&(Graph->Data[V]));
    */
   return Graph;
}

int main()
{
    return 0;
}