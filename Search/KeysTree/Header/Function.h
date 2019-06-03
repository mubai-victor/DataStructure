#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
#define LISTINCREMENT 5
#define LISTLENGTH 10

#define MAX_KEY_LEN 16
#define N 16

#define LINERLIST_CHAIN

class DLTNode;

struct SElem {
	char ch;
	DLTNode* p;
};

typedef SElem SElemType;
typedef SElem Elemtype;



#ifdef LINERLIST_CHAIN
typedef  Elemtype SElemType;
struct LNode{
	Elemtype data;
	LNode*next;
};

typedef LNode*LinkList;
typedef struct LNode LNode;
#define LinkStack LinkList

void InitList(LinkList&L);
void DestroyList(LinkList&L);
void ClearList(LinkList&L);
Status ListEmpty(LinkList L);
//Status GetElem(LinkList L,int i,Elemtype &elem);
Status ListInsert(LinkList&L,int i,Elemtype elem);
Status ListDelete(LinkList&L,int i,Elemtype &elem);
int LocateElem(LinkList L,Elemtype elem,Status(*compare)(Elemtype a,Elemtype b));
int ListLength(LinkList L);


#define InitStack InitList
#define DestroyStack DestroyList
#define ClearStack ClearList
#define StackEmpty ListEmpty
#define StackLength ListLength

void Push(LinkStack s, SElemType selem);
Status Pop(LinkStack s, SElemType&selem);

#endif

struct Others {
	int ord;
};

struct KeysType {
	char ch[MAX_KEY_LEN];
	int num;
};

struct Record {
	KeysType key;
	Others others;
};

enum NodeKind{LEAF,BRANCH};

typedef struct DLTNode {
	char symbol;
	DLTNode *next;
	NodeKind kind;
	union {
		Record *infoptr;
		DLTNode *first;
	};
	DLTNode();
}DLTNode,*DLTree;


class KeysTree {
private:
	DLTree root;
	void _DestroyTree(DLTNode *&ptr);
public:
	KeysTree();
	~KeysTree();
	Record* SearchDLTree(KeysType key);
	void InsertDLTree(Record *r);
	void TraverseDLTree(void (*Func)(Record r));
};

void print(Record r);

#endif