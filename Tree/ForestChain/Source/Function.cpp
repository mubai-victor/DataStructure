#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;
#define MAX_BUF_SIZE 100

void InitQueue(LinkQueue &q)
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (q.front == NULL)
		exit(1);
	q.front->next = NULL;
}
void DestroyQueue(LinkQueue &q)
{
	while (q.rear) {
		q.rear = q.front->next;
		free(q.front);
		q.front = q.rear;
	}
	q.rear = q.front = NULL;
}
void ClearQueue(LinkQueue &q)
{
	QueuePtr first, last;
	last = q.front->next;
	q.rear = q.front;
	q.front->next = NULL;
	while (last) {
		first = last;		
		last = last->next;	
		free(first);	
	} 
}
Status QueueEmpty(LinkQueue &q)
{
	if (!q.front->next)
		return TRUE;
	else
		return FALSE;
}
int QueueLength(LinkQueue q)
{
	QueuePtr p = q.front->next;
	int count = 0;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}
Status GetHead(LinkQueue q, QElemType &elem)
{
	if (QueueEmpty(q)) {
		return ERROR;
	}
	elem = q.front->next->data;
	return OK;
}
void EnQueue(LinkQueue &q, QElemType elem)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(-1);
	p->data = elem;
	p->next = q.rear->next;
	q.rear->next = p;
	q.rear = p;
}
Status DeQueue(LinkQueue &q, QElemType &elem) {
	if (QueueEmpty(q))
		return ERROR;
	QueuePtr p = q.front->next;
	elem = p->data;
	if (q.front->next == q.rear) {
		q.rear = q.front;
		q.front->next = NULL;
	}
	else {
		q.front->next = p->next;
	}
	free(p);
	p = NULL;
	return OK;
}
void QueueTraverse(LinkQueue q, void(*func)(QElemType elem))
{
	QueuePtr p = q.front->next;
	while (p) {
		func(p->data);
		p = p->next;
	}
}

void InitStack(SqStack&S)
{
	S.base = (SElemType*)(malloc(sizeof(SElemType)*STACK_INIT_SIZE));
	if (!S.base)
		exit(1);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
void DestroyStack(SqStack&S)
{
	free(S.base);
	S.base = S.top = NULL;
	S.stacksize = 0;
}
void ClearStack(SqStack&S)
{
	S.top = S.base;
}
Status StackEmpty(SqStack&S)
{
	return (S.base == S.top);
}
int StackLength(SqStack&S)
{
	return (S.top - S.base);
}
Status GetTop(SqStack&S, SElemType&selem)
{
	if (S.top == S.base)
		return ERROR;
	selem = *(S.top - 1);
	return OK;
}
void Push(SqStack&S, SElemType selem)
{
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType*)(realloc(S.base, sizeof(SElemType)*(S.stacksize + STACK_INCREMENT)));
		if (!S.base)
			exit(1);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*S.top = selem;
	S.top++;
}
Status Pop(SqStack&S, SElemType&selem)
{
	if (S.base == S.top)
		return ERROR;
	else {
		selem = *(--S.top);
		return OK;
	}
}
void StackTraverse(SqStack&S, void(*func)(SElemType selem))
{
	SElemType*cur;
	cur = S.base;
	while (S.top > cur) {
		func(*cur++);
	}
	printf("\n");
}

Node::Node()
{
	data = Nil;
	firstchild = NULL;
	nextsibling = NULL;
}


