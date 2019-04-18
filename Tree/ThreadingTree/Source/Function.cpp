#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

BiThrNode::BiThrNode()
{
	right = left = NULL;
	Rtag = Ltag = Link;
	data = Nil;
}


void BiThrTree::_CreateBiThrTree(BiThrNode *&pnode,char *&pbuf)
{//Create the BiThrTree with the buf of string 'pbuf', and the pnode is the root,private function.
	if (*pbuf != '\0') {
		if (*pbuf != Nil) {
			pnode = new BiThrNode;
			pnode->data = *pbuf;
			_CreateBiThrTree(pnode->left,++pbuf);
			_CreateBiThrTree(pnode->right, ++pbuf);		
		}
		else {
			pnode = NULL;
		}
	}
	else {
		pnode = NULL;
	}

}
void BiThrTree::_InThreading(BiThrNode *pnode)
{//Threading the tree in in-order,private function.
	if (pnode) {
		_InThreading(pnode->left);
		if (pre->right == NULL) {
			pre->right = pnode;
			pre->Rtag = Thread;
		}
		if (pnode->left == NULL) {
			pnode->left = pre;
			pnode->Ltag = Thread;
		}
		pre = pnode;
		_InThreading(pnode->right);
	}
}
void BiThrTree::_PreThreading(BiThrNode *pnode)
{//Threading the tree in pre-order,private function.
	if (pnode->left == NULL) {
		pnode->left = pre;
		pnode->Ltag = Thread;
	}
	if (pre->right == NULL) {
		pre->right = pnode;
		pre->Rtag = Thread;
	}
	pre = pnode;
	if (pnode->Ltag == Link) {
		_PreThreading(pnode->left);
	}
	if (pnode->Rtag == Link &&pnode->right != NULL) {
		_PreThreading(pnode->right);
	}
}
void BiThrTree::_PostThreading(BiThrNode *pnode)
{//Threading the tree in post-order,private function.
	if (pnode != NULL) {
		_PostThreading(pnode->left);
		_PostThreading(pnode->right);
		if (pre->right == NULL) {
			pre->right = pnode;
			pre->Rtag = Thread;
		}
		if (pnode->left == NULL) {
			pnode->left = pre;
			pnode->Ltag = Thread;
		}
		pre = pnode;
	}
}
void BiThrTree::_DestroyBiTree(BiThrNode *&pnode)
{//Destroy Tree,private function.
	if (pnode != NULL) {
		if (pnode->Rtag == Link) {
			_DestroyBiTree(pnode->right);
		}
		if (pnode->Ltag == Link) {
			_DestroyBiTree(pnode->left);
		}
		delete pnode;
		pnode = NULL;
	}
}
BiThrTree::BiThrTree()
{//Construct function.
	pre = tree = NULL;
}
void BiThrTree::CreateBiThrTree(char *FileName)
{//Create the Tree,'FileName' is the file with the element of the tree.
	FILE *pF = NULL;
	char carrBuf[MAX_LINE_LEN];
	char *pcBuf = carrBuf;
	errno_t status = fopen_s(&pF, FileName, "r");
	if (status!=0) {
		cout << "Can not open file." << endl;
	}
	fgets(carrBuf, MAX_LINE_LEN, pF);
	fclose(pF);
	_CreateBiThrTree(tree,pcBuf);
}
void BiThrTree::InOrderThreading(BiThrTree T)
{//Threading the tree in in-order,T is the origin tree.
	tree = new BiThrNode;
	tree->Ltag = Link;
	tree->Rtag = Thread;
	tree->right = tree;
	if (T.tree == NULL) {
		tree->left = tree;
	}
	else {
		tree->left = T.tree;
		pre = tree;
		_InThreading(T.tree);
		tree->right = pre;
		pre->right = tree;
		pre->Rtag = Thread;
	}
}
void BiThrTree::InOrderTraverse_Thr(void(*func)(TElemType))
{//Traversa the Threaded tree which is in in-order.
	if (tree->left != tree) {
		BiThrNode *pnode = tree->left;
		while (pnode!=tree) {
			while (pnode->Ltag == Link) {
				pnode = pnode->left;
			}
			func(pnode->data);
			while (pnode->Rtag == Thread&&pnode->right != tree) {
				pnode = pnode->right;
				func(pnode->data);			
			}
			pnode = pnode->right;
		}
	}
}
void BiThrTree::PreOrderThreading(BiThrTree T)
{//Threading the tree in pre-order,T is the origin tree.
	tree = new BiThrNode;
	tree->right = tree;
	tree->Rtag = Thread;
	tree->Ltag = Link;
	if (T.tree == NULL) {
		tree->left = tree;
	}
	else {
		tree->left = T.tree; 
		pre = tree;
		_PreThreading(T.tree);
		pre->right = tree;
		pre->Rtag = Thread;
		tree->right = pre;
	}
}
void BiThrTree::PreOrderTraverse_Thr(void(*func)(TElemType))
{//Traversa the threaded tree which is in pre-order.
	if (tree->left != tree) {
		BiThrNode *pnode = tree->left;
		while (pnode != tree) {
			func(pnode->data);
			if (pnode->Ltag == Link) {
				pnode = pnode->left;
			}
			else {
				pnode = pnode->right;
			}
		}
	}
}
void BiThrTree::PostOrderThreading(BiThrTree T)
{//Threading the tree in post-order,T is the origin tree.
	tree = new BiThrNode;
	tree->Ltag = Link;
	tree->Rtag = Thread;
	tree->right = tree;
	if (T.tree == NULL) {
		tree->left = tree;
	}
	else {
		tree->left = T.tree;
		pre = tree;
		_PostThreading(T.tree);
		tree->right = T.tree;
		if (pre->right == NULL) {
			pre->right = tree;
			pre->Rtag = Thread;
		}
	}
}
void BiThrTree::DestroyBiThrTree()
{//Destroy the Threaded tree.
	_DestroyBiTree(tree->left);
	delete tree;
	tree = NULL;
}

void visit(TElemType elem)
{
	cout << elem << ends;
}