#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"


//#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 26
#define MAX_NAME 20
#define MAX_INFO 20
#define MAX_BUF_SIZE 100

typedef int VRType;

typedef int InfoType;
typedef char VertexType[MAX_NAME];
typedef VertexType TElemType;
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
class CSTree;
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
	int NextAdjVex(VertexType center, VertexType next);
	Status DeleteArc(VertexType vex1, VertexType vex2);
	Status DeleteVex(VertexType vex);
	void DestroyGraph();
	Status InsertVex(VertexType vex);
	Status InsertArc(VertexType vex1, VertexType vex2);
	void DFS(int pos, void(*func)(VertexType));
	void DFSTraverse(void(*func)(VertexType));
	void BFSTraverse(void(*func)(VertexType));
	void MarkUnvisited();
	void Display();
	friend class CSTree;
};

void visit(VertexType vex);
Status GetSubStr(char *sub, char *&str);


#define ClearTree DestroyTree;

struct Node {
	VertexType data;
	Node*firstchild, *nextsibling;
	Node();
};
class CSTree {
private:
	Node*tree;
	void _PreOrderTraverse(Node*node,void (*func)(TElemType elem));
	void _DestroyTree(Node*&node);
	int _TreeDepth(Node*node);
	void _PostOrderTraverse(Node*node,void (*func)(TElemType elem));
public:
	CSTree();
	void DFSForest(AMLGraph &graph);
	void DFSTree(AMLGraph &graph, int i, Node *pTree);
	void PreOrderTraverse(void (*func)(TElemType elem));
	void InitTree();
	void DestroyTree();
	void CreateTree(char*FileName);
	Status TreeEmpty();
	int TreeDepth();
	Status Assign(TElemType OriginElem, TElemType CurElem);
	Status InsertChild(Node*node,int i,CSTree T);
	Status DeleteChild(Node*node,int i);
	void PostOrderTraverse(void (*func)(TElemType elem));
	void LevelOrderTraverse(void (*func)(TElemType elem));
};
void visit(TElemType elem);

#endif