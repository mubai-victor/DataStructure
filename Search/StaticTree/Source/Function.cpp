#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

BiTree::BiTree()
{
	lchild = rchild = NULL;
}

Status SOSTree::SecondOptimal(ElemType R[])
{
	_SecondOptimal(root, R, 1, N);
	return OK;
}

SOSTree::SOSTree()
{
	root = NULL;
}
Status SOSTree::_SecondOptimal(BiTree *&T, ElemType R[], int low, int high)
{
	int iMin = sw[high] - sw[low], iDw = sw[low - 1] + sw[high];
	int iLow = low;
	for (int i = low + 1; i <= high; i++) {
		if (iMin > abs(iDw - sw[i] - sw[i - 1])) {
			iMin = abs(iDw - sw[i] - sw[i - 1]);
			iLow = i;
		}
	}
	T = new BiTree;
	T->data = R[iLow - 1];
	if (iLow == low) {
		T->lchild = NULL;
	}
	else {
		_SecondOptimal(T->lchild, R, low, iLow - 1);
	}
	if (iLow == high) {
		T->rchild = NULL;
	}
	else {
		_SecondOptimal(T->rchild, R, iLow + 1, high);
	}
	return OK;
}
void SOSTree::_Traverse(BiTree *elem, void(*Func)(ElemType elem))
{
	if (elem->lchild != NULL) {
		_Traverse(elem->lchild,Func);
	}
	Func(elem->data);
	if (elem->rchild != NULL) {
		_Traverse(elem->rchild, Func);
	}
}

void SOSTree::Traverse(void(*Func)(ElemType elem))
{
	if (root != NULL) {
		_Traverse(root, Func);
	}
}
void SOSTree::FindSW(ElemType R[])
{
	sw[0] = 0;
	for (int i = 1; i <= N; i++) {
		sw[i] = sw[i - 1] + R[i - 1].weight;
	}
}
void SOSTree::CreateSOSTree(ElemType R[])
{
	FindSW(R);
	SecondOptimal(R);
}
Status SOSTree::Search_SOSTree(KeyType key)
{
	BiTree *pTree = root;
	while (pTree != NULL) {
		if (pTree->data.key == key) {
			cout << "The weight of the node:" << pTree->data.weight << endl;
			return OK;
		}
		else if (pTree->data.key < key) {
			pTree = pTree->rchild;
		}
		else {
			pTree = pTree->lchild;
		}
	}
	return ERROR;
}
void print(ElemType elem)
{
	cout << "Key:" << elem.key << " Weight:" << elem.weight << endl;
}