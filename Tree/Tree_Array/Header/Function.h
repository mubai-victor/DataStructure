#ifndef _FUNCTION_
#define _FUNCTION_DestroyQueue
#include "Test.h"

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

#define MAX_TREE_SIZE 100
#define ClearBiTree InitBiTree
#define DestroyBiTree InitBiTree
typedef TElemType SqBiTree[MAX_TREE_SIZE];

struct position {
	int level;
	int order;
};

class Tree {
private:
	SqBiTree tree;
	void _PreTraverse(int pos,void (*func)(TElemType elem));
	void _InTraverse(int pos, void(*func)(TElemType elem));
	void _PostTraverse(int pos, void(*func)(TElemType elem));
public:
	Tree();
	void InitBiTree();
	void CreateBiTree(char* FileName);
	Status BiTreeEmpty();
	int BiTreeDepth();
	Status Root(TElemType &elem);
	TElemType Value(position pos);
	Status Assign(position pos, TElemType value);
	TElemType Parent(TElemType value);
	TElemType LeftChild(TElemType value);
	TElemType RightChild(TElemType value);
	TElemType LeftSibling(TElemType value);
	TElemType RightSibling(TElemType value);
	void Move(int pos_src, Tree &R, int pos_des);
	void InsertChild(TElemType elem, int LR, Tree &R);
	Status DeleteChild(position pos, int LR);
	void PreOrderTraverse(void(*func)(TElemType elem));
	void InOrderTraverse(void(*func)(TElemType elem));
	void PostOrderTraverse(void(*func)(TElemType elem));
	void LevelOrderTraverse(void(*func)(TElemType elem));
	void Print();
};
void visit(TElemType elem);

#endif