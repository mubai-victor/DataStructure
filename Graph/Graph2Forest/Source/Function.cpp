#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;
#define MAX_BUF_SIZE 100

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
	char arrcBuf[MAX_BUF_SIZE], arrcSub[MAX_NAME];
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
	if (pbox == NULL || (pbox->ivex == iPosCenter&&pbox->ilink == NULL) || (pbox->jvex == iPosCenter&&pbox->jlink == NULL)) {
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
	for (int i = vexnum - 1; i > 0; i--) {
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
	return OK;
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

//Function************************************************************
Status GetSubStr(char *sub, char *&str)
{
	char *pcPos = NULL;
	if ((pcPos = strchr(str, ' ')) != NULL || (pcPos = strchr(str, '\n')) != NULL) {
		*pcPos = '\0';
		strcpy_s(sub, MAX_NAME, str);
		str = pcPos + 1;
		return OK;
	}
	return ERROR;
}
void visit(VertexType vex)
{
	cout << vex << ends;
}
//Function of struct Node*********************************************
Node::Node()
{
	firstchild = NULL;
	nextsibling = NULL;
}

//Function of class CSTree*******************************************
void CSTree::DFSForest(AMLGraph &graph)
{
	Node *pNodeRoot = NULL, *pNode = NULL;
	for (int i = 0; i < graph.vexnum; i++) {
		graph.mark[i] = UNVISITED;
	}
	for (int i = 0; i < graph.vexnum; i++) {
		if (graph.mark[i] == UNVISITED) {
			graph.mark[i] = VISITED;
			pNode = new Node;
			pNode->firstchild = NULL;
			pNode->nextsibling = NULL;
			strcpy_s(pNode->data, graph.vexs[i].data);
			if (tree == NULL) {
				tree = pNode;
			}
			else {
				pNodeRoot->nextsibling = pNode;
			}
			pNodeRoot = pNode;
			DFSTree(graph, i, pNode);
		}
	}
}
void CSTree::DFSTree(AMLGraph &graph, int i, Node *pTree)
{
	Node*pTreeRoot = NULL, *pTreeLocal = NULL;
	int iIsVisited = UNVISITED, iNext = 0;	
	for (iNext = graph.FirstAdjVex(graph.vexs[i].data); iNext >= 0; iNext = graph.NextAdjVex(graph.vexs[i].data, graph.vexs[iNext].data)) {
		if (graph.mark[iNext] == UNVISITED) {
			graph.mark[iNext] = VISITED;
			pTreeLocal = new Node;
			pTreeLocal->firstchild = NULL;
			pTreeLocal->nextsibling = NULL;
			strcpy_s(pTreeLocal->data, graph.vexs[iNext].data);
			if (iIsVisited == UNVISITED) {
				pTree->firstchild = pTreeLocal;
				iIsVisited = VISITED;
			}
			else {
				pTreeRoot->nextsibling = pTreeLocal;
			}
			pTreeRoot = pTreeLocal;
			DFSTree(graph, iNext, pTreeRoot);
		}
	}
}
void CSTree::_PreOrderTraverse(Node*node, void(*func)(TElemType elem))
{
	func(node->data);
	if (node->firstchild != NULL) {
		_PreOrderTraverse(node->firstchild,func);
	}
	if (node->nextsibling) {
		_PreOrderTraverse(node->nextsibling,func);
	}
}
void CSTree::_DestroyTree(Node*&node)
{
	if (node != NULL) {
		if (node->firstchild != NULL) {
			_DestroyTree(node->firstchild);
		}
		if (node->nextsibling != NULL) {
			_DestroyTree(node->nextsibling);
		}
		free(node);
		node = NULL;
	}
}
int CSTree::_TreeDepth(Node*node)
{
	if (node != NULL) {
		int iDepth = 0, iMax = 1;
		if (node->firstchild == NULL) {
			return 1;
		}
		else {
			node = node->firstchild;
			while (node != NULL) {
				iDepth = _TreeDepth(node);
				if (iDepth > iMax) {
					iMax = iDepth;
				}
				node = node->nextsibling;
			}
		}
		return iMax + 1;
	}
	return 0;
}
void CSTree::_PostOrderTraverse(Node*node, void(*func)(TElemType elem))
{
	if (node != NULL) {
		_PostOrderTraverse(node->firstchild, func);
		func(node->data);
		_PostOrderTraverse(node->nextsibling, func);

	}
}
CSTree::CSTree()
{
	tree = NULL;
}
void CSTree::PreOrderTraverse(void(*func)(TElemType elem))
{
	if (!TreeEmpty()) {
		_PreOrderTraverse(tree,func);
	}
}
void CSTree::InitTree()
{
	tree = NULL;
}
void CSTree::DestroyTree()
{
	_DestroyTree(tree);
}

Status CSTree::TreeEmpty()
{
	if (tree == NULL) {
		return TRUE;
	}
	else {
		return ERROR;
	}
}
int CSTree::TreeDepth()
{
	return _TreeDepth(tree);
}


Status CSTree::InsertChild(Node*node, int i, CSTree T)
{
	if (!T.TreeEmpty()) {
		Node*pnode = NULL;
		if (i == 1) {
			T.tree->nextsibling = node->firstchild;
			node->firstchild = T.tree;
			return OK;
		}
		else {
			int j = 2;
			pnode = tree->firstchild;
			for (; pnode!=NULL&&pnode->nextsibling != NULL&&j < i; j++) {
				pnode = pnode->nextsibling;
			}
			if (i == j) {
				T.tree->nextsibling = pnode->nextsibling;
				pnode->nextsibling = T.tree;
			}
		}
	}
	return ERROR;
}
Status CSTree::DeleteChild(Node*node, int i)
{
	if (node != NULL&&node->firstchild != NULL) {
		Node*pnode = node->firstchild;
		if (i == 1) {
			node->firstchild = pnode->nextsibling;
			pnode->nextsibling = NULL;
			_DestroyTree(pnode);
			return OK;
		}
		else {
			for (int j = 2; j < i&&pnode->nextsibling != NULL; j++) {
				pnode = pnode->nextsibling;
			}
			if (pnode->nextsibling != NULL) {
				pnode->nextsibling = pnode->nextsibling->nextsibling;
				pnode->nextsibling->nextsibling = NULL;
				_DestroyTree(pnode->nextsibling);
				return OK;
			}
		}
	}
	return ERROR;
}
void CSTree::PostOrderTraverse(void(*func)(TElemType elem))
{
	_PostOrderTraverse(tree, func);
}

