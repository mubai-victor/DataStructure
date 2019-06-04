#include "stdafx.h"
#include "Function.h"
#include "Test.h"
//Testing Function**************************************************************
// func2-3.cpp 几个常用的函数


using namespace std;

HashTable::HashTable()
{
	elem = NULL;
	count = 0;
	sizeindex = 0;
	size = 0;
}

void HashTable::InitHashTable()
{
	size = hashsize[0];
	elem = new ElemType[size];
	for (int i = 0; i < size; i++) {
		elem[i].key = NULL_KEY;
	}
}

void HashTable::DestroyHashTable()
{
	delete[] elem;
	elem = NULL;
	count = 0;
	sizeindex = 0;
	size = 0;
}

unsigned HashTable::Hash(KeyType key)
{
	return key%size;
}

void HashTable::Collision(int & pos, int i)
{
	pos = (pos + i) % size;
}

Status HashTable::SearchHash(KeyType key, int & pos, int &times)
{
	times = 0;
	pos = Hash(key);
	while (key != elem[pos].key&&elem[pos].key != NULL_KEY) {
		times++;
		if (times < size) {
			Collision(pos, times);
		}
		else {
			break;
		}
	}
	if (elem[pos].key == key) {
		return SUCCESS;
	}
	else {
		return UNSUCCESS;
	}
}

Status HashTable::InsertHash(ElemType key)
{
	int pos = 0;
	int times = 0;
	if (SearchHash(key.key, pos, times) == SUCCESS) {
		return DUPLICATE;
	}
	else if (times < size / 2) {
		elem[pos] = key;
		count++;
		return SUCCESS;
	}
	else {
		RecreateHash();
		return UNSUCCESS;
	}
}

void HashTable::RecreateHash()
{

	ElemType *pElem = new ElemType[size];
	for (int i = 0; i < size; i++) {
		pElem[i] = elem[i];
	}
	delete[] elem;
	size = hashsize[++sizeindex];
	elem = new ElemType[size];
	for (int i = 0; i < size; i++) {
		elem[i].key = NULL_KEY;
	}
	count = 0;
	for (int i = 0; i < hashsize[sizeindex - 1]; i++) {
		if (pElem[i].key != NULL_KEY) {
			InsertHash(pElem[i]);
		}			
	}
	delete[] pElem;
	pElem = NULL;
}

void HashTable::TraverseHash(void(*Func)(int pos, ElemType *elem))
{
	for (int i = 0; i < size; i++) {
		if (elem[i].key != NULL_KEY) {
			Func(i,elem + i);
		}
	}
}

Status HashTable::Find(KeyType key, int & pos)
{
	int times = 0;
	pos = Hash(key);
	while (elem[pos].key != key&&elem[pos].key != NULL_KEY) {
		times++;
		if (times < size) {
			Collision(pos, times);
		}
		else {
			return UNSUCCESS;
		}
	}
	if (elem[pos].key == key) {
		return SUCCESS;
	}
	else {
		return UNSUCCESS;
	}
}

void HashTable::Print(int pos)
{
	cout << "Address=" << pos << " (" << elem[pos].key << "," << elem[pos].ord << ")" << endl;
}

void print(int pos, ElemType *elem)
{
	cout << "Address=" << pos << " (" << elem->key << "," << elem->ord << ")" << endl;
}