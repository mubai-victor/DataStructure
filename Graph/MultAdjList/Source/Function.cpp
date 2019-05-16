#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;
//Function of struct EBox*****************************************
EBox::EBox()
{
	mark = UNVISITED;
	ilink = jlink = NULL;
	info = NULL;
}
//Function of struct VerBox******************************************
VexBox::VexBox()
{
	firstedge = NULL;
}
//Function of class ArcBox******************************************
AMLGraph::AMLGraph()
{
	vexnum = arcnum = 0;
	for (int i = 0; i < MAX_VERTEX_NUM; i++) {
		mark[i] = UNVISITED;
	}
}
int AMLGraph::LocateVex(VertexType vex)
{
	for (int i = 0; i < vexnum; i++) {
		if (strcmp(vex, vexs[i].data) == 0) {
			return i;
		}
	}
	return -1;
}
void AMLGraph::CreateGraph(char*file)
{
	FILE *pF = NULL;
	char arrcBuf[MAX_BUF_SIZE],arrcSub[MAX_NAME];
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
	for (int i = 0; GetSubStr(arrcSub, pcBuf); i++) {
		strcpy_s(vexs[i].data, arrcSub);
		vexs[i].firstedge = NULL;
	}
	pcBuf = arrcBuf;
	int iPosVex1 = 0, iPosVex2 = 0;
	EBox *pBox = NULL;
	while (fgets(pcBuf, MAX_BUF_SIZE, pF)) {
		GetSubStr(arrcSub, pcBuf);
		iPosVex1 = LocateVex(arrcSub);
		GetSubStr(arrcSub, pcBuf);
		iPosVex2 = LocateVex(arrcSub);
		pBox = new EBox;
		pBox->ivex = iPosVex1;
		pBox->jvex = iPosVex2;
		pBox->ilink = vexs[iPosVex1].firstedge;
		vexs[iPosVex1].firstedge = pBox;
		pBox->jlink = vexs[iPosVex2].firstedge;
		vexs[iPosVex2].firstedge = pBox;
		if (GetSubStr(arrcSub, pcBuf) != ERROR) {
			pBox->info = new InfoType;
			*pBox->info = atoi(arrcSub);
		}
		else {
			pBox->info = NULL;
		}
		pcBuf = arrcBuf;
	}
	fclose(pF);
}
VertexType& AMLGraph::GetVex(int pos)
{
	if (pos < vexnum&&pos >= 0) {
		return vexs[pos].data;
	}
}
Status AMLGraph::PutVex(VertexType origin, VertexType value)
{
	int iPos = LocateVex(origin);
	if (iPos < 0) {
		return ERROR;
	}
	strcpy_s(vexs[iPos].data, value);
	return OK;
}
int AMLGraph::FirstAdjVex(VertexType vex)
{
	int iPos = LocateVex(vex);
	if (vex < 0 || vexs[iPos].firstedge == NULL) {
		return -1;
	}
	if (vexs[iPos].firstedge->ivex == iPos) {
		return vexs[iPos].firstedge->jvex;
	}
	else {
		return vexs[iPos].firstedge->ivex;
	}
}
int AMLGraph::NextAdjVex(VertexType center, VertexType next)
{
	int iPosCenter = LocateVex(center);
	int iPosNext = LocateVex(next);
	if (iPosCenter < 0 || iPosNext < 0) {
		return -1;
	}
	EBox*pbox = vexs[iPosCenter].firstedge;
	while (pbox != NULL) {
		if (pbox->ivex == iPosCenter&&pbox->jvex != iPosNext) {
			pbox = pbox->ilink;
		}
		else if (pbox->jvex == iPosCenter&&pbox->ivex != iPosNext) {
			pbox = pbox->jlink;
		}
		else {
			break;
		}
	}
	if (pbox == NULL||(pbox->ivex == iPosCenter&&pbox->ilink==NULL)||(pbox->jvex == iPosCenter&&pbox->jlink==NULL)) {
		return -1;
	}
	if (pbox->ivex == iPosCenter) {
		pbox = pbox->ilink;
	}
	else {
		pbox = pbox->jlink;
	}
	if (pbox->ivex == iPosCenter) {
		return pbox->jvex;
	}
	else {
		return pbox->ivex;
	}
}
Status AMLGraph::DeleteArc(VertexType vex1, VertexType vex2)
{
	int iPosVex1 = LocateVex(vex1);
	int iPosVex2 = LocateVex(vex2);
	if (iPosVex1 < 0 || iPosVex2 < 0) {
		return ERROR;
	}
	EBox *pBox = vexs[iPosVex1].firstedge;
	EBox *pBoxFront = NULL;
	if (vexs[iPosVex1].firstedge != NULL&&vexs[iPosVex1].firstedge->ivex == iPosVex1&&vexs[iPosVex1].firstedge->jvex == iPosVex2) {
		vexs[iPosVex1].firstedge = vexs[iPosVex1].firstedge->ilink;
	}
	else if (vexs[iPosVex1].firstedge != NULL&&vexs[iPosVex1].firstedge->jvex == iPosVex1&&vexs[iPosVex1].firstedge->ivex == iPosVex2) {
		vexs[iPosVex1].firstedge = vexs[iPosVex1].firstedge->jlink;
	}
	else {		
		while (pBox != NULL) {
			if (pBox->ivex == iPosVex1&&pBox->jvex != iPosVex2) {
				pBoxFront = pBox;
				pBox = pBox->ilink;
			}
			else if (pBox->jvex == iPosVex1&&pBox->ivex != iPosVex2) {
				pBoxFront = pBox;
				pBox = pBox->jlink;
			}
			else {
				break;
			}
		}
		if (pBox == NULL) {
			return ERROR;
		}
		if (pBox->jvex == iPosVex2) {
			if (pBoxFront->ilink == pBox) {
				pBoxFront->ilink = pBox->ilink;
			}
			else {
				pBoxFront->jlink = pBox->ilink;
			}
		}
		if (pBox->ivex == iPosVex2) {
			if (pBoxFront->ilink == pBox) {
				pBoxFront->ilink = pBox->jlink;
			}
			else {
				pBoxFront->jlink = pBox->jlink;
			}
		}
	}
	pBox = vexs[iPosVex2].firstedge;
	pBoxFront = NULL;
	if (vexs[iPosVex2].firstedge != NULL&&vexs[iPosVex2].firstedge->ivex == iPosVex2&&vexs[iPosVex2].firstedge->jvex == iPosVex1) {
		vexs[iPosVex2].firstedge = vexs[iPosVex2].firstedge->ilink;
	}
	else if (vexs[iPosVex2].firstedge != NULL&&vexs[iPosVex2].firstedge->jvex == iPosVex2&&vexs[iPosVex2].firstedge->ivex == iPosVex1) {
		vexs[iPosVex2].firstedge = vexs[iPosVex2].firstedge->jlink;
	}
	else {
		while (pBox != NULL) {
			if (pBox->ivex == iPosVex2&&pBox->jvex != iPosVex1) {
				pBoxFront = pBox;
				pBox = pBox->ilink;
			}
			else if (pBox->jvex == iPosVex2&&pBox->ivex != iPosVex1) {
				pBoxFront = pBox;
				pBox = pBox->jlink;
			}
			else {
				break;
			}
		}
		if (pBox == NULL) {
			return ERROR;
		}
		if (pBox->jvex == iPosVex1) {
			if (pBoxFront->ilink == pBox) {
				pBoxFront->ilink = pBox->ilink;
			}
			else {
				pBoxFront->jlink = pBox->ilink;
			}
		}
		if (pBox->ivex == iPosVex1) {
			if (pBoxFront->ilink == pBox) {
				pBoxFront->ilink = pBox->jlink;
			}
			else {
				pBoxFront->jlink = pBox->jlink;
			}
		}
	}
	if (pBox->info != NULL) {
		delete pBox->info;
		pBox->info = NULL;
	}
	delete pBox;
	pBox = NULL;
	arcnum--;
	return OK;
}
Status AMLGraph::DeleteVex(VertexType vex)
{
	int iPos = LocateVex(vex);
	EBox*pBox = NULL;
	if (iPos < 0) {
		return ERROR;
	}
	for (int i = iPos; i < vexnum - 1; i++) {
		vexs[i].firstedge = vexs[i + 1].firstedge;
		strcpy_s(vexs[i].data, vexs[i + 1].data);
	}
	for (int i = 0; i < vexnum; i++) {
		DeleteArc(vexs[i].data, vex);
	}
	vexnum--;
	for (int i = iPos; i < vexnum; i++) {
		pBox = vexs[iPos].firstedge;
		while (pBox != NULL) {
			if (pBox->ivex == iPos + 1) {
				pBox->ivex--;
				pBox = pBox->ilink;
			}
			else {
				pBox->jvex--;
				pBox = pBox->jlink;
			}
		}
	}

	return OK;
}
void AMLGraph::DestroyGraph()
{
	for (int i = vexnum-1; i > 0; i--) {
		DeleteVex(vexs[i].data);
	}
}
Status AMLGraph::InsertVex(VertexType vex)
{
	if (vexnum == MAX_VERTEX_NUM) {
		cout << "The space is full, can not add new vertex." << endl;
		return ERROR;
	}
	strcpy_s(vexs[vexnum].data, vex);
	vexnum++;
	return OK;
}
Status AMLGraph::InsertArc(VertexType vex1, VertexType vex2)
{
	int iPosVex1 = LocateVex(vex1);
	int iPosVex2 = LocateVex(vex2);
	if (iPosVex1 < 0 || iPosVex2 < 0) {
		return ERROR;
	}
	EBox *pBox = new EBox;
	pBox->ivex = iPosVex1;
	pBox->jvex = iPosVex2;
	pBox->ilink = vexs[iPosVex1].firstedge;
	vexs[iPosVex1].firstedge = pBox;
	pBox->jlink = vexs[iPosVex2].firstedge;
	vexs[iPosVex2].firstedge = pBox;
	arcnum++;
	int iFlag = 0;
	cout << "Does the arc own weight?(1 for yes,others for no)" << endl;
	cin >> iFlag;
	if (iFlag == 1) {
		cout << "Input the weight of the arc." << endl;
		pBox->info = new int;
		cin >> *pBox->info;
	}
	else {
		pBox->info = NULL;
	}
}
void AMLGraph::DFS(int pos, void(*func)(VertexType))
{
	int iCenter = 0, iNext = 0;
	mark[pos] = VISITED;
	func(vexs[pos].data);
	for (iNext = FirstAdjVex(vexs[pos].data); iNext > 0; iNext = NextAdjVex(vexs[pos].data, vexs[iNext].data)) {
		if (mark[iNext] != VISITED) {
			DFS(iNext, func);
		}
	}
}
void AMLGraph::DFSTraverse(void(*func)(VertexType))
{
	for (int i = 0; i < vexnum; i++) {
		mark[i] = UNVISITED;
	}
	for (int i = 0; i < vexnum; i++) {
		if (mark[i] == UNVISITED) {
			DFS(i, func);
		}
	}
}
void AMLGraph::BFSTraverse(void(*func)(VertexType))
{
	LinkQueue Q;
	int iPos = 0, iNext = 0;
	InitQueue(Q);
	for (int i = 0; i < vexnum; i++) {
		mark[i] = UNVISITED;
	}
	for (int i = 0; i < vexnum; i++) {
		if (mark[i] == UNVISITED) {
			mark[i] = VISITED;
			func(vexs[i].data);
			EnQueue(Q, i);
			while (QueueEmpty(Q) != TRUE) {
				DeQueue(Q, iPos);
				for (iNext = FirstAdjVex(vexs[iPos].data); iNext > 0; iNext = NextAdjVex(vexs[iPos].data, vexs[iNext].data)) {
					if (mark[iNext] == UNVISITED) {
						mark[iNext] = VISITED;
						func(vexs[iNext].data);
						EnQueue(Q,iNext);
					}
				}
			}
		}
	}
	cout << endl;
}
void AMLGraph::MarkUnvisited()
{
	EBox *pBox = NULL;
	for (int i = 0; i < vexnum; i++) {
		pBox = vexs[i].firstedge;
		while (pBox != NULL) {
			pBox->mark = UNVISITED;
			if (pBox->ivex == i) {
				pBox = pBox->ilink;
			}
			else {
				pBox = pBox->jlink;
			}
		}
	}
}
void AMLGraph::Display()
{
	cout << "There are " << vexnum << " vex(s)" << endl;
	for (int i = 0; i < vexnum; i++) {
		cout << vexs[i].data << ends;
	}
	cout << endl << "and " << arcnum << " arc(s)" << endl;
	MarkUnvisited();
	EBox *pBox = NULL;
	for (int i = 0; i < vexnum; i++) {
		pBox = vexs[i].firstedge;
		while (pBox != NULL) {
			if (pBox->mark == UNVISITED) {
				pBox->mark = VISITED;
				cout << vexs[pBox->ivex].data << "->" << vexs[pBox->jvex].data << ends;
				if (pBox->info != NULL) {
					cout << *pBox->info;
				}
				cout << endl;
			}
			if (pBox->ivex == i) {
				pBox = pBox->ilink;
			}
			else {
				pBox = pBox->jlink;
			}
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