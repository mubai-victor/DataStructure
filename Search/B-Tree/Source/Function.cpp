#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

BTNode::BTNode()
{
	parent = NULL;
	keynum = 0;
	for (int i = 0; i <= m; i++) {
		node[i].ptr = NULL;
		node[i].recptr = NULL;
	}
}

void DSTree::_DestroyDSTree(BTree &T)
{
	if (T != NULL) {
		for (int i = 0; i <= T->keynum; i++) {
			_DestroyDSTree(T->node[i].ptr);
		}
		delete T;
		T = NULL;
	}
}
int DSTree::_Search(BTree T, KeyType key)
{
	int iPos = 0;
	if (T != NULL) {
		for (int i = 1; i <= T->keynum; i++) {
			if (T->node[i].key <= key) {
				iPos = i;
			}
		}
		return iPos;
	}
	return 0;
}
void DSTree::_Insert(BTree &T, int i, Record *r, BTree ap)
{
	int iPos = 0;
	for (iPos = T->keynum; iPos >= i + 1; iPos--) {
		T->node[iPos + 1] = T->node[iPos];
	}
	iPos = i + 1;
	T->node[iPos].recptr = r;
	T->node[iPos].ptr = ap;
	T->node[iPos].key = r->key;
	T->keynum++;
}
void DSTree::_Split(BTree &q, BTree &ap)
{
	int iPos = (q->keynum + 1) / 2;
	ap = new BTNode;
	for (int i = iPos; i <= q->keynum; i++) {
		ap->node[i - iPos] = q->node[i];
		if (q->node[i].ptr != NULL) {
			q->node[i].ptr->parent = ap;
		}
	}
	ap->parent = q->parent;
	ap->keynum = iPos - 1;
	q->keynum -= iPos;
}
void DSTree::_NewRoot(BTree &T, Record *r, BTree ap)
{
	BTree bp = new BTNode;
	bp->node[0].ptr = T;
	T = bp;
	T->node[1].key = r->key;
	T->node[1].ptr = ap;
	T->node[1].recptr = r;
	T->parent = NULL;
	T->keynum = 1;
	if (T->node[0].ptr != NULL) {
		T->node[0].ptr->parent = T;
	}
	if (T->node[1].ptr != NULL) {
		T->node[1].ptr->parent = T;
	}
}
void DSTree::_TraverseDTree(BTree &T, void(*Func)(BTNode elem, int i))
{
	if (T != NULL) {
		_TraverseDTree(T->node[0].ptr, Func);
		for (int i = 1; i <= T->keynum; i++) {
			Func(*T, i);
			_TraverseDTree(T->node[i].ptr, Func);
		}
	}
}

DSTree::DSTree()
{
	root = NULL;
}
DSTree::~DSTree()
{
	if (root != NULL) {
		_DestroyDSTree(root);
	}
}
void DSTree::InsertDSTree(Record *r, BTree q, int i)
{
	int iFinish = FALSE;
	int iPos = 0;
	BTree ap = NULL;
	Result res;
	while (q != NULL&&iFinish == FALSE) {
		_Insert(q, i, r, ap);
		if (q->keynum < m) {
			iFinish = TRUE;
		}
		else {
			iPos = (q->keynum + 1) / 2;
			r = q->node[iPos].recptr;
			_Split(q, ap);
			q = q->parent;
			if (q != NULL) {
				i = _Search(q, r->key);				
			}
		}
	}
	if (iFinish == FALSE) {
		_NewRoot(root, r, ap);
	}
}
void DSTree::TraverseDSTree(void(*Func)(BTNode elem, int i))
{
	if (root != NULL) {
		_TraverseDTree(root, Func);
	}
}
Result DSTree::SearchDSTree(KeyType key)
{
	BTree rParent = NULL, rChild = root;
	Result res;
	int iPos = 0;
	int find = FALSE;
	while (rChild != NULL&&find == FALSE) {
		iPos = _Search(rChild, key);
		if (iPos > 0 && rChild->node[iPos].key == key) {
			find = TRUE;
		}
		else {
			rParent = rChild;
			rChild = rChild->node[iPos].ptr;
		}
	}
	res.i = iPos;
	if (find == TRUE) {
		res.tag = TRUE;
		res.pt = rChild;
	}
	else {
		res.tag = FALSE;
		res.pt = rParent;
	}
	return res;
}



void print(BTNode elem, int i)
{
	cout << "(" << elem.node[i].key << "," << elem.node[i].recptr->others << ")," << endl;
}