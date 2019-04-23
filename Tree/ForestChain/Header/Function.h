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

#define ClearTree DestroyTree;

class Node {
public:
	TElemType data;
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
	void PreOrderTraverse(void (*func)(TElemType elem));
	void InitTree();
	void DestroyTree();
	void CreateTree(char*FileName);
	Status TreeEmpty();
	int TreeDepth();
	TElemType Value(Node*node);
	TElemType Root();
	Node* Point(TElemType elem);
	Status Assign(TElemType OriginElem, TElemType CurElem);
	TElemType LeftChild(TElemType elem);
	TElemType Parent(TElemType elem);
	TElemType RightSibling(TElemType elem);
	Status InsertChild(Node*node,int i,CSTree T);
	Status DeleteChild(Node*node,int i);
	void PostOrderTraverse(void (*func)(TElemType elem));
	void LevelOrderTraverse(void (*func)(TElemType elem));
};
void visit(TElemType elem);

#endif