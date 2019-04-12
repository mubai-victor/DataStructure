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

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2
struct SqStack {
	SElemType *base;
	SElemType *top;
	int stacksize;
};
void InitStack(SqStack&S);
void DestroyStack(SqStack&S);
void ClearStack(SqStack&S);
Status StackEmpty(SqStack&S);
int StackLength(SqStack&S);
Status GetTop(SqStack&S, SElemType&selem);
void Push(SqStack&S, SElemType selem);
Status Pop(SqStack&s, SElemType&selem);
void StackTraverse(SqStack&S, void(*func)(SElemType selem));

#define MAX_TREE_SIZE 100
#define ClearBiTree DestroyBiTree

struct position {
	int level;
	int order;
};
struct BiTNode {
	TElemType data;
	BiTNode *right, *left;
};
class Tree {
private:
	BiTNode *tree;
	void _DestroyBiTree(BiTNode*&pnode);
	void _PreOrderTraverse(BiTNode*pnode, void(*func)(TElemType elem));
	void _InOrderTraverse(BiTNode*pnode, void(*func)(TElemType elem));
	void _PostOrderTraverse(BiTNode*pnode, void(*func)(TElemType elem));
	void _CreateBiTree(BiTNode*&pnode, char*&buf);
	int _BiTreeDepth(BiTNode*pnode);
public:
	Tree();
	void DestroyBiTree();
	void PreOrderTraverse(void (*func)(TElemType elem));
	void InOrderTraverse(void (*func)(TElemType elem));
	void CreateBiTree(char *FileName);
	Status BiTreeEmpty();
	int BiTreeDepth();
	TElemType Root();
	TElemType Value(BiTNode*pnode);
	void Assign(BiTNode*pnode, TElemType value);
	TElemType Parent(TElemType elem);
	BiTNode *Point(TElemType elem);
	TElemType LeftChild(TElemType elem);
	TElemType RightChild(TElemType elem);
	TElemType LeftSibling(TElemType elem);
	TElemType RightSibling(TElemType elem);
	Status InsertChild(BiTNode*pchild, int LR, BiTNode*pparent);
	Status DeleteChild(BiTNode*pnode, int LR);
	void InOrderTraverse1(void(*func)(TElemType elem));
	void InOrderTraverse2(void(*func)(TElemType elem));
	void PostOrderTraverse(void(*func)(TElemType elem));
	void LevelOrderTraverse(void(*func)(TElemType elem));
};
void visit(TElemType elem);

#endif