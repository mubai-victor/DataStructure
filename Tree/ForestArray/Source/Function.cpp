#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;


void InitQueue(LinkQueue &q)
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (q.front == NULL)
		exit(1);
	q.front->next = NULL;
}
void DestroyQueue(LinkQueue &q)
{
	while (q.rear) {
		q.rear = q.front->next;
		free(q.front);
		q.front = q.rear;
	}
	q.rear = q.front = NULL;
}
void ClearQueue(LinkQueue &q)
{
	QueuePtr first, last;
	last = q.front->next;
	q.rear = q.front;
	q.front->next = NULL;
	while (last) {
		first = last;		
		last = last->next;	
		free(first);	
	} 
}
Status QueueEmpty(LinkQueue &q)
{
	if (!q.front->next)
		return TRUE;
	else
		return FALSE;
}
int QueueLength(LinkQueue q)
{
	QueuePtr p = q.front->next;
	int count = 0;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}
Status GetHead(LinkQueue q, QElemType &elem)
{
	if (QueueEmpty(q)) {
		return ERROR;
	}
	elem = q.front->next->data;
	return OK;
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
Status DeQueue(LinkQueue &q, QElemType &elem) {
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
void QueueTraverse(LinkQueue q, void(*func)(QElemType elem))
{
	QueuePtr p = q.front->next;
	while (p) {
		func(p->data);
		p = p->next;
	}
}

PTNode::PTNode()
{
	data = Nil;
	parent = 0;

}

PTree::PTree()
{
	InitTree();
}
void PTree::InitTree()
{
	num = 0;
	for (int i = 0; i < MAX_TREE_SIZE; i++) {
		nodes[i].data = Nil;
		nodes[i].parent = 0;
		deleted[i] = KEEP;
	}
}
void PTree::CreateTree(char*pcFileName)
{
	FILE *pF = NULL;
	char arrcBuf[50];
	char *pcBuf = arrcBuf;
	int parent = 0;
	LinkQueue Q;
	InitQueue(Q);
	EnQueue(Q,0);
	if (fopen_s(&pF, pcFileName, "r") != 0) {
		cout << "Can not open file." << endl;
		exit(0);
	}
	for (int i = 1; i < MAX_TREE_SIZE&&fgets(arrcBuf, MAX_BUF_SIZE, pF)&&!QueueEmpty(Q);) {//
		pcBuf = arrcBuf;
		while (*pcBuf != '\n') {
			Status sFlag = DeQueue(Q, parent);
			while (*pcBuf != ' '&&*pcBuf != '\n') {
				nodes[i].data = *pcBuf;
				nodes[i].parent = parent;
				EnQueue(Q, i);
				pcBuf++;
				i++;
				num++;
			}
			if (*pcBuf == ' ') {
				pcBuf++;
				if (*pcBuf == ' ' && (pcBuf-arrcBuf)%2==0) {
					pcBuf++;
				}
			}
		}
	}
}
Status PTree::TreeEmpty()
{
	return num == 0;
}
int PTree::TreeDepth()
{
	int iMax = 0, iNum = 0, iCur = 0;
	for (int i = 1; nodes[i].data != Nil; i++) {
		iCur = i;
		while (iCur != 0) {
			iNum++;
			iCur = nodes[iCur].parent;
		}
		if (iNum > iMax) {
			iMax = iNum;
		}
		iNum = 0;
	}
	return iMax;
}
TElemType PTree::Root()
{
	if (!TreeEmpty()) {
		return nodes[1].data;
	}
	else {
		return Nil;
	}
}
Status PTree::Assign(TElemType origin_elem, TElemType new_elem)
{
	for (int i = 1; nodes[i].data != Nil; i++) {
		if (nodes[i].data == origin_elem) {
			nodes[i].data = new_elem;
			return OK;
		}
	}
	return ERROR;
}
TElemType PTree::Parent(TElemType elem)
{
	for (int i = 1; nodes[i].data != Nil; i++) {
		if (nodes[i].data == elem) {
			return nodes[nodes[i].parent].data;
		}
	}
	return Nil;
}
TElemType PTree::LeftChild(TElemType elem)
{
	for (int i = 1; i<=num; i++) {
		if (nodes[i].data == elem) {
			for (int j = i + 1; j <= num; j++) {
				if (nodes[j].parent == i) {
					return nodes[j].data;
				}
			}
			return Nil;
		}
	}
	return Nil;
}
TElemType PTree::RightSibling(TElemType elem)
{
	for (int i = 1; i < num; i++) {
		if (nodes[i].data == elem) {
			if (nodes[i + 1].parent = nodes[i].parent) {
				return nodes[i + 1].data;
			}
			else {
				return Nil;
			}
		}
	}
	return Nil;
}
void PTree::Print()
{
	cout << "node" << ends << "parent" << endl;
	for (int i = 0; i <= num; i++) {
		cout << nodes[i].data << ends;
		if (nodes[i].parent != 0) {
			cout << nodes[nodes[i].parent].data;
		}
		cout << endl;
	}
}
Status PTree::InsertChild(TElemType elem, int i, PTree T)
{
	if (!T.TreeEmpty()) {
		if (num + T.num >= MAX_TREE_SIZE || i<=0) {
			return ERROR;
		}
		int iPos = 0, iInsertPos = 0;
		Status sSwap = TRUE;
		PTNode tSwap;
		for (int i = 1; i <= num; i++) {
			if (nodes[i].data == elem) {
				iPos = i;
				break;
			}
		}
		if (iPos == 0) {
			return ERROR;
		}
		iInsertPos = iPos + i;
		if (nodes[iInsertPos - 1].parent != iPos || i == 1) {
			return ERROR;
		}
		for (int j = num + T.num; j >= iInsertPos + T.num; j--) {
			nodes[j] = nodes[j - T.num];
			if (nodes[j].parent >= iInsertPos) {
				nodes[j].parent += T.num;
			}
		}
		for (int j = 0; j < T.num; j++) {
			nodes[j + iInsertPos] = T.nodes[j + 1];
			nodes[j + iInsertPos].parent += iInsertPos - 1;
		}
		nodes[iInsertPos].parent = iPos;
		num += T.num;
		/*for (int j = iInsertPos; j <= num; j++) {
			for (int k = j + 1; k <= num; k++) {
				if (nodes[j].parent > nodes[k].parent) {
					tSwap = nodes[j].parent;
					nodes[j].parent = nodes[k].parent;
					nodes[k].parent = tSwap;
				}
			}
		}*/
		while (sSwap == TRUE) {
			sSwap = FALSE;
			for (int j = iInsertPos; j < num; j++) {
				if (nodes[j].parent > nodes[j + 1].parent) {
					tSwap=nodes[j];
					nodes[j] = nodes[j + 1];
					nodes[j + 1] = tSwap;
					sSwap = TRUE;
					for (int k = j; k <= num; k++) {
						if (nodes[k].parent == j) {
							nodes[k].parent++;
						}
						else if (nodes[k].parent == j + 1) {
							nodes[k].parent--;
						}
					}
				}
			}
		}
	}
	return OK;
}
void PTree::DeleteChild(TElemType elem, int i)
{
	if (!TreeEmpty()) {
		int iPos = 0, iDelPos = 0, iSub = 0;
		TElemType tElem;
		LinkQueue Q;
		InitQueue(Q);
		tElem = LeftChild(elem);
		for (int i = 1; i <= num; i++) {
			if (nodes[i].data == tElem) {
				iPos = i;
				break;
			}
		}
		iDelPos = iPos + i - 1;
		if (iPos == 0 || iDelPos>num || i==0) {
			return;		
		}
		EnQueue(Q, iDelPos);
		while (!QueueEmpty(Q)) {
			DeQueue(Q, iDelPos);
			deleted[iDelPos] = DELETED;
			for (int i = iDelPos; i <= num; i++) {
				if (nodes[i].parent == iDelPos) {
					EnQueue(Q, i);
				}
			}
			//for (int i = iDelPos; i < num; i++) {
			//	nodes[i] = nodes[i + 1];
			//	if (nodes[i].parent > iDelPos) {
			//		nodes[i].parent--;
			//	}
			//	else if (nodes[i].parent == iDelPos) {
			//		EnQueue(Q, i);
			//	}
			//}
		}
		for (int i = 1; i <= num; i++) {
			if (deleted[i] == DELETED) {
				for (int j = i; j <= num; j++) {
					nodes[j] = nodes[j + 1];
					deleted[j] = deleted[j + 1];
					if (nodes[j].parent > i) {
						nodes[j].parent--;
					}
				}
				i--;
				num--;
			}		
		}
	}
}
void PTree::TraverseTree(void(*func)(TElemType elem))
{
	for (int i = 1; i <= num; i++) {
		func(nodes[i].data);
	}
	cout << endl;
}
TElemType PTree::Value(int pos)
{
	return nodes[pos].data;
}

void visit(TElemType elem)
{
	cout << elem << ends;
}
