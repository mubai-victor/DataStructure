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
	if (tree[2 * pos + 1] != Nil)
		_PreTraverse(2 * pos + 1, func);
	if (tree[2 * pos + 2] != Nil)
		_PreTraverse(2 * pos + 2, func);
}
void Tree::_InTraverse(int pos, void(*func)(TElemType elem))
{
	if(tree[2 * pos + 1]!=Nil)
		_InTraverse(2 * pos + 1, func);
	func(tree[pos]);
	if (tree[2 * pos + 2] != Nil)
		_InTraverse(2 * pos + 2, func);
}
void Tree::_PostTraverse(int pos, void(*func)(TElemType elem))
{
	if (tree[2 * pos + 1] != Nil)
		_PostTraverse(2 * pos + 1, func);
	if (tree[2 * pos + 2] != Nil)
		_PostTraverse(2 * pos + 2, func);
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
void Tree::CreateBiTree(char* FileName)
{
	errno_t status = 0;
	FILE*pF = NULL;
	char TEbuf[MAX_TREE_SIZE];
	char*pcur = NULL;
	int length = 0, pos = 0;
	status = fopen_s(&pF, FileName, "r");
	if (status != 0) {
		cout << "无法打开文件。" << endl;
		exit(0);
	}
//	fgets(TEbuf, MAX_TREE_SIZE, pF);
	while (fgets(TEbuf, MAX_TREE_SIZE, pF),!feof(pF)) {
		length = strlen(TEbuf);
		pcur = TEbuf;
		while(1) {
			tree[pos++] = atoi(pcur);
			pcur = strchr(pcur, ' ');
			if (pcur == NULL)
				break;
			pcur = pcur + 1;
		}
	}
	fclose(pF);
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
	if (pos == MAX_TREE_SIZE) {
		return Nil;
	}
	else if (pos * 2 + 2 > MAX_TREE_SIZE) {
		return Nil;
	}
	else {
		return tree[2 * pos + 2];
	}
}
TElemType Tree::LeftSibling(TElemType value)
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
	else if (pos % 2 == 1) {
		return Nil;
	}
	else {
		return tree[pos - 1];
	}
}
TElemType Tree::RightSibling(TElemType value)
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
	else if (pos % 2 == 0 || pos + 1 >= MAX_TREE_SIZE) {
		return Nil;
	}
	else {
		return tree[pos + 1];
	}
}
void Tree::Move(int pos_src, Tree &R, int pos_des)
{
	if (tree[2 * pos_src + 1] != Nil) {
		Move(2 * pos_src + 1, R, 2 * pos_des + 1);
	}
	if (tree[2 * pos_src + 2] != Nil) {
		Move(2 * pos_src + 2, R, 2 * pos_des + 2);
	}
	R.tree[pos_des] = tree[pos_src];
	tree[pos_src] = Nil;
}
void Tree::InsertChild(TElemType elem, int LR, Tree &R)
{
	//初始条件：当前二叉树存在， p是当前二叉树中某个结点的值， LR为0或1，非空二叉树R与当前不相交且右子树为空
	//操作结果:根据LR为0或1,插入R为T中elem结点的左或右子树。 elem结点的原有左或右子树则成为R的右子树
	int pos = 0, insert_pos = 0;
	for (; pos < MAX_TREE_SIZE; pos++) {
		if (tree[pos] == elem)
			break;
	}
	insert_pos = 2 * pos + 1 + LR;
	if(tree[insert_pos]!=Nil)
		Move(insert_pos, R, 2);
	R.Move(0,*this,insert_pos);
}
Status Tree::DeleteChild(position pos, int LR)
{
	int Ipos = int(pow(2, pos.level - 1)) + pos.order - 2;
	Status flag = OK;
	if (tree[Ipos] == Nil) {
		return ERROR;
	}
	else if (tree[2 * Ipos + 1 + LR] == Nil) {
		return OK;
	}
	else {
		LinkQueue Q;
		QElemType Qelem;
		InitQueue(Q);
		Ipos = 2 * Ipos + 1 + LR;
		while (flag == OK) {
			if (tree[2 * Ipos + 1] != Nil) {
				EnQueue(Q, 2 * Ipos + 1);
			}
			if (tree[2 * Ipos + 2] != Nil) {
				EnQueue(Q, 2 * Ipos + 2);
			}
			tree[Ipos] = Nil;
			flag=DeQueue(Q, Ipos);
		}
	}
}
void Tree::PreOrderTraverse(void(*func)(TElemType elem))
{
	if(tree[0]!=Nil)
		_PreTraverse(0, func);
}
void Tree::InOrderTraverse(void(*func)(TElemType elem))
{
	if(tree[0]!=Nil)
		_InTraverse(0, func);
	cout << endl;
}
void Tree::PostOrderTraverse(void(*func)(TElemType elem))
{
	if(tree[0]!=Nil)
		_PostTraverse(0, func);
	cout << endl;
}
void Tree::LevelOrderTraverse(void(*func)(TElemType elem))
{
	int depth = BiTreeDepth();
	for (int i = 0; i<int(pow(2, depth)) - 1; i++) {
		if (tree[i] != Nil) {
			func(tree[i]);
		}
	}
	cout << endl;
}
void Tree::Print()
{
	int depth = BiTreeDepth();
	position pos;
	TElemType elem;
	for (int i = 1; i <= depth; i++) {
		for (int j = 1; j <= int(pow(2, i - 1)); j++) {
			pos.level=i;
			pos.order=j;
			elem=Value(pos);
			if (elem != Nil) {
				cout<<elem<<ends;
			}
		}
		cout<<endl;
	}
}

void visit(TElemType elem)
{
	cout << elem << ends;
}

