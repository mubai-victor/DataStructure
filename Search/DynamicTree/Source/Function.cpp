#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

Tree::Tree()
{
	lchild = rchild = NULL;
}

BiTree BSTree::_SearchBST(BiTree T, KeyType key)
{
	if (T == NULL) {
		return NULL;
	}
	else if (T->data.key == key) {
		return T;
	}
	else if (T->data.key < key) {
		return _SearchBST(T->rchild, key);
	}
	else {
		return _SearchBST(T->lchild, key);
	}
}
Status BSTree::_SearchBST(BiTree T, KeyType key, BiTree f, BiTree &b)
{
	if (T == NULL) {
		b = f;
		return ERROR;
	}
	else if (T->data.key == key) {
		b = T;
		return OK;
	}
	else if (T->data.key < key) {
		return _SearchBST(T->rchild, key, T, b);
	}
	else {
		return _SearchBST(T->lchild, key, T, b);
	}
}
Status BSTree::_DeleteBST(BiTree &T, KeyType key)
{
	if (T == NULL) {
		return ERROR;
	}
	else if (T->data.key == key) {
		Delete(T);
		return OK;
	}
	else if (T->data.key < key) {
		return _DeleteBST(T->rchild, key);
	}
	else {
		return _DeleteBST(T->lchild, key);
	}
}
void  BSTree::_TraverseBSTree(BiTree p,void(*Func)(ElemType elem))
{
	if (p != NULL) {
		_TraverseBSTree(p->lchild, Func);
		Func(p->data);
		_TraverseBSTree(p->rchild, Func);
	}
}
void  BSTree::_DestroyBSTree(BiTree p)
{
	if (p != NULL) {
		_DestroyBSTree(p->lchild);
		_DestroyBSTree(p->rchild);
		delete p;
		p = NULL;
	}
}

BSTree::BSTree()
{
	root = NULL;
}
BSTree::~BSTree()
{
	if (root != NULL) {
		_DestroyBSTree(root->lchild);
		_DestroyBSTree(root->rchild);
		delete root;
		root = NULL;
	}
}
void BSTree::TraverseBSTree(void(*Func)(ElemType elem))
{
	if (root != NULL) {
		_TraverseBSTree(root, Func);
	}
}
BiTree BSTree::SearchBST(KeyType key)
{
	if (root != NULL) {
		return _SearchBST(root, key);
	}
	return NULL;
}
Status BSTree::SearchBST(KeyType key, BiTree f, BiTree &b)
{
	if (root != NULL) {
		return _SearchBST(root, key, f, b);
	}
	else {
		b = f;
		return ERROR;
	}
}
Status BSTree::InsertBST(ElemType elem)
{
	BiTree BParent = NULL, BPoint = NULL;
	if (_SearchBST(root, elem.key, NULL, BPoint) != OK) {
		if (BPoint == NULL) {
			root = new Tree;
			root->data = elem;
		}
		else {
			if (BPoint->data.key < elem.key) {
				BPoint->rchild = new Tree;
				BPoint->rchild->data = elem;
				BPoint->rchild->lchild = BPoint->rchild->rchild = NULL;
			}
			else {
				BPoint->lchild = new Tree;
				BPoint->lchild->data = elem;
				BPoint->lchild->lchild = BPoint->lchild->rchild = NULL;
			}
		}
		return OK;
	}
	else {
		return ERROR;
	}
}
void BSTree::Delete(BiTree &p)
{
	BiTree BChild = NULL, BSwap = NULL;
	if (p->lchild == NULL) {
		BChild = p;
		p = p->rchild;
		delete BChild;
		BChild = NULL;
	}
	else if (p->rchild == NULL) {
		BChild = p;
		p = p->lchild;
		delete BChild;
		BChild = NULL;
	}
	else {
		BChild = p;
		BSwap = BChild->lchild;
		while (BSwap->rchild != NULL) {
			BChild = BSwap;
			BSwap = BSwap->rchild;
		}
		if (BChild == p) {
			p->data = BSwap->data;
			p->lchild = BSwap->lchild;
		}
		else {
			p->data = BSwap->data;
			BChild->rchild = BSwap->lchild;
		}
		delete BSwap;
		BSwap = NULL;
	}
	
}
Status BSTree::DeleteBST(KeyType key)
{
	if (root != NULL) {
		return _DeleteBST(root, key);
	}
	return ERROR;
}

void print(ElemType elem)
{
	cout << "(" << elem.key << "," << elem.others << ")" << endl;
}