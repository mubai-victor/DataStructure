#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

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

//This is the private function of class Tree.
void Tree::_PreTraverse(int pos, void(*func)(TElemType elem))
{
	func(tree[pos]);
	_PreTraverse(2 * pos + 1, func);
	_PreTraverse(2 * pos + 2, func);
}
void Tree::_InTraverse(int pos, void(*func)(TElemType elem))
{
	_PreTraverse(2 * pos + 1, func);
	func(tree[pos]);
	_PreTraverse(2 * pos + 2, func);
}
void Tree::_PostTraverse(int pos, void(*func)(TElemType elem))
{
	_PreTraverse(2 * pos + 1, func);
	_PreTraverse(2 * pos + 2, func);
	func(tree[pos]);
}

//This is the public function of class Tree.
Tree::Tree()
{
	InitBiTree();
}
void Tree::InitBiTree()
{
	for (int i = 0; i < MAX_TREE_SIZE; i++)
		tree[i] = Nil;
}
void Tree::CreateBiTree()
{
	errno_t status = 0;
	FILE*pF = NULL;
	TElemType TEbuf[MAX_TREE_SIZE];
	int length = 0, pos = 0;
	status = fopen_s(&pF, "Tree_Array.txt", "w");
	if (status != 0) {
		cout << "无法打开文件。" << endl;
		exit(0);
	}
	while (fgets(TEbuf, MAX_TREE_SIZE, pF) != NULL) {
		length = strlen(TEbuf);
		for (int i = 0; i < length - 1; i++) {
			tree[pos++] = TEbuf[i];
		}
	}
	pos--;
}
Status Tree::BiTreeEmpty()
{
	return (tree[0] == Nil);
}
int Tree::BiTreeDepth()
{
	int Idepth = 0, Icount = MAX_TREE_SIZE - 1;
	while (tree[Icount] == Nil && Icount >= 0) {
		Icount--;
	}
	Icount++;
	while (Icount>=pow(2,Idepth)) {
		Idepth++;
	}
	return Idepth;
}
Status Tree::Root(TElemType &elem)
{
	if (tree[0] == Nil)
		return ERROR;
	else {
		elem = tree[0];
		return OK;
	}
}
TElemType Tree::Value(position pos)
{
	return tree[int(pow(2, pos.level - 1)) + pos.order - 2];
}
Status Tree::Assign(position pos, TElemType value)
{
	int Ipos = int(pow(2, pos.level - 1)) + pos.order - 2;
	if (tree[(Ipos + 1) / 2] == Nil && value != Nil) {//双亲为空，给子节点赋值不为空。
		return ERROR;
	}
	else if ((tree[2 * Ipos + 1] != Nil || tree[2 * Ipos + 2] != Nil) && value == Nil) {//子节点不为空，但是给双亲赋值为空。
		return ERROR;
	}
	else {
		tree[Ipos] = value;
		return OK;
	}
}
TElemType Tree::Parent(TElemType value)
{
	int pos = 0;
	if (BiTreeEmpty())
		return Nil;
	for (; pos < MAX_TREE_SIZE; pos++) {
		if (tree[pos] == value)
			break;
	}
	if (pos == MAX_TREE_SIZE)
		return Nil;
	else {
		return tree[(pos + 1) / 2 - 1];
	}
}
TElemType Tree::LeftChild(TElemType value)
{
	if (BiTreeEmpty()) {
		return Nil;
	}
	int pos = 0;
	for (; pos < MAX_TREE_SIZE; pos++) {
		if (tree[pos] == value)
			break;
	}
	if (pos == MAX_TREE_SIZE) {
		return Nil;
	}
	else if (2 * pos + 1 >= MAX_TREE_SIZE) {
		return Nil;
	}
	else {
		return tree[pos * 2 + 1];
	}
}
TElemType Tree::RightChild(TElemType value)
{
	if (BiTreeEmpty()) {
		return Nil;
	}
	int pos = 0;
	for (; pos < MAX_TREE_SIZE; pos++) {
		if (tree[pos] == value)
			break;
	}

}
TElemType Tree::LeftSibling(TElemType value);
TElemType Tree::RightSibling(TElemType value);
void Tree::Move(int pos_src, Tree &R, int pos_des);
void Tree::InsertChild(TElemType elem, int LR, Tree &R);
Status Tree::DeleteChild(int pos, int LR);
void Tree::PreOrderTraverse(void(*func)(TElemType elem));
void Tree::InOrderTraverse(void(*func)(TElemType elem));
void Tree::PostTraverse(void(*func)(TElemType elem));
void Tree::LevelOrderTraverse(void(*func)(TElemType elem));
void Tree::Print();

