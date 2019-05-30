#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

Tree::Tree()
{
	lchild = rchild = NULL;
}

void BalanceTree::_R_Rotate(BiTree &T)
{
	BiTree BChild = T->lchild;
	T->lchild = BChild->rchild;
	BChild->rchild = T;
	T = BChild;
}
void BalanceTree::_L_Rotate(BiTree &T)
{
	BiTree BChild = T->rchild;
	T->rchild = BChild->lchild;
	BChild->lchild = T;
	T = BChild;
}
void BalanceTree::_LeftBalance(BiTree &T)
{
	BiTree BChild = T->lchild, BTemp = NULL;
	switch (BChild->bf) {
	case LH:
		BChild->bf = EH;
		T->bf = EH;
		_R_Rotate(T);
		break;
	case RH:
		BTemp = BChild->rchild;
		switch (BTemp->bf) {
		case RH:
			T->bf = EH;
			BChild->bf = LH;
			break;
		case EH:
			BChild->bf = T->bf = EH;
			break;
		case LH:
			T->bf = RH;
			BChild->bf = EH;
		}
		BTemp->bf = EH;
		_L_Rotate(T->lchild);
		_R_Rotate(T);
	}
}
void BalanceTree::_RightBalance(BiTree &T)
{
	BiTree BChild = T->rchild, BTemp = NULL;
	switch (BChild->bf) {
	case RH:
		T->bf = BChild->bf = EH;
		_L_Rotate(T);
		break;
	case LH:
		BTemp = BChild->lchild;
		switch (BTemp->bf)
		{
		case RH:
			T->bf = LH;
			BChild->bf = EH;
			break;
		case LH:
			T->bf = EH;
			BChild->bf = RH;
			break;
		case EH:
			T->bf = BChild->bf = EH;
		}
		BTemp->bf = EH;
		_R_Rotate(T->rchild);
		_L_Rotate(T);
	}
}
void BalanceTree::_DestroyBST(BiTree &T)
{
	if (T != NULL) {
		_DestroyBST(T->lchild);
		_DestroyBST(T->rchild);
		delete T;
		T = NULL;
	}
}
void BalanceTree::_Traverse(BiTree &T, void(*Func)(ElemType elem))
{
	if (T != NULL) {
		_Traverse(T->lchild, Func);
		Func(T->data);
		_Traverse(T->rchild, Func);
	}
}
Status BalanceTree::_InsertAVL(BiTree &T, ElemType elem, Status &taller)
{
	if (T == NULL) {
		T = new Tree;
		T->data = elem;
		T->lchild = T->rchild = NULL;
		T->bf = EH;
		taller = TRUE;
	}
	else {
		if (T->data.key == elem.key) {
			taller = FALSE;
			return ERROR;
		}
		else if (T->data.key < elem.key) {
			if (_InsertAVL(T->rchild, elem, taller) != ERROR) {
				if (taller == TRUE) {
					switch (T->bf) {
					case EH:
						T->bf = RH;
						taller = TRUE;
						break;
					case RH:
						_RightBalance(T);
						taller = FALSE;
						break;
					case LH:
						T->bf = EH;
						taller = FALSE;
					}
				}
				return OK;
			}
			else {
				taller = FALSE;
				return ERROR;
			}
		}
		else {
			if (_InsertAVL(T->lchild, elem, taller) != ERROR) {
				if (taller == TRUE) {
					switch (T->bf) {
					case EH:
						T->bf = LH;
						taller = TRUE;
						break;
					case RH:
						T->bf = EH;
						taller = FALSE;
						break;
					case LH:
						_LeftBalance(T);
						taller = FALSE;
					}
				}
				return OK;
			}
			taller = FALSE;
			return ERROR;
		}
	}
}
BiTree BalanceTree::_SearchBST(BiTree &T, KeyType key)
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

BalanceTree::BalanceTree()
{
	root = NULL;
}
BalanceTree::~BalanceTree()
{
	if (root != NULL) {
		_DestroyBST(root);
	}
}
Status BalanceTree::InsertAVL(ElemType elem)
{
	Status STaller;
	return _InsertAVL(root, elem, STaller);
}
void BalanceTree::TraverseBST(void(*Func)(ElemType elem))
{
	if (root != NULL) {
		_Traverse(root, Func);
	}
}
BiTree BalanceTree::SearchBST(KeyType key)
{
	if (root != NULL) {
		return _SearchBST(root, key);
	}
	else {
		return NULL;
	}
}

void print(ElemType elem)
{
	cout << "(" << elem.key << "," << elem.others << ")," << endl;
}