void CSTree::_PreOrderTraverse(Node*node, void(*func)(TElemType elem))
{
	func(node->data);
	if (node->firstchild != NULL) {
		_PreOrderTraverse(node->firstchild,func);
	}
	if (node->nextsibling) {
		_PreOrderTraverse(node->nextsibling,func);
	}
}
void CSTree::_DestroyTree(Node*&node)
{
	if (node != NULL) {
		if (node->firstchild != NULL) {
			_DestroyTree(node->firstchild);
		}
		if (node->nextsibling != NULL) {
			_DestroyTree(node->nextsibling);
		}
		free(node);
		node = NULL;
	}
}
int CSTree::_TreeDepth(Node*node)
{
	if (node != NULL) {
		int iDepth = 0, iMax = 1;
		if (node->firstchild == NULL) {
			return 1;
		}
		else {
			node = node->firstchild;
			while (node != NULL) {
				iDepth = _TreeDepth(node);
				if (iDepth > iMax) {
					iMax = iDepth;
				}
				node = node->nextsibling;
			}
		}
		return iMax + 1;
	}
	return 0;
}
void CSTree::_PostOrderTraverse(Node*node, void(*func)(TElemType elem))
{
	if (node != NULL) {
		_PostOrderTraverse(node->firstchild, func);
		func(node->data);
		_PostOrderTraverse(node->nextsibling, func);

	}
}
CSTree::CSTree()
{
	tree = NULL;
}
void CSTree::PreOrderTraverse(void(*func)(TElemType elem))
{
	if (!TreeEmpty()) {
		_PreOrderTraverse(tree,func);
	}
}
void CSTree::InitTree()
{
	tree = NULL;
}
void CSTree::DestroyTree()
{
	_DestroyTree(tree);
}
void CSTree::CreateTree(char*FileName)
{
	FILE*pF = NULL;
	char arrcBuf[MAX_BUF_SIZE], *pcBuf = NULL;
	Node*pNChild = NULL;
	if (fopen_s(&pF, FileName, "r") != 0) {
		cout << "Can not open file." << endl;
		exit(0);
	}
	LinkQueue Q;
	InitQueue(Q);
	if (fgets(arrcBuf, MAX_BUF_SIZE,pF)) {
		tree = new Node;
		tree->data = arrcBuf[0];
		EnQueue(Q,tree);
	}
	while (fgets(arrcBuf, MAX_BUF_SIZE, pF)) {
		pcBuf = arrcBuf;
		while (pcBuf[0] != '\n' && !QueueEmpty(Q)) {
			DeQueue(Q,pNChild);
			if (pcBuf[0] != ' ') {
				pNChild->firstchild = new Node;
				pNChild->firstchild->data = pcBuf[0];
				EnQueue(Q, pNChild->firstchild);
				pcBuf++;
				pNChild = pNChild->firstchild;
			}		
			while (pcBuf[0] != Nil&&pcBuf[0] != '\n') {
				pNChild->nextsibling = new Node;
				EnQueue(Q,pNChild->nextsibling);
				pNChild->nextsibling->data = pcBuf[0];
				pNChild = pNChild->nextsibling;
				pcBuf++;
			}
			if (pcBuf[0] == Nil) {
				pcBuf++;
				if (pcBuf[0] == Nil&&(pcBuf - arrcBuf) % 2 == 1) {
					pcBuf++;
				}
			}
		}
	}
}
Status CSTree::TreeEmpty()
{
	if (tree == NULL) {
		return TRUE;
	}
	else {
		return ERROR;
	}
}
int CSTree::TreeDepth()
{
	return _TreeDepth(tree);
}
TElemType CSTree::Value(Node*node)
{
	return node->data;
}
TElemType CSTree::Root()
{
	if (!TreeEmpty()) {
		return tree->data;
	}
	else {
		return Nil;
	}
}
Node* CSTree::Point(TElemType elem)
{
	if (!TreeEmpty()) {
		LinkQueue Q;
		Node*pnode = NULL;
		InitQueue(Q);
		EnQueue(Q, tree);
		while (!QueueEmpty(Q)) {
			DeQueue(Q, pnode);
			if (pnode->data == elem) {
				return pnode;
			}
			if (pnode->firstchild != NULL) {
				EnQueue(Q, pnode->firstchild);
				pnode = pnode->firstchild;
			}
			while (pnode->nextsibling != NULL) {
				EnQueue(Q, pnode->nextsibling);
				pnode = pnode->nextsibling;
			}
		}
	}
	return NULL;
}
Status CSTree::Assign(TElemType OriginElem, TElemType CurElem)
{
	Node*pnode = NULL;
	pnode = Point(OriginElem);
	if (pnode != NULL) {
		pnode->data = CurElem;
		return OK;
	}
	else {
		return ERROR;
	}
}
TElemType CSTree::LeftChild(TElemType elem)
{
	Node *pnode = NULL;
	pnode = Point(elem);
	if (pnode != NULL&&pnode->firstchild != NULL) {
		return pnode->firstchild->data;
	}
	else {
		return Nil;
	}
}
TElemType CSTree::Parent(TElemType elem)
{
	if (!TreeEmpty()) {
		LinkQueue Q;
		Node*pnode = NULL, *pparent = NULL;
		InitQueue(Q);
		EnQueue(Q,tree);
		while (!QueueEmpty(Q)) {
			DeQueue(Q,pparent);
			pnode = pparent->firstchild;
			while (pnode != NULL) {
				if (pnode->data == elem) {
					return pparent->data;
				}
				else {
					EnQueue(Q, pnode);
				}
				pnode = pnode->nextsibling;
			}
		}
	}
	return Nil;
}
TElemType CSTree::RightSibling(TElemType elem)
{
	Node*pnode = NULL;
	pnode = Point(elem);
	if (pnode != NULL&&pnode->nextsibling != NULL) {
		return pnode->nextsibling->data;
	}
	else {
		return Nil;
	}
}
Status CSTree::InsertChild(Node*node, int i, CSTree T)
{
	if (!T.TreeEmpty()) {
		Node*pnode = NULL;
		if (i == 1) {
			T.tree->nextsibling = node->firstchild;
			node->firstchild = T.tree;
			return OK;
		}
		else {
			int j = 2;
			pnode = tree->firstchild;
			for (; pnode!=NULL&&pnode->nextsibling != NULL&&j < i; j++) {
				pnode = pnode->nextsibling;
			}
			if (i == j) {
				T.tree->nextsibling = pnode->nextsibling;
				pnode->nextsibling = T.tree;
			}
		}
	}
	return ERROR;
}
Status CSTree::DeleteChild(Node*node, int i)
{
	if (node != NULL&&node->firstchild != NULL) {
		Node*pnode = node->firstchild;
		if (i == 1) {
			node->firstchild = pnode->nextsibling;
			pnode->nextsibling = NULL;
			_DestroyTree(pnode);
			return OK;
		}
		else {
			for (int j = 2; j < i&&pnode->nextsibling != NULL; j++) {
				pnode = pnode->nextsibling;
			}
			if (pnode->nextsibling != NULL) {
				pnode->nextsibling = pnode->nextsibling->nextsibling;
				pnode->nextsibling->nextsibling = NULL;
				_DestroyTree(pnode->nextsibling);
				return OK;
			}
		}
	}
	return ERROR;
}
void CSTree::PostOrderTraverse(void(*func)(TElemType elem))
{
	_PostOrderTraverse(tree, func);
}
void CSTree::LevelOrderTraverse(void(*func)(TElemType elem))
{
	if (!TreeEmpty()) {
		LinkQueue Q;
		Node*pnode = NULL;
		InitQueue(Q);
		EnQueue(Q, tree);
		while (!QueueEmpty(Q)) {
			DeQueue(Q, pnode);
			func(pnode->data);
			if (pnode->firstchild != NULL) {
				EnQueue(Q, pnode->firstchild);
				pnode = pnode->firstchild;
				while (pnode->nextsibling != NULL) {
					EnQueue(Q, pnode->nextsibling);
					pnode = pnode->nextsibling;
				}
			}
		}
	}
}

void visit(TElemType elem)
{
	cout << elem << ends;
}

