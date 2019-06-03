#include "stdafx.h"
#include "Function.h"
#include "Test.h"
//Testing Function**************************************************************
// func2-3.cpp 几个常用的函数


using namespace std;

#ifdef LINERLIST_CHAIN
void InitList(LinkList&L){
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)
		exit(OVERFLOW);
	L->next=NULL;
}
void DestroyList(LinkList&L)
{
	LinkList p_front=L,p_rear;
	while(!p_front){
		p_rear=p_front->next;
		free(p_front);
		p_front=p_rear;
		p_rear=p_front->next;
	}
	L=NULL;
}
void ClearList(LinkList&L)
{
	LinkList p_front=L->next,p_rear;
	while(!p_front){
		p_rear=p_front->next;
		free(p_front);
		p_front=p_rear;
		p_rear=p_front->next;
	}	
	L->next=NULL;
}



Status ListEmpty(LinkList L)
{
	if(!L->next)
		return TRUE;
	else
		return FALSE;
}

Status ListInsert(LinkList&L, int i, Elemtype elem)
{
	LinkList p_front,p_rear=L;
	int count=1;
	while(p_rear&&count<i){
		p_rear = p_rear->next;
		count++;
	}
	if(!p_rear||count>i)
		return ERROR;
	p_front=(LinkList)malloc(sizeof(LNode));
	p_front->data=elem;
	p_front->next=p_rear->next;
	p_rear->next=p_front;
	return OK;
}
Status ListDelete(LinkList&L, int i, Elemtype &elem)
{
	LinkList p = L, p_temp;
	int count = 1;
	while (p->next&&count<i){
		p = p -> next;
		count++;
	}
	if (!p->next || count>i)
		return ERROR;
	elem = p->next->data;
	p_temp = p->next;
	p->next= p->next->next;
	free(p_temp);
	return OK;
}

int LocateElem(LinkList L, Elemtype elem, Status(*compare)(Elemtype a, Elemtype b))
{
	int count = 1;
	LinkList p = L->next;
	while (p){
		if (compare(elem, p->data))
			return count;
		count++;
		p = p->next;
	}
	return 0;
}
int ListLength(LinkList L)
{
	int count = 0;
	LinkList p = L;
	while (p->next){
		count++;
		p = p->next;
	}
	return count;
}

void Push(LinkStack s, SElemType selem)
{
	ListInsert(s, 1, selem);
}

Status Pop(LinkStack s, SElemType&selem)
{
	return ListDelete(s, 1, selem);
}

DLTNode::DLTNode()
{
	next = NULL;
	first = NULL;
}

void KeysTree::_DestroyTree(DLTNode *&ptr)
{
	if (ptr->kind == BRANCH&&ptr->first != NULL) {
		_DestroyTree(ptr->first);//下探
	}
	if (ptr->next != NULL) {
		_DestroyTree(ptr->next);//向右寻找。
	}
	delete ptr;
	ptr = NULL;
}
KeysTree::KeysTree()
{
	root = NULL;
}
KeysTree::~KeysTree()
{
	if (root != NULL) {
		_DestroyTree(root);
	}
}
Record* KeysTree::SearchDLTree(KeysType key)
{
	DLTree parent = NULL, child = NULL;
	if (root != NULL) {
		parent = child = root;
		int i = 0;
		while (child != NULL&&i < key.num) {
			while (child != NULL&&child->symbol < key.ch[i]) {
				parent = child;
				child = child->next;
			}
			if (child != NULL&&child->symbol == key.ch[i]) {
				parent = child;
				child = child->first;
				i++;
			}
			else {
				return NULL;
			}
		}
		if (child != NULL) {
			return child->infoptr;
		}
	}
	return NULL;
}
void KeysTree::InsertDLTree(Record *r)
{
	DLTree parent = NULL, child = NULL, temp = NULL;
	if (root == NULL) {
		parent = new DLTNode;
		root = parent;
		for (int i = 0; i < r->key.num; i++) {
			parent->symbol = r->key.ch[i];
			parent->kind = BRANCH;
			parent->next = NULL;
			child = new DLTNode;
			parent->first = child;
			parent = child;
		}
		child->next = NULL;
		child->kind = LEAF;
		child->infoptr = r;
		child->symbol = ' ';
	}
	else {
		int i = 0;
		child = parent = root;
		while (child != NULL&&i < r->key.num) {
			while (child != NULL&&child->symbol < r->key.ch[i]) {
				parent = child;
				child = child->next;
			}
			if (child != NULL&&child->symbol == r->key.ch[i]) {
				parent = child;
				child = child->first;
				i++;
			}
			else {
				break;
			}
		}
		temp = new DLTNode;
		if (parent->first == child) {			
			parent->first = temp;
		}
		else {
			parent->next = temp;
		}
		temp->next = child;
		child = temp;
		for (; i < r->key.num; i++) {
			child->kind = BRANCH;
			child->symbol = r->key.ch[i];
			parent = child;
			child = new DLTNode;	
			child->next = NULL;
			parent->first = child;			
		}
		child->kind = LEAF;
		child->infoptr = r;
		child->symbol = ' ';
	}
}
void KeysTree::TraverseDLTree(void(*Func)(Record r))
{
	LinkStack S;
	SElem elem;
	DLTree child = NULL;
	child = root;
	InitStack(S);
	if (child != NULL) {
		while (child->kind == BRANCH) {
			elem.ch = child->symbol;
			elem.p = child;
			Push(S, elem);
			child = child->first;
		}
		elem.ch = child->symbol;
		elem.p = child;
		Push(S, elem);
		Func(*child->infoptr);
		while (StackEmpty(S) != TRUE) {
			Pop(S, elem);
			child = elem.p;
			if (child ->next != NULL) {
				child = child->next;
				while (child->kind == BRANCH) {
					elem.p = child;
					elem.ch = child->symbol;
					Push(S, elem);
					child = child->first;
				}
				elem.ch = child->symbol;
				elem.p = child;
				Push(S, elem);
				Func(*child->infoptr);
			}
		}
	}
}

void print(Record r)
{
	cout << '(';
	for (int i = 0; i < r.key.num; i++) {
		cout << r.key.ch[i];
	}
	cout << ',' << r.others.ord << ')' << endl;
}
#endif