#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

MGraph::MGraph()
{
	vexnum = 0;
	arcnum = 0;
	for (int i = 0; i < MAX_VERTEX_NUM; i++) {
		visited[i] = 0;
	}
}
int MGraph::LocateVex(VertexType name)
{
	for (int i = 0; i < MAX_VERTEX_NUM; i++) {
		if (strcmp(vexs[i], name) == 0) {
			return i;
		}
	}
	return -1;
}
void MGraph::CreateFUDG(char *filename)//根据文件的内容，构建无向图。
{
	FILE *pF = NULL;
	char arrcBuf[MAX_BUF_SIZE], arrcName[MAX_NAME];
	char *pcBuf = arrcBuf;	
	int iRow = 0, iColumn = 0;
	int iLoop = 0, iPos = 0;
	char *pcPos = NULL;
	int iLength = 0;
	if (fopen_s(&pF, filename, "r") != 0) {
		cout << "can not open the file." << endl;
		exit(0);
	}
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	vexnum = atoi(pcBuf);
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	arcnum = atoi(pcBuf);
	for (iRow = 0; iRow < MAX_VERTEX_NUM; iRow++) {
		for (iColumn = 0; iColumn < MAX_VERTEX_NUM; iColumn++) {
			arcs[iRow][iColumn].adj = 0;
			arcs[iRow][iColumn].info = NULL;
		}
	}
	pcBuf = arrcBuf;
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	for (int i = 0; GetSubString(pcBuf, arrcName) != ERROR; i++) {
		strcpy_s(vexs[i], arrcName);
	}
	while (fgets(pcBuf, MAX_BUF_SIZE, pF) != NULL) {
		GetSubString(pcBuf, arrcName);
		iRow = LocateVex(arrcName);
		GetSubString(pcBuf, arrcName);
		iColumn = LocateVex(arrcName);
		arcs[iRow][iColumn].adj = arcs[iColumn][iRow].adj = 1;
		if (*pcBuf != '\0') {
			iLength = strlen(pcBuf);
			arcs[iRow][iColumn].info = arcs[iColumn][iRow].info = new char[iLength];//strlen()返回的长度不包括字符串结尾符，包含回车换行符。
			for (int i = 0; i < iLength - 1; i++) {
				arcs[iRow][iColumn].info[i] = pcBuf[i];
			}
			arcs[iRow][iColumn].info[iLength - 1] = '\0';
			//strcpy_s(arcs[iRow][iColumn].info, MAX_INFO, pcBuf);
		}
		pcBuf = arrcBuf;
	}
	kind = UDG;	
}
void MGraph::CreateFUDN(char *filename)//根据文件的内容，构建无向网。
{
	FILE *pF = NULL;
	char arrcBuf[MAX_BUF_SIZE], arrcName[MAX_NAME];
	char *pcBuf = arrcBuf;	
	int iRow = 0, iColumn = 0;
	int iLoop = 0, iPos = 0;
	int iWeight = INFINITY;
	char *pcPos = NULL;
	int iLength = 0;
	if (fopen_s(&pF, filename, "r") != 0) {
		cout << "can not open the file." << endl;
		exit(0);
	}
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	vexnum = atoi(pcBuf);
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	arcnum = atoi(pcBuf);
	for (iRow = 0; iRow < MAX_VERTEX_NUM; iRow++) {
		for (iColumn = 0; iColumn < MAX_VERTEX_NUM; iColumn++) {
			arcs[iRow][iColumn].adj = INT_MAX;
			arcs[iRow][iColumn].info = NULL;
		}
	}
	pcBuf = arrcBuf;
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	for (int i = 0; GetSubString(pcBuf, arrcName) != ERROR; i++) {
		strcpy_s(vexs[i], arrcName);
	}
	while (fgets(pcBuf, MAX_BUF_SIZE, pF) != NULL) {
		GetSubString(pcBuf, arrcName);
		iRow = LocateVex(arrcName);
		GetSubString(pcBuf, arrcName);
		iColumn = LocateVex(arrcName);
		GetSubString(pcBuf, arrcName);
		arcs[iRow][iColumn].adj = arcs[iColumn][iRow].adj = atoi(arrcName);
		if (*pcBuf != '\0') {
			iLength = strlen(pcBuf);
			arcs[iRow][iColumn].info = arcs[iColumn][iRow].info = new char[iLength];//strlen()返回的长度不包括字符串结尾符，包含回车换行符。
			//strcpy_s(arcs[iRow][iColumn].info, MAX_INFO, pcBuf);
			for (int i = 0; i < iLength - 1; i++) {
				arcs[iRow][iColumn].info[i] = pcBuf[i];
			}
			arcs[iRow][iColumn].info[iLength - 1] = '\0';
		}
		pcBuf = arrcBuf;
	}
	kind = UDN;
}
void MGraph::CreateDG(char *filename)//根据文件的内容创建有向图。
{
	FILE *pF = NULL;
	char arrcBuf[MAX_BUF_SIZE + 1], arrcName[MAX_NAME + 1];
	char *pcBuf = arrcBuf;
	int iRow = 0, iColumn = 0;
	int iLoop = 0, iPos = 0;
	int iWeight = INFINITY;
	int iLength = 0;
	char *pcPos = NULL;
	if (fopen_s(&pF, filename, "r") != 0) {
		cout << "can not open the file." << endl;
		exit(0);
	}
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	vexnum = atoi(pcBuf);
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	arcnum = atoi(pcBuf);
	for (iRow = 0; iRow < MAX_VERTEX_NUM; iRow++) {
		for (iColumn = 0; iColumn < MAX_VERTEX_NUM; iColumn++) {
			arcs[iRow][iColumn].adj = 0;
			arcs[iRow][iColumn].info = NULL;
		}
	}
	pcBuf = arrcBuf;
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	for (int i = 0; GetSubString(pcBuf, arrcName) != ERROR; i++) {
		strcpy_s(vexs[i], arrcName);
	}
	pcBuf = arrcBuf;
	while (fgets(pcBuf, MAX_BUF_SIZE, pF) != NULL) {
		GetSubString(pcBuf, arrcName);
		iRow = LocateVex(arrcName);
		GetSubString(pcBuf, arrcName);		
		iColumn = LocateVex(arrcName);
		arcs[iRow][iColumn].adj = 1;
		if (*pcBuf != '\0') {
			iLength = strlen(pcBuf);
			arcs[iRow][iColumn].info = new char[iLength];//strlen()返回的长度不包括字符串结尾符，包含回车换行符。
			//strcpy_s(arcs[iRow][iColumn].info, MAX_INFO, pcBuf);
			for (int i = 0; i < iLength - 1; i++) {
				arcs[iRow][iColumn].info[i] = pcBuf[i];
			}
			arcs[iRow][iColumn].info[iLength - 1] = '\0';
		}
		pcBuf = arrcBuf;
	}
	kind = DG;
}
void MGraph::CreateDN(char *filename)//根据文件的内容，构建有向网。
{
	FILE *pF = NULL;
	char arrcBuf[MAX_BUF_SIZE], arrcName[MAX_NAME];
	char *pcBuf = arrcBuf;
	int iRow = 0, iColumn = 0;
	int iLoop = 0, iPos = 0;
	int iLength = 0;
	char *pcPos = NULL;
	if (fopen_s(&pF, filename, "r") != 0) {
		cout << "can not open the file." << endl;
		exit(0);
	}
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	vexnum = atoi(pcBuf);
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	arcnum = atoi(pcBuf);
	for (iRow = 0; iRow < MAX_VERTEX_NUM; iRow++) {
		for (iColumn = 0; iColumn < MAX_VERTEX_NUM; iColumn++) {
			arcs[iRow][iColumn].adj = INT_MAX;
			arcs[iRow][iColumn].info = NULL;
		}
	}
	pcBuf = arrcBuf;
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	for (int i = 0; GetSubString(pcBuf, arrcName) != ERROR; i++) {
		strcpy_s(vexs[i], arrcName);
	}
	while (fgets(pcBuf, MAX_BUF_SIZE, pF) != NULL) {
		GetSubString(pcBuf, arrcName);
		iRow = LocateVex(arrcName);
		GetSubString(pcBuf, arrcName);
		iColumn = LocateVex(arrcName);
		GetSubString(pcBuf, arrcName);
		arcs[iRow][iColumn].adj = atoi(arrcName);
		if (*pcBuf != '\0') {
			iLength = strlen(pcBuf);
			arcs[iRow][iColumn].info = new char[iLength];//strlen()返回的长度不包括字符串结尾符，包含回车换行符。
			pcBuf[strlen(pcBuf) - 1] = '\0';
//			strcpy_s(arcs[iRow][iColumn].info, MAX_INFO, pcBuf);
			for (int i = 0; i < iLength - 1; i++) {
				arcs[iRow][iColumn].info[i] = pcBuf[i];
			}
			arcs[iRow][iColumn].info[iLength - 1] = '\0';
		}
		pcBuf = arrcBuf;
	}
	kind = DN;
}
void MGraph::CreateUSG(char *filename){}
void MGraph::CreateUDN(char *filename){}
void MGraph::CreateGraph()
{
	int iKind;
	cout << "Input the type of the graph you want to create.(1 for DG,2 for DN,3 for UDG and 4 for UDN):";
	cin >> iKind;
	switch (iKind) {
	case UDN:CreateFUDN(FILEUDN); break;
	case UDG:CreateFUDG(FILEUDG); break;
	case DN:CreateDN(FILEDN); break;
	case DG:CreateDG(FILEDG); break;
	default:cout << "Invalid parameter,please try again." << endl; CreateGraph(); break;
	}
}
void MGraph::DestroyGraph()
{
	int iRow = 0, iColumn = 0;
	for (iRow = 0; iRow < arcnum; iRow++) {
		if (kind == UDG || kind == UDN) {
			iColumn = iRow;
		}
		else {
			iColumn = 0;
		}
		for (; iColumn < arcnum; iColumn++) {
			if (arcs[iRow][iColumn].info != NULL) {
				if (strlen(arcs[iRow][iColumn].info) == 1) {
					delete arcs[iRow][iColumn].info;
				}
				else {
					delete[] arcs[iRow][iColumn].info;
				}
				arcs[iRow][iColumn].info = NULL;
			}
		}
	}
	vexnum = 0;
	arcnum = 0;
}
VertexType& MGraph::GetVex(int num)//获取顶点集中序号为num的点。
{
	if (num >= vexnum || num < 0) {
		exit(0);
	}
	else {
		return vexs[num];
	}
}
Status MGraph::PutVex(VertexType origin, VertexType newone)//origin是顶点中的原始值，如果该点存在，将该点的值修改为newone。
{
	int iPos = 0, iLength = 0;
	iPos = LocateVex(origin);
	if (iPos < 0) {
		return ERROR;
	}
	else {
		iLength = strlen(newone);
		for (int i = 0; i < iLength; i++) {
			vexs[iPos][i] = newone[i];			
		}
		vexs[iPos][iLength] = '\0';
		return OK;
	}
}
int MGraph::FirstAdjVex(VertexType vex)//获得顶点vex的第一个邻接点的序号。
{
	int iPos = 0, iValue = 0;
	iPos = LocateVex(vex);
	if (iPos < 0) {
		cout << "The vertex does not exist." << endl;
		exit(0);
	}
	else {
		if (kind == UDG || kind == DG) {
			iValue = 0;
		}
		else {
			iValue = INT_MAX;
		}
		for (int i = 0; i < vexnum; i++) {
			if (arcs[iPos][i].adj != iValue) {
				return i;
			}
		}
		return -1;
	}
}
int MGraph::NextAdjVex(VertexType center, VertexType pre)//获得顶点center在pre后边的第一个邻接点。
{
	int iPosCenter = 0, iPosPre = 0;
	int iValue = 0;
	iPosCenter = LocateVex(center);
	iPosPre = LocateVex(pre);
	if (iPosCenter < 0 || iPosPre < 0) {
		cout << "The vertex does not exsit." << endl;
		exit(0);
	}
	if (kind == UDG || kind == DG) {
		iValue = 0;
	}
	else {
		iValue = INT_MAX;
	}
	for (int i = iPosPre + 1; i < vexnum; i++) {
		if (arcs[iPosCenter][i].adj != iValue) {
			return i;
		}
	}
	return -1;
}
void MGraph::InsertVex(VertexType InsVex)//插入新的点InsVex，并不插入新的弧。
{
	int iValue = 0;
	if (vexnum == MAX_VERTEX_NUM) {
		cout << "The array is full,can not insert new vertex." << endl;
		exit(0);
	}
	strcpy_s(vexs[vexnum], InsVex);
	if (kind == UDG || kind == DG) {
		iValue = 0;
	}
	else {
		iValue = INT_MAX;
	}
	for (int i = 0; i <= vexnum; i++) {
		arcs[vexnum][i].adj = iValue;
		arcs[vexnum][i].info = NULL;
	}
	for (int i = 0; i < vexnum; i++) {
		arcs[i][vexnum].adj = iValue;
		arcs[i][vexnum].info = NULL;		
	}
	vexnum++;
}
Status MGraph::DeleteVex(VertexType DelVex)//删除节点。
{
	int iPos = 0;
	int iValue = 0;
	iPos = LocateVex(DelVex);
	if (kind == UDG || kind == DG) {
		iValue = 0;
	}
	else {
		iValue = INT_MAX;
	}
	if (iPos < 0) {
		cout << "The vertex does not exist." << endl;
		return ERROR;
	}
	if (vexnum == 0) {
		cout << "There is no any vertex in the graph." << endl;
		return ERROR;
	}
	for (int i = iPos; i < vexnum - 1; i++) {
		strcpy_s(vexs[i], vexs[i + 1]);
	}
	for (int i = 0; i < vexnum; i++) {
		if (arcs[iPos][i].adj != iValue) {
			if (arcs[iPos][i].info != NULL) {
				delete[] arcs[iPos][i].info;
				arcs[iPos][i].info = NULL;
			}
			arcnum--;
		}
	}
	if (kind == DN || kind == DG) {
		for (int i = 0; i < vexnum; i++) {
			if (arcs[i][iPos].adj != iValue) {
				if (arcs[i][iPos].info != NULL) {
					delete[] arcs[i][iPos].info;
					arcs[i][iPos].info = NULL;
				}
				arcnum--;
			}
		}
	}
	for (int i = iPos; i < vexnum; i++) {
		for (int j = 0; j < vexnum; j++) {
			arcs[i][j] = arcs[i + 1][j];
		}
	}
	vexnum--;
	for (int i = iPos; i <= vexnum; i++) {
		for (int j = 0; j < vexnum; j++) {
			arcs[j][i] = arcs[j][i + 1];
		}
	}
}
Status MGraph::InsertArc(VertexType InsArcTail, VertexType InsArcHead)//插入一个弧。
{
	char  arrcInfoBuf[MAX_BUF_SIZE];
	int iPosTail = 0, iPosHead = 0;
	int iInfoLen = 0;
	int iFlag = 0;
	iPosHead = LocateVex(InsArcHead);
	iPosTail = LocateVex(InsArcTail);
	if (iPosHead < 0 || iPosTail < 0) {
		cout << "The vertex(s) does not exsit." << endl;
		return ERROR;
	}
	cout << "Does the arc have any information?(1 for yes)" << endl;
	cin >> iFlag;
	if (iFlag == 1) {
		cout << "Please input the information of the arc." << endl;
		cin >> arrcInfoBuf;
	}
	if (iFlag == 1) {
		iInfoLen = strlen(arrcInfoBuf);
		arcs[iPosTail][iPosHead].info = new char[iInfoLen + 1];
		//strcpy_s(arcs[iPosTail][iPosHead].info, MAX_INFO, arrcInfoBuf);
		for (int i = 0; i < iInfoLen; i++) {
			arcs[iPosTail][iPosHead].info[i] = arrcInfoBuf[i];
		}
		arcs[iPosTail][iPosHead].info[iInfoLen] = '\0';
	}
	if (kind == UDG || kind == DG) {
		arcs[iPosTail][iPosHead].adj = 1;
		if (kind == UDG) {
			arcs[iPosHead][iPosTail] = arcs[iPosTail][iPosHead];
		}
	}
	else {
		cout << "Please input the weight of the arc." << endl;
		cin >> arcs[iPosTail][iPosHead].adj;
		if (kind == UDN) {
			arcs[iPosHead][iPosTail] = arcs[iPosTail][iPosHead];
		}
	}
	arcnum++;
	return OK;
}
Status MGraph::DeleteArc(VertexType DelArcTail, VertexType DelArcHead)
{
	int iPosTail = 0, iPosHead = 0;
	int iValue = 0;
	iPosTail = LocateVex(DelArcTail);
	iPosHead = LocateVex(DelArcHead);
	if (iPosTail < 0 || iPosHead < 0) {
		cout << "The vertex does not exist." << endl;
		return ERROR;
	}
	if (kind == UDG || kind == DG) {
		iValue = 0;
	}
	else {
		iValue = INFINITY;
	}
	arcs[iPosTail][iPosHead].adj = iValue;
	if (arcs[iPosTail][iPosHead].info != NULL) {
		if (strlen(arcs[iPosTail][iPosHead].info) == 1) {
			delete arcs[iPosTail][iPosHead].info;
		}
		else {
			delete[] arcs[iPosTail][iPosHead].info;
		}
		arcs[iPosTail][iPosHead].info = NULL;
	}
	if (kind == UDG || kind == UDN) {
		arcs[iPosHead][iPosTail].adj = iValue;
	}
	arcnum--;
}
void MGraph::DFS(int PreVex, void(*visit)(VertexType vex))
{
	int iPosNext = 0;
	visited[PreVex] = VISITED;
	visit(vexs[PreVex]);
	for (iPosNext = FirstAdjVex(vexs[PreVex]); iPosNext >= 0; iPosNext = NextAdjVex(vexs[PreVex], vexs[iPosNext])) {
		if (visited[iPosNext] == UNVISITED) {
			DFS(iPosNext, visit);
		}
	}
}
void MGraph::DFSTraverse(void(*visit)(VertexType vex))
{
	for (int i = 0; i < vexnum; i++) {
		visited[i] = UNVISITED;
	}
	for (int i = 0; i < vexnum; i++) {
		if (visited[i] == UNVISITED) {
			DFS(i, visit);
		}
	}
}
void MGraph::BFSTraverse(void(*visit)(VertexType vex))
{
	int iPosPre = 0, iPosNext = 0;
	LinkQueue Q;
	InitQueue(Q);
	for (int i = 0; i < vexnum; i++) {
		visited[i] = UNVISITED;
	}
	for (int i = 0; i < vexnum; i++) {
		if (visited[i] == UNVISITED) {
			visited[i] = VISITED;
			visit(vexs[i]);
			EnQueue(Q, i);
			while (!QueueEmpty(Q)) {
				DeQueue(Q, iPosPre);
				for (iPosNext = FirstAdjVex(vexs[iPosPre]); iPosNext >= 0; iPosNext = NextAdjVex(vexs[iPosPre], vexs[iPosNext])) {
					if (visited[iPosNext] == UNVISITED) {
						visited[iPosNext] = VISITED;
						visit(vexs[iPosNext]);
						EnQueue(Q, iPosNext);
					}
				}
			}
		}
	}
	cout << endl;
}
void MGraph::Display()
{
	int iStartPos = 0;
	cout << vexnum << "个顶点," << arcnum << "条弧的";
	switch (kind) {
	case UDG:cout << "无向图"; break;
	case UDN:cout << "无向网"; break;
	case DG:cout << "有向图"; break;
	case DN:cout << "有向网"; break;
	}
	cout << "顶点依次是:" << endl;
	for (int i = 0; i < vexnum; i++) {
		cout << vexs[i] << ends;
	}
	cout << endl << "arcs[i][j]:" << endl;
	for (int i = 0; i < vexnum; i++) {
		for (int j = 0; j < vexnum; j++) {
			cout << arcs[i][j].adj << ends;
		}
		cout << endl;
	}
	cout << "information:" ;
	for (int i = 0; i < vexnum; i++) {
		if (kind == UDG || kind == UDN) {
			iStartPos = i;
		}
		else {
			iStartPos = 0;
		}
		for (int j = iStartPos; j < vexnum; j++) {
			if (arcs[i][j].info != NULL) {
				cout << "(" << vexs[i] << "," << vexs[j] << "):" << arcs[i][j].info << ends;
			}
		}
	}
	cout << endl;
}
GraphKind MGraph::GetType()
{
	return kind;
}
Status MGraph::GetSubString(char *&buf, char *sub)
{
	char *pcPos = NULL;
	int iNum = 0;
	if ((pcPos = strchr(buf, ' ')) != NULL||(pcPos = strchr(buf, '\n')) != NULL) {
		*pcPos = '\0';
		strcpy_s(sub, MAX_NAME, buf);
		buf = pcPos + 1;
		return OK;
	}
	sub = NULL;
	return ERROR;
}

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
void visit(VertexType vex)
{
	cout << vex << ends;
}