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

typedef struct QNode {
	QElemType data;
	QNode*next;
}*QueuePtr;
struct LinkQueue {
	QueuePtr rear, front;
};

typedef char InfoType;
typedef char VertexType[MAX_NAME];
enum GraphKind { DG = 1, DN = 2, UDG = 3, UDN = 4 };

void InitList(LinkList&L);
void ClearList(LinkList&L);
int ListLength(LinkList L);
int LocateElem(LinkList L, Elemtype elem, Status(*compare)(Elemtype elem_a, Elemtype elem_b));
Status GetElem(LinkList L, int i, Elemtype&elem);
Status ListInsert(LinkList&L, int i, Elemtype elem);
Status ListDelete(LinkList L, int i, Elemtype &elem);
Status ListEmpty(LinkList L);
Status DeleteElem(LinkList&L, Elemtype&elem, Status(*equal)(Elemtype elem_a, Elemtype elem_b));
LinkList Point(LinkList L, Elemtype elem, Status(*equal)(Elemtype elem_a, Elemtype elem_b), LinkList&p);

void visit(VertexType vex);
void InitQueue(LinkQueue &q);
void EnQueue(LinkQueue &q, QElemType elem);
Status DeQueue(LinkQueue &q, QElemType &elem);
Status QueueEmpty(LinkQueue &q);
#endif