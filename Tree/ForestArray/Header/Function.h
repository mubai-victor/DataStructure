#ifndef _FUNCTION_
#define _FUNCTION_DestroyQueue
#include "Test.h"

#define ClearTree InitTree
#define DestroyTree InitTree

#define MAX_TREE_SIZE 100
#define MAX_BUF_SIZE 100
#define KEEP 0
#define DELETED 1

typedef struct QNode {
	QElemType data;
	QNode*next;
}*QueuePtr;
struct LinkQueue {
	QueuePtr rear, front;
};
void print(QElemType i);
void InitQueue(LinkQueue &q);
void DestroyQueue(LinkQueue &q);
void ClearQueue(LinkQueue &q);
Status QueueEmpty(LinkQueue &q);
int QueueLength(LinkQueue q);
Status GetHead(LinkQueue q, QElemType &elem);
void EnQueue(LinkQueue &q, QElemType elem);
Status DeQueue(LinkQueue &q,QElemType &elem);
void QueueTraverse(LinkQueue q, void(*func)(QElemType elem));

class PTNode {
public:
	TElemType data;
	int parent;
	PTNode();
};

class PTree {
private:
	PTNode nodes[MAX_TREE_SIZE + 1];
	Status deleted[MAX_TREE_SIZE + 1];
	int num;
public:
	PTree();
	void InitTree();
	void CreateTree(char*pcFileName);
	Status TreeEmpty();
	int TreeDepth();
	TElemType Root();
	Status Assign(TElemType origin_elem,TElemType new_elem);
	TElemType Value(int pos);
	TElemType Parent(TElemType elem);
	TElemType LeftChild(TElemType elem);
	TElemType RightSibling(TElemType elem);
	void Print();
	Status InsertChild(TElemType elem,int i,PTree T);
	void DeleteChild(TElemType elem,int i);
	void TraverseTree(void (*func)(TElemType elem));
};
void visit(TElemType elem);

#endif