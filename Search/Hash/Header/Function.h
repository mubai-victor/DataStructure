#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1

#define N 10
#define NULL_KEY 0

static int hashsize[4] = { 11,19,29,37 };

typedef int KeyType;
struct ElemType {
	KeyType key;
	int ord;
};

class HashTable {
private:
	ElemType *elem;
	int count;
	int sizeindex;
	int size;
public:
	HashTable();
	void InitHashTable();
	void DestroyHashTable();
	unsigned Hash(KeyType key);
	void Collision(int &pos,int i);
	Status SearchHash(KeyType key, int &pos, int &times);
	Status InsertHash(ElemType elem);
	void RecreateHash();
	void TraverseHash(void(*Func)(int pos, ElemType *elem));
	Status Find(KeyType key,int &pos);
	void Print(int pos);
};

void print(int pos, ElemType *elem);

#endif