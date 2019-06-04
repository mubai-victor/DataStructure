#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

void TrieTrees::_DestroyTrieTree(TrieTree &ptr)
{
	if (ptr->kind == BRANCH) {
		for (int i = 0; i < LENGTH; i++) {
			if (ptr->bh.ptr[i] != NULL) {
				_DestroyTrieTree(ptr->bh.ptr[i]);
				ptr->bh.ptr[i] = NULL;
			}
		}
	}
	delete ptr;
	ptr = NULL;
}
void TrieTrees::_TraverseTrieTree(TrieTree ptr, void(*Func)(Record*rec))
{
	if (ptr->kind == BRANCH) {
		for (int i = 0; i < LENGTH; i++) {
			if (ptr->bh.ptr[i] != NULL) {
				_TraverseTrieTree(ptr->bh.ptr[i], Func);
			}
		}
	}
	else {
		Func(ptr->lf.infoptr);
	}
}
TrieTrees::TrieTrees()
{
	root = NULL;
}
void TrieTrees::DestroyTrieTree()
{
	if (root != NULL) {
		_DestroyTrieTree(root);
	}
}
Record*TrieTrees::SearchTrieTree(KeysType key)
{
	TrieTree child = NULL, parent = NULL;
	child = root;
	for (int i = 0; child != NULL && child->kind == BRANCH&&i < key.num; i++) {
		child = child->bh.ptr[ord(key.ch[i])];
	}
	if (child != NULL&&child->kind == LEAF&&strcmp(child->lf.K.ch, key.ch)==0) {
		return child->lf.infoptr;
	}
	else {
		return NULL;
	}
}
void TrieTrees::InsertTrieTree(Record*rec)
{
	TrieTree tree = NULL, parent = NULL, temp = NULL;;
	if (root == NULL) {
		root = new TrieNode;
		root->kind = BRANCH;
		for (int i = 0; i < LENGTH; i++) {
			root->bh.ptr[i] = NULL;
		}
		tree = new TrieNode;
		tree->kind = LEAF;
		tree->lf.infoptr = rec;
		tree->lf.K = rec->key;
		root->bh.ptr[ord(rec->key.ch[0])] = tree;
	}
	else {
		int i = 0;
		for (tree = root; i < rec->key.num&&tree != NULL&&tree->kind == BRANCH; i++) {
			parent = tree;
			tree = tree->bh.ptr[ord(rec->key.ch[i])];
		}
		i = i - 1;
		if (tree != NULL) {
			int j = i;
			for (; tree->lf.K.ch[j] == rec->key.ch[j]; j++) {
				temp = parent->bh.ptr[ord(rec->key.ch[j])] = new TrieNode;
				temp->kind = BRANCH;
				for (int j = 0; j < LENGTH; j++) {
					temp->bh.ptr[j] = NULL;
				}
				parent = temp;
			}
			parent->bh.ptr[ord(tree->lf.K.ch[j])] = tree;
			temp = new TrieNode;
			temp->kind = LEAF;
			temp->lf.infoptr = rec;
			temp->lf.K = rec->key;
			parent->bh.ptr[ord(rec->key.ch[j])] = temp;
		}
		else {		
			tree = new TrieNode;
			parent->bh.ptr[ord(rec->key.ch[i])] = tree;
			tree->kind = LEAF;
			tree->lf.infoptr = rec;
			tree->lf.K = rec->key;
		}
	}
}
void TrieTrees::TraverseTrieTree(void(*Func)(Record*rec))
{
	if (root != NULL) {
		_TraverseTrieTree(root,Func);
	}
}

void print(Record *r)
{
	cout << '(';
	cout << r->key.ch;
	cout << ',' << r->others.ord << ')' << endl;
}
int ord(char cha)
{
	char temp = tolower(cha);
	if (temp >= 'a'&&temp <= 'z') {
		return temp - 'a' + 1;
	}
	return 0;
}