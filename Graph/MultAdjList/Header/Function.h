#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
//#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 26
#define MAX_NAME 20
#define MAX_INFO 20
#define MAX_BUF_SIZE 100

#define VISITED 1
#define UNVISITED 0

#define FILEUDN "UDN.txt"
#define FILEUDG "UDG.txt"
#define FILEDG	"DG.txt"
#define FILEDN	"DN.txt"

typedef int VRType;
typedef int QElemType;
typedef int InfoType;
typedef char VertexType[MAX_NAME];
enum GraphKind { DG = 1, DN = 2, UDG = 3, UDN = 4 };


Status equalvex(ElemType elem1, ElemType elem2);
void visit(VertexType vex);
Status GetSubStr(char *sub, char *&str);

#define LNode ArcBox
#define next tail
typedef ArcBox *LinkList;

typedef struct QNode {
	QElemType data;
	QNode*next;
}*QueuePtr;
struct LinkQueue {
	QueuePtr rear, front;
};



void InitList(LinkList&L);
void ClearList(LinkList&L);
int ListLength(LinkList L);
int LocateElem(LinkList L, ElemType elem, Status(*compare)(ElemType elem_a, ElemType elem_b));
Status GetElem(LinkList L, int i, ElemType&elem);
Status ListInsert(LinkList&L, int i, ElemType elem);
Status ListDelete(LinkList&L, int i, ElemType &elem);
Status ListEmpty(LinkList L);
Status DeleteElem(LinkList&L, ElemType&elem, Status(*equal)(ElemType elem_a, ElemType elem_b));
LinkList Point(LinkList L, ElemType elem, Status(*equal)(ElemType elem_a, ElemType elem_b), LinkList&p);

void visit(VertexType vex);
void InitQueue(LinkQueue &q);
void EnQueue(LinkQueue &q, QElemType elem);
Status DeQueue(LinkQueue &q, QElemType &elem);
Status QueueEmpty(LinkQueue &q);
#endif