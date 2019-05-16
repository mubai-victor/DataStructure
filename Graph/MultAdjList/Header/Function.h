#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
//#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 26
#define MAX_NAME 20
#define MAX_INFO 20
#define MAX_BUF_SIZE 100

typedef int VRType;
typedef int QElemType;
typedef int InfoType;
typedef char VertexType[MAX_NAME];
enum VisitIf { UNVISITED, VISITED };
struct EBox {
	VisitIf mark;
	int ivex, jvex;
	EBox *ilink, *jlink;
	InfoType *info;
	EBox();
};
struct VexBox {
	VertexType data;
	EBox *firstedge;
	VexBox();
};
class AMLGraph {
private:
	VisitIf mark[MAX_VERTEX_NUM];
	VexBox vexs[MAX_VERTEX_NUM];
	int vexnum, arcnum;
public:
	AMLGraph();
	int LocateVex(VertexType vex);
	void CreateGraph(char*file);
	VertexType& GetVex(int pos);
	Status PutVex(VertexType origin, VertexType value);
	int FirstAdjVex(VertexType vex);
	int NextAdjVex(VertexType center,VertexType next);
	Status DeleteArc(VertexType vex1, VertexType vex2);
	Status DeleteVex(VertexType vex);
	void DestroyGraph();
	Status InsertVex(VertexType vex);
	Status InsertArc(VertexType vex1,VertexType vex2);
	void DFS(int pos,void (*func)(VertexType));
	void DFSTraverse(void (*func)(VertexType));
	void BFSTraverse(void (*func)(VertexType));
	void MarkUnvisited();
	void Display();
};

void visit(VertexType vex);
Status GetSubStr(char *sub, char *&str);

typedef struct QNode {
	QElemType data;
	QNode*next;
}*QueuePtr;
struct LinkQueue {
	QueuePtr rear, front;
};

void visit(VertexType vex);
void InitQueue(LinkQueue &q);
void EnQueue(LinkQueue &q, QElemType elem);
Status DeQueue(LinkQueue &q, QElemType &elem);
Status QueueEmpty(LinkQueue &q);
#endif