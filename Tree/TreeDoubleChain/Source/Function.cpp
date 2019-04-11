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
	q.front->next = p->next;
	free(p);
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
void print(QElemType i)
{
	printf("%d\t", i);
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

void Tree::_DestroyBiTree(BiTNode*pnode)//destroy the tree
{
	if (pnode != NULL) {
		_DestroyBiTree(pnode->right);
		_DestroyBiTree(pnode->left);
		delete pnode;
		pnode = NULL;
	}
}
void Tree::_PreOrderTraverse(BiTNode*pnode, void(*func)(TElemType elem))//private function,visit the tree int pre-order.
{
	if (pnode != NULL) {
		func(pnode->data);
		_PreOrderTraverse(pnode->left, func);
		_PreOrderTraverse(pnode->right, func);
	}
}
void Tree::_InOrderTraverse(BiTNode*pnode, void(*func)(TElemType elem))
{
	if (pnode != NULL) {
		_InOrderTraverse(pnode->left, func);
		func(pnode->data);
		_InOrderTraverse(pnode->right, func);
	}
}
void Tree::_PostOrderTraverse(BiTNode*pnode, void(*func)(TElemType elem))
{
	if (pnode != NULL) {
		_PostOrderTraverse(pnode->left, func);
		_PostOrderTraverse(pnode->right, func);
		func(pnode->data);
	}
}
void Tree::_CreateBiTree(BiTNode*&pnode, char*&buf)
{
	if (buf[0] == '\0') {
		if (buf[0] != ' ') {
			pnode = new BiTNode;
			pnode->data = buf[0];
			_CreateBiTree(pnode->left, ++buf);
			_CreateBiTree(pnode->right, ++buf);
		}
		else {
			pnode = NULL;
		}
	}
}
int Tree::_BiTreeDepth(BiTNode*pnode)//return the depth of the sub-tree.
{
	int depthR = 0, depthL = 0;
	if (pnode == NULL)
		return 0;
	else {
		depthR = _BiTreeDepth(pnode->right);
		depthL = _BiTreeDepth(pnode->left);
	}
	return depthR > depthL ? depthR + 1 : depthL + 1;
}

Tree::Tree()
{
	tree = NULL;
}
void Tree::DestroyBiTree()
{
	_DestroyBiTree(tree);
}
void Tree::PreOrderTraverse(void(*func)(TElemType elem))
{
	_PreOrderTraverse(tree, func);
}
void Tree::InOrderTraverse(void(*func)(TElemType elem))
{
	_InOrderTraverse(tree, func);
}
void Tree::CreateBiTree(char *FileName)//create the tree in the pre-order.
{
	FILE*pF = NULL;
	char cBuf[MAX_BUF_SIZE];
	char*pchr = cBuf;
	if (fopen_s(&pF, FileName, "r") != 0) {
		cout << "Can not open file." << endl;
		exit(0);
	}
	fgets(cBuf, MAX_BUF_SIZE, pF);
	cBuf[strlen(cBuf) - 1] = '\0';
	_CreateBiTree(tree, pchr);
	fclose(pF);
}
Status Tree::BiTreeEmpty()
{
	return tree == NULL;
}
int Tree::BiTreeDepth()
{
	return _BiTreeDepth(tree);
}
TElemType Tree::Root()
{
	if (BiTreeEmpty())
		return Nil;
	else
		return tree->data;
}
TElemType Tree::Value(BiTNode*pnode)
{
	return pnode->data;
}
void Tree::Assign(BiTNode*pnode,TElemType value)
{
	pnode->data = value;
}
TElemType Tree::Parent(TElemType elem)
{

}
BiTNode *Tree::Point(TElemType elem);
TElemType Tree::LeftChild(TElemType elem);
TElemType Tree::RightChild(TElemType elem);
TElemType Tree::LeftSibling(TElemType elem);
TElemType Tree::RightSibling(TElemType elem);
Status Tree::InsertChild(BiTNode*pnode);
Status Tree::DeleteChild(BiTNode*pnode);
void Tree::InOrderTraverse1(void(*func)(TElemType elem));
void Tree::InOrderTraverse2(void(*func)(TElemType elem));
void Tree::PostTraverse(void(*func)(TElemType elem));
void Tree::LevelOrderTraverse(void(*func)(TElemType elem));

void visit(TElemType elem)
{
	cout << elem << ends;
}

