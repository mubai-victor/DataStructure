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

typedef struct QNode {
	QElemType data;
	QNode*next;
}*QueuePtr;
struct LinkQueue {
	QueuePtr rear, front;
};

typedef char InfoType;
typedef char VertexType[MAX_NAME];
enum GraphKind { DG = 1, DN = 2, UDG = 3, UDN = 4 };
typedef struct {
	VRType adj;
	InfoType *info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
class MGraph {
private:
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
	GraphKind kind;
	bool visited[MAX_VERTEX_NUM];
public:
	MGraph();
	int LocateVex(VertexType name);
	void CreateFUDG(char *filename);
	void CreateFUDN(char *filename);
	void CreateDG(char *filename);
	void CreateDN(char *filename);
	void CreateUSG(char *filename);
	void CreateUDN(char *filename);
	Status GetSubString(char *&buf,char *sub);
	void CreateGraph();
	void DestroyGraph();
	VertexType& GetVex(int num);
	Status PutVex(VertexType origin,VertexType newone);
	int FirstAdjVex(VertexType vex);
	int NextAdjVex(VertexType center,VertexType pre);
	void InsertVex(VertexType InsVex);
	Status DeleteVex(VertexType DelVex);
	Status InsertArc(VertexType InsArcTail,VertexType InsArcHead);
	Status DeleteArc(VertexType DelArcTail,VertexType DelArcHead);
	GraphKind GetType();
	void DFS(int FirVex, void(*visit)(VertexType vex));
	void DFSTraverse(void(*visit)(VertexType vex));
	void BFSTraverse(void (*visit)(VertexType vex));
	void Display();
};
void visit(VertexType vex);
void InitQueue(LinkQueue &q);
void EnQueue(LinkQueue &q, QElemType elem);
Status DeQueue(LinkQueue &q, QElemType &elem);
Status QueueEmpty(LinkQueue &q);
#endif