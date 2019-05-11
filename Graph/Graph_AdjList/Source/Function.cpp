#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;
//Function of struct ElemType*****************************************
ElemType::ElemType()
{
	adjvax = 0;
	info = NULL;
}
//Function of struct ArcNode******************************************
ArcNode::ArcNode()
{
	nextarc = NULL;
}
//Function of struct VexNode******************************************
VexNode::VexNode()
{
	InitList(firstarc);
}
//Function of class cALGraph******************************************
cALGraph::cALGraph()
{
	vexnum = arcnum = 0;
	for (int i = 0; i < MAX_VERTEX_NUM; i++) {
		visited[i] = UNVISITED;
	}
}
int cALGraph::LocateVex(VertexType vex)
{
	for (int i = 0; i < vexnum; i++) {
		if (strcmp(vex, vexs[i].data) == 0) {
			return i;
		}
	}
	return -1;
}
void cALGraph::CreateGraph()
{
	int iKind = 0;
	int iPos = 0;
	FILE*pF = NULL;
	ElemType elem;
	char arrcBuf[MAX_BUF_SIZE],arrcName[MAX_NAME];
	char *pFileName = NULL, *pcBuf = arrcBuf;

	cout << "Please input the kind of the graph you want to create.( DG = 1, DN = 2, UDG = 3, UDN = 4)" << endl;
	cin >> iKind;
	switch (iKind) {
	case DG:
		pFileName = FILEDG;
		kind = DG;
		break;
	case DN:
		pFileName = FILEDN;
		kind = DN;
		break;
	case UDG:
		pFileName = FILEUDG;
		kind = UDG;
		break;
	case UDN:
		pFileName = FILEUDN;
		kind = UDN;
		break;
	default:
		cout << "Invalid parameter." << endl;
		CreateGraph();
		return;
		break;
	}
	if (fopen_s(&pF, pFileName, "r") != 0) {
		cout << "Can not open file." << endl;
		exit(0);
	}
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	vexnum = atoi(pcBuf);
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	arcnum = atoi(pcBuf);
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	for (int i = 0; GetSubStr(arrcName, pcBuf);i++) {
		InitList(vexs[i].firstarc);
		strcpy_s(vexs[i].data, arrcName);
	}
	pcBuf = arrcBuf;
	int iPosHead = 0, iPosTail = 0;
	while (fgets(pcBuf, MAX_BUF_SIZE, pF)) {
		GetSubStr(arrcName, pcBuf);
		iPosTail = LocateVex(arrcName);
		GetSubStr(arrcName, pcBuf);
		iPosHead = LocateVex(arrcName);
		elem.adjvax = iPosHead;
		if (GetSubStr(arrcName, pcBuf) != ERROR && (kind == DN || kind == UDN)) {
			elem.info = new int;
			*elem.info = atoi(arrcName);
		}
		ListInsert(vexs[iPosTail].firstarc, 1, elem);
		if (kind == UDG || kind == UDN) {
			ListInsert(vexs[iPosHead].firstarc, 1, elem);
		}
		pcBuf = arrcBuf;
	}
}
void cALGraph::DestroyGraph()
{
	ElemType DelElem;
	for (int i = 0; i < vexnum; i++) {
		if (kind == UDG || kind == DG) {
			ClearList(vexs[i].firstarc);		
		}
		else {
			while (ListEmpty(vexs[i].firstarc) != TRUE) {
				ListDelete(vexs[i].firstarc, 1, DelElem);
				if (kind == UDN) {
					if (i < DelElem.adjvax) {
						delete DelElem.info;
						DelElem.info = NULL;
					}
				}
				else {
					delete DelElem.info;
					DelElem.info = NULL;
				}
			}
		}
	}
	arcnum = 0;
	vexnum = 0;
}
VertexType&cALGraph::GetVex(int i)
{
	return vexs[i].data;
}
Status cALGraph::PutVex(VertexType origin, VertexType newone)
{
	int iPos = 0;
	iPos = LocateVex(origin);
	if (iPos >= 0) {
		strcpy_s(vexs[iPos].data, newone);
		return OK;
	}
	return ERROR;
}
int cALGraph::FirstAdjVex(VertexType vex)
{
	int iPos = 0;
	iPos = LocateVex(vex);
	if (iPos >= 0) {
		ElemType elem;
		GetElem(vexs[iPos].firstarc, 1, elem);
		return elem.adjvax;
	}
	return -1;
}
Status equalvex(ElemType elem1, ElemType elem2)
{
	if (elem1.adjvax == elem2.adjvax) {
		return OK;
	}
	return ERROR;
}
int cALGraph::NextAdjVex(VertexType center, VertexType pre)
{
	int iPosCenter = 0, iPosPre = 0;
	LinkList LFront = NULL, LPre = NULL;
	ElemType elem;
	iPosCenter = LocateVex(center);
	iPosPre = LocateVex(pre);
	elem.adjvax = iPosPre;
	elem.info = NULL;
	LPre = Point(vexs[iPosCenter].firstarc, elem, equalvex, LFront);
	if (LPre == NULL || LPre->nextarc == NULL) {
		return -1;
	}
	return LPre->data.adjvax;
}
void cALGraph::InsertVex(VertexType vex)
{
	if (vexnum == MAX_VERTEX_NUM - 1) {
		cout << "There is no free memeroy avilible. " << endl;
		exit(0);
	}
	strcpy_s(vexs[vexnum].data, vex);
	InitList(vexs[vexnum].firstarc);
	vexnum++;
}
Status cALGraph::DeleteVex(VertexType vex)
{
	int iPos = 0;
	ElemType ElemDel1,ElemDel2;
	iPos = LocateVex(vex);
	if (iPos < 0) {
		return ERROR;
	}
	if (kind == DG || kind == UDG) {
		arcnum -= ListLength(vexs[iPos].firstarc);
		ClearList(vexs[iPos].firstarc);
	}
	else {
		while (ListEmpty(vexs[iPos].firstarc) != TRUE) {
			ListDelete(vexs[iPos].firstarc,1, ElemDel1);
			delete ElemDel1.info;
			ElemDel1.info = NULL;
			arcnum--;
		}
	}
	ElemDel1.adjvax = iPos;
	for (int i = iPos; i < vexnum - 1; i++) {
		vexs[i].firstarc = vexs[i + 1].firstarc;
		strcpy_s(vexs[i].data, vexs[i + 1].data);
	}
	vexnum--;
	for (int i = 0; i < vexnum; i++) {
		if (DeleteElem(vexs[i].firstarc, ElemDel1, equalvex) == OK) {
			if (kind==DN) {
				delete ElemDel1.info;					
			}
			arcnum--;
			ElemDel1.info = NULL;
		}
		for (int j = iPos + 1; j <= vexnum; j++) {
			LinkList LPre = NULL, LFront = NULL;
			ElemDel2.adjvax = j;
			LPre = Point(vexs[i].firstarc, ElemDel2, equalvex, LFront);
			if (LPre != NULL) {
				LPre->data.adjvax--;				
			}
		}
	}
	return OK;
}
Status cALGraph::InsertArc(VertexType head, VertexType tail)
{
	int iPosHead = 0, iPosTail = 0;
	int iWeight = 0;
	ElemType elem;
	iPosHead = LocateVex(head);
	iPosTail = LocateVex(tail);
	if (iPosHead < 0 || iPosTail < 0) {
		cout << "Invalid parameter." << endl;
		return ERROR;
	}
	if (kind == UDN || kind == DN) {
		cout << "Please input the weight of the arc." << endl;
		cin >> iWeight;
		elem.info = new InfoType;
		*elem.info = iWeight;
	}
	elem.adjvax = iPosHead;
	ListInsert(vexs[iPosTail].firstarc, 1, elem);
	if (kind == UDN || kind == UDG) {
		elem.adjvax = iPosTail;
		ListInsert(vexs[iPosHead].firstarc, 1, elem);
	}
	arcnum++;
	return OK;
}
Status cALGraph::DeleteArc(VertexType head, VertexType tail)
{
	int iPosHead = 0, iPosTail = 0;
	ElemType elem;
	iPosHead = LocateVex(head);
	iPosTail = LocateVex(tail);
	if (iPosHead < 0 || iPosTail < 0) {
		cout << "Invalid parameter." << endl;
		return ERROR;
	}
	elem.adjvax = iPosHead;
	DeleteElem(vexs[iPosTail].firstarc, elem, equalvex);
	if (elem.info != NULL) {
		delete elem.info;
		elem.info = NULL;
	}
	if (kind == UDN || kind == UDG) {
		elem.adjvax = iPosTail;
		DeleteElem(vexs[iPosHead].firstarc, elem, equalvex);
	}
	arcnum--;
	return OK;
}
void cALGraph::DFS(void(*visit)(VertexType elem),int vex)
{
	int iPosPre = vex, iPosNext = 0;
	visited[vex] = VISITED;
	visit(vexs[vex].data);
	for (iPosNext = FirstAdjVex(vexs[iPosPre].data); iPosNext > 0; iPosNext = NextAdjVex(vexs[iPosPre].data, vexs[iPosNext].data)) {
		if (visited[iPosNext] != VISITED) {
			DFS(visit, iPosNext);
		}
	}
}
void cALGraph::DFSTraverse(void(*visit)(VertexType elem))
{
	for (int i = 0; i < vexnum; i++) {
		visited[i] = UNVISITED;
	}
	for (int i = 0; i < vexnum; i++) {
		if (visited[i] != VISITED) {
			DFS(visit, i);
		}
	}
}
void cALGraph::BFSTreaverse(void(*visit)(VertexType elem))
{
	LinkQueue Q;
	int iPosPre = 0, iPosNext = 0;
	for (int i = 0; i < vexnum; i++) {
		visited[i] = UNVISITED;
	}
	InitQueue(Q);
	for (int i = 0; i < vexnum; i++) {
		if (visited[i] != VISITED) {
			visit(vexs[i].data);
			visited[i] = VISITED;
			EnQueue(Q, i);
			while (QueueEmpty(Q) != TRUE) {
				DeQueue(Q, iPosPre);
				for (iPosNext = FirstAdjVex(vexs[iPosPre].data); iPosNext > 0; iPosNext = NextAdjVex(vexs[iPosPre].data, vexs[iPosNext].data)) {
					if (visited[iPosNext] == UNVISITED) {
						visited[iPosNext] = VISITED;
						visit(vexs[iPosNext].data);
						EnQueue(Q, iPosNext);
					}
				}

			}
		}
	}
	cout << endl;
}
void cALGraph::Display()
{
	ArcNode *pA_Elem = NULL;
	cout << "There are " << vexnum << " vertex(s) and " << arcnum << " arc(s) in the ";
	switch (kind) {
	case UDG:cout << "UDG." << endl; break;
	case DG:cout << "DG" << endl; break;
	case UDN:cout << "UDN" << endl; break;
	case DN:cout << "DN" << endl; break;
	}
	cout << "The vertex(s):" << endl;
	for (int i = 0; i < vexnum; i++) {
		cout << vexs[i].data << ends;
	}
	cout << endl;
	cout << "The arc(s):" << endl;
	for (int i = 0; i < vexnum; i++) {
		for (pA_Elem = vexs[i].firstarc; pA_Elem != NULL;pA_Elem=pA_Elem->nextarc) {
			if (i < pA_Elem->data.adjvax || kind == DN || kind == DG) {
				cout << vexs[i].data << "->" << vexs[pA_Elem->data.adjvax].data << ends;
			}		
			if (kind == UDN || kind == DN) {			
				cout << *pA_Elem->data.info << endl;
			}
		}	
	}
	cout << endl;
}
GraphKind cALGraph::GetKind()
{
	return kind;
}

//Function about Queue*************************************************
void InitQueue(LinkQueue &q)
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (q.front == NULL)
		exit(1);
	q.front->next = NULL;
}
void EnQueue(LinkQueue &q, QElemType elem)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(-1);
	p->data = elem;
	p->next = q.rear->next;
	q.rear->next = p;
	q.rear = p;
}
Status DeQueue(LinkQueue &q, QElemType &elem)
{
	if (QueueEmpty(q))
		return ERROR;
	QueuePtr p = q.front->next;
	elem = p->data;
	if (q.front->next == q.rear) {
		q.rear = q.front;
		q.front->next = NULL;
	}
	else {
		q.front->next = p->next;
	}
	free(p);
	p = NULL;
	return OK;
}
Status QueueEmpty(LinkQueue &q)
{
	if (!q.front->next)
		return TRUE;
	else
		return FALSE;
}
//Function************************************************************
Status GetSubStr(char *sub, char *&str)
{
	char *pcPos = NULL;
	if ((pcPos = strchr(str, ' ')) != NULL || (pcPos = strchr(str, '\n')) != NULL) {
		*pcPos = '\0';
		strcpy_s  (sub,MAX_NAME, str);
		str = pcPos + 1;
		return OK;
	}
	return ERROR;
}
void visit(VertexType vex)
{
	cout << vex << ends;
}
//Function about List**************************************************
void InitList(LinkList&L)
{
	L = NULL;
}
void ClearList(LinkList&L)
{
	LinkList p = L;
	while (L) {
		L = L->next;
		free(p);
		p = L;
	}
}
int ListLength(LinkList L)
{
	LinkList p = L;
	int length = 0;
	while (p) {
		p = p->next;
		length++;
	}
	return length;
}
int LocateElem(LinkList L, ElemType elem, Status(*compare)(ElemType elem_a, ElemType elem_b))
{
	LinkList p = L;
	int count = 1;
	while (p) {
		if (compare(p->data, elem) == OK)
			return count;
		count++;
		p = p->next;
	}
	return 0;
}
Status GetElem(LinkList L, int i, ElemType&elem)
{
	LinkList p = L;
	int count = 1;
	while (p&&count < i) {
		p = p->next;
		count++;
	}
	if (!p || count>i)
		return INFEASIBLE;
	elem = p->data;
	return OK;
}
Status ListInsert(LinkList&L, int i, ElemType elem)
{
	LinkList p = L, p_temp = NULL;
	int count = 1;
	if (i == 1) {
		p_temp = (LinkList)malloc(sizeof(LNode));
		p_temp->data = elem;
		p_temp->next = L;
		L = p_temp;
		return OK;
	}
	while (count < i - 1 && p) {
		count++;
		p = p->next;
	}
	if (!p || count>i)
		return ERROR;
	p_temp = (LinkList)malloc(sizeof(LNode));
	p_temp->data = elem;
	p_temp->next = p->next;
	p->next = p_temp;
	return OK;
}
Status ListDelete(LinkList &L, int i, ElemType &elem)
{
	LinkList p = L, p_temp;
	int count = 1;
	if (i == 1) {
		elem = L->data;
		L = NULL;
		free(p);
		return OK;
	}
	while (p->next&&count < i - 1) {
		count++;
		p = p->next;
	}
	if (!p->next || i - 1 < count) {

		return ERROR;
	}

	p_temp = p->next;
	p->next = p_temp->next;
	elem = p_temp->data;

	free(p_temp);
	return OK;
}
Status ListEmpty(LinkList L)
{
	if (L)
		return FALSE;
	else
		return TRUE;
}
Status DeleteElem(LinkList&L, ElemType&elem, Status(*equal)(ElemType elem_a, ElemType elem_b))
{
	LinkList p_front, p_back, p_temp;
	p_back = Point(L, elem, equal, p_front);
	if (p_back) {
		if (p_front) {
			p_front->next = p_back->next;
			elem = p_back->data;
			free(p_back);
		}
		else {
			p_temp = L;
			L = L->next;
			elem = p_back->data;
			free(p_temp);
		}
		return OK;
	}

	return ERROR;
}
// 查找表L中满足条件的结点。如找到，返回指向该结点的指针， p指向该结点的前驱(若该结点是
// 首元结点，则p=NULL)。如表L中无满足条件的结点，则返回NULL， p无定义。
// 函数equal()的两形参的关键字相等，返回OK；否则返回ERROR
LinkList Point(LinkList L, ElemType elem, Status(*equal)(ElemType elem_a, ElemType elem_b), LinkList&p)
{
	int i, j;
	i = LocateElem(L, elem, equal);
	if (i) {
		if (i == 1) {
			p = NULL;
			return L;
		}
		else {
			p = L;
			for (j = 2; j < i; j++) {
				p = p->next;
			}
			return p->next;
		}
	}
	return NULL;
}