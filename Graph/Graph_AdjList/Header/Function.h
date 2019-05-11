#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
//#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 26
#define MAX_NAME 20
#define MAX_INFO 20
#define MAX_BUF_SIZE 100

#define VISITED 1
#define UNVISITED 0

#define FILEUDN "UDN.txt"
#define FILEUDG "UDG.txt"
#define FILEDG	"DG.txt"
#define FILEDN	"DN.txt"

typedef int VRType;
typedef int QElemType;
typedef int InfoType;
typedef char VertexType[MAX_NAME];
enum GraphKind { DG = 1, DN = 2, UDG = 3, UDN = 4 };

struct ElemType {
	int adjvax;
	InfoType *info;
	ElemType();
};

struct ArcNode {
	ElemType data;
	ArcNode *nextarc;
	ArcNode();
};

typedef struct VexNode{
	VertexType data;
	ArcNode *firstarc;
	VexNode();
}VNode, AdjList[MAX_VERTEX_NUM];


class cALGraph {
private:
	AdjList vexs;
	int vexnum, arcnum;
	GraphKind kind;
	bool visited[MAX_VERTEX_NUM];
public:
	cALGraph();
	int LocateVex(VertexType vex);
	void CreateGraph();
	void DestroyGraph();
	VertexType&GetVex(int i);
	Status PutVex(VertexType origin, VertexType newone);
	int FirstAdjVex(VertexType vex);
	int NextAdjVex(VertexType center, VertexType pre);
	void InsertVex(VertexType vex);
	Status DeleteVex(VertexType vex);
	Status InsertArc(VertexType head, VertexType tail);
	Status DeleteArc(VertexType head, VertexType tail);
	GraphKind GetKind();
	void DFS(void(*visit)(VertexType elem), int vex);
	void DFSTraverse(void(*visit)(VertexType elem));
	void BFSTreaverse(void(*visit)(VertexType elem));
	void DFS1(void(*visit)(VertexType elem), int vex);
	void DFSTraverse1(void(*visit)(VertexType elem));
	void BFSTreverse1(void(*visit)(VertexType elem));
	void Display();
};

Status equalvex(ElemType elem1, ElemType elem2);
void visit(VertexType vex);
Status GetSubStr(char *sub, char *&str);

#define LNode ArcNode
#define next nextarc
typedef ArcNode *LinkList;

typedef struct QNode {
	QElemType data;
	QNode*next;
}*QueuePtr;
struct LinkQueue {
	QueuePtr rear, front;
};



void InitList(LinkList&L);
void ClearList(LinkList&L);
int ListLength(LinkList L);
int LocateElem(LinkList L, ElemType elem, Status(*compare)(ElemType elem_a, ElemType elem_b));
Status GetElem(LinkList L, int i, ElemType&elem);
Status ListInsert(LinkList&L, int i, ElemType elem);
Status ListDelete(LinkList&L, int i, ElemType &elem);
Status ListEmpty(LinkList L);
Status DeleteElem(LinkList&L, ElemType&elem, Status(*equal)(ElemType elem_a, ElemType elem_b));
LinkList Point(LinkList L, ElemType elem, Status(*equal)(ElemType elem_a, ElemType elem_b), LinkList&p);

void visit(VertexType vex);
void InitQueue(LinkQueue &q);
void EnQueue(LinkQueue &q, QElemType elem);
Status DeQueue(LinkQueue &q, QElemType &elem);
Status QueueEmpty(LinkQueue &q);
#endif