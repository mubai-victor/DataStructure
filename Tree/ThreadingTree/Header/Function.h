#ifndef _FUNCTION_
#include "Test.h"

#define MAX_LINE_LEN 50
#define Nil ' '
typedef char TElemType;
enum PointerTag {
	Link,Thread
};
struct BiThrNode {
	BiThrNode *right, *left;
	PointerTag Ltag, Rtag;
	TElemType data;
	BiThrNode();
};
class BiThrTree {
private:
	BiThrNode *tree;
	BiThrNode *pre;
	void _CreateBiThrTree(BiThrNode *&pnode, char *&pbuf);
	void _InThreading(BiThrNode *pnode);
	void _PreThreading(BiThrNode *pnode);
	void _PostThreading(BiThrNode *pnode);
	void _DestroyBiTree(BiThrNode *&pnode);
public:
	BiThrTree();
	void CreateBiThrTree(char *FileName);
	void InOrderThreading(BiThrTree T);
	void InOrderTraverse_Thr(void (*func)(TElemType));
	void PreOrderThreading(BiThrTree T);
	void PreOrderTraverse_Thr(void (*func)(TElemType));
	void PostOrderThreading(BiThrTree T);
	void DestroyBiThrTree();
};
void visit(TElemType elem);

#endif