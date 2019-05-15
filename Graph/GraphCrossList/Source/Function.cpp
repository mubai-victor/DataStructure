#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;
//Function of struct ElemType*****************************************
ElemType::ElemType()
{
	head = NULL;
	info = NULL;
}
//Function of struct ArcBox1******************************************
ArcBox1::ArcBox1()
{
	head = tail = NULL;
	info = NULL;
}
//Function of struct VexNode******************************************
VexNode::VexNode()
{
	firstin = NULL;
	firstout = NULL;
}
//Function of class ArcBox******************************************
ArcBox::ArcBox()
{
	tail = NULL;
}
//Function of class ArcBox******************************************
OLGraph::OLGraph()
{
	vexnum = arcnum = 0;
}
int OLGraph::LocateVex(VertexType vex)
{
	for (int i = 0; i < vexnum; i++) {
		if (strcmp(vexs[i].data, vex) == 0) {
			return i;
		}
	}
	return -1;
}
void OLGraph::CreateDG(char *file)
{
	FILE*pF = NULL;
	char arrcBuf[MAX_BUF_SIZE], arrcName[MAX_NAME];
	char *pcBuf = arrcBuf;
	if (fopen_s(&pF, file, "r") != 0) {
		cout << "Can not open file." << endl;
		exit(0);
	}
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	vexnum = atoi(pcBuf);
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	arcnum = atoi(pcBuf);
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	for (int i = 0; GetSubStr(arrcName, pcBuf) != ERROR; i++) {
		strcpy_s(vexs[i].data, arrcName);
		vexs[i].firstin = NULL;
		vexs[i].firstout = NULL;
	}
	pcBuf = arrcBuf;
	int iPosHead = 0, iPosTail = 0;
	ArcBox *pArc = NULL;
	while (fgets(pcBuf, MAX_BUF_SIZE, pF) != 0) {	
		GetSubStr(arrcName, pcBuf);
		iPosTail = LocateVex(arrcName);
		GetSubStr(arrcName, pcBuf);
		iPosHead = LocateVex(arrcName);
		pArc = new ArcBox;
		pArc->data.headvex = iPosHead;
		pArc->data.tailvex = iPosTail;
		if (GetSubStr(arrcName, pcBuf) != ERROR) {
			pArc->data.info = new InfoType;
			*pArc->data.info = atoi(arrcName);
		}
		else {
			pArc->data.info = NULL;
		}
		pArc->tail = vexs[iPosTail].firstout;
		pArc->data.head = vexs[iPosHead].firstin;
		vexs[iPosTail].firstout = pArc;
		vexs[iPosHead].firstin = (ArcBox1*)pArc;
	}
	fclose(pF);
}
void OLGraph::DestroyGraph()
{
	ElemType elem;
	for (int i = 0; i < vexnum; i++) {
		while (ListEmpty(vexs[i].firstout) != TRUE) {
			ListDelete(vexs[i].firstout, 1, elem);
			if (elem.info != NULL) {
				delete elem.info;
				elem.info = NULL;
			}
		}
	}
	arcnum = vexnum = 0;
}
VertexType& OLGraph::GetVex(int v)
{
	if (v >= 0 && v < vexnum) {
		return vexs[v].data;
	}
}
Status OLGraph::PutVex(VertexType origin, VertexType value)
{
	int iPos = 0;
	iPos = LocateVex(origin);
	if (iPos<0) {
		return ERROR;
	}
	strcpy_s(vexs[iPos].data, value);
	return OK;
}
int OLGraph::FirstAdjVex(VertexType center)
{
	int iPos = 0;
	iPos = LocateVex(center);
	if (iPos < 0) {
		return -1;
	}
	return vexs[iPos].firstout->data.headvex;
}
int OLGraph::NextAdjVex(VertexType center, VertexType pre)
{
	ArcBox *pNext = NULL;
	int iPosCenter = 0, iPosPre = 0;
	iPosCenter = LocateVex(center);
	iPosPre = LocateVex(pre);
	if (iPosCenter < 0 || iPosPre < 0) {
		return -1;
	}
	pNext = vexs[iPosCenter].firstout;
	while (pNext&&pNext->data.headvex != iPosPre) {
		pNext = pNext->tail;
	}
	if (pNext != NULL&&pNext->tail != NULL) {
		return pNext->data.headvex;
	}
	return -1;
}
void OLGraph::InsertVex(VertexType vex)
{
	vexs[vexnum].firstin = NULL;
	vexs[vexnum].firstout = NULL;
	strcpy_s(vexs[vexnum].data, vex);
	vexnum++;
}
Status OLGraph::DeleteVex(VertexType vex)
{
	int iPos = LocateVex(vex);
	if (iPos < 0) {
		return ERROR;
	}
	ArcBox1 *pArcBox1 = NULL, *pArcBox1Front = NULL;
	ArcBox *pArcBox = NULL;
	ArcBox arcbox;
	ArcBox1 arcbox1;
	ElemType elem;
	elem.headvex = iPos;
	for (int i = 0; i < vexnum; i++) {
		arcbox1.headvex = iPos;
		if (DeleteElem(vexs[i].firstout, elem, equalvex) == OK) {
			arcnum--;
			if (elem.info != NULL) {
				delete elem.info;
				elem.info = NULL;
			}
		}
	}
	for (int i = 0; i < vexnum; i++) {
		pArcBox1Front = pArcBox1 = vexs[i].firstin;
		while (pArcBox1 != NULL&&pArcBox1->tailvex != iPos) {
			pArcBox1Front = pArcBox1;
			pArcBox1 = pArcBox1->head;
		}
		if (pArcBox1 != NULL) {
			if (pArcBox1 == vexs[i].firstin) {
				vexs[i].firstin = pArcBox1->head;
			}
			else{
				pArcBox1Front->head = pArcBox1->head;
			}
			if (pArcBox1->info != NULL) {
				delete pArcBox1->info;
				pArcBox1->info = NULL;
			}
			delete pArcBox1;
			pArcBox1 = NULL;
			arcnum--;
		}
	}
	for (int i = iPos; i < vexnum - 1; i++) {
		vexs[i].firstin = vexs[i + 1].firstin;
		vexs[i].firstout = vexs[i + 1].firstout;
		strcpy_s(vexs[i].data, vexs[i + 1].data);
	}
	vexnum--;
	for (int i = 0; i < vexnum; i++) {
		pArcBox = vexs[i].firstout;
		while (pArcBox != NULL) {
			if (pArcBox->data.headvex > iPos) {
				pArcBox->data.headvex--;
			}
			if (pArcBox->data.tailvex > iPos) {
				pArcBox->data.tailvex--;
			}
			pArcBox = pArcBox->tail;
		}
	}
	return OK;
}
Status OLGraph::InsertArc(VertexType head, VertexType tail)
{
	int iPosHead = 0, iPosTail = 0;
	int iFlag = 0;
	ArcBox *pArcBox = NULL;
	iPosHead = LocateVex(head);
	iPosTail = LocateVex(tail);
	if (iPosHead < 0 || iPosTail < 0) {
		return ERROR;
	}
	pArcBox = new ArcBox;
	pArcBox->data.headvex = iPosHead;
	pArcBox->data.tailvex = iPosTail;
	cout << "Does the arc own the weight?(1 for yes,other for no)" << endl;
	cin >> iFlag;
	if (iFlag == 1) {
		cout << "Input the weight of the arc." << endl;
		pArcBox->data.info = new InfoType;
		cin >> *pArcBox->data.info;
	}
	else {
		pArcBox->data.info = NULL;
	}
	pArcBox->tail = vexs[iPosTail].firstout;
	pArcBox->data.head = (ArcBox1*)vexs[iPosHead].firstin;
	vexs[iPosTail].firstout = pArcBox;
	vexs[iPosHead].firstin = (ArcBox1*)pArcBox;
	arcnum++;
	return OK;
}
Status OLGraph::DeleteArc(VertexType head, VertexType tail)
{
	int iPosHead = 0, iPosTail = 0;
	ElemType elem;
	iPosHead = LocateVex(head);
	iPosTail = LocateVex(tail);
	if (iPosHead < 0 || iPosTail < 0) {
		return ERROR;
	}
	ArcBox *pArcBoxTail = vexs[iPosTail].firstout;
	ArcBox1 *pArcBoxHead = vexs[iPosHead].firstin, *pArcBoxHeadFront = pArcBoxHead;
	while (pArcBoxHead != NULL && pArcBoxHead->tailvex != iPosTail) {
		pArcBoxHeadFront = pArcBoxHead;
		pArcBoxHead = pArcBoxHead->head;
	}
	if (pArcBoxHead != NULL) {
		if (pArcBoxHead == vexs[iPosHead].firstin) {
			vexs[iPosHead].firstin = pArcBoxHead->head;
		}
		else {
			pArcBoxHeadFront->head = pArcBoxHead->head;
		}
	}
	elem.headvex = iPosHead;
	DeleteElem(vexs[iPosTail].firstout, elem, equalvex);
	if (elem.info != NULL) {
		delete elem.info;
		elem.info = NULL;
	}
	arcnum--;
	return OK;
}
void OLGraph::Display()
{
	ArcBox *pArcBox = NULL;
	cout << "There are " << vexnum << " vex(s)" << endl;
	for (int i = 0; i < vexnum; i++) {
		cout << vexs[i].data << ends;
	}
	cout << "And " << arcnum << " arc(s)" << endl;
	for (int i = 0; i < vexnum; i++) {
		pArcBox = vexs[i].firstout;
		while (pArcBox != NULL) {
			cout << vexs[pArcBox->data.tailvex].data << "->" << vexs[pArcBox->data.headvex].data;
			if (pArcBox->data.info != NULL) {
				cout << ends << *pArcBox->data.info;
			}
			pArcBox = pArcBox->tail;
			cout << endl;
		}
	}
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
Status equalvex(ElemType elem1, ElemType elem2)
{
	if (elem1.headvex == elem2.headvex) {
		return TRUE;
	}
	else {
		return FALSE;
	}
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