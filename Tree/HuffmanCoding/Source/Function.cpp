#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;
#define MAX_BUF_SIZE 50

HTNode::HTNode()
{
	weight = 0;
	parent = rchild = lchild = 0;
}

HuffmanTree::HuffmanTree()
{
	tree = NULL;
	HC = NULL;
	piWeight = NULL;
	num = 0;
}
HuffmanTree::~HuffmanTree()
{
	delete[] tree;
	tree = NULL;
	delete[] piWeight;
	piWeight = NULL;
	for (int i = 0; i <= num; i++) {
		delete[] HC[i];
		HC[i] = NULL;
	}
	delete HC;
	HC = NULL;
}
int HuffmanTree::_MinWeight(int i)
{
	unsigned int iMin = UINT_MAX;
	int iPos = 0;
	for (int j = 1; j <= i; j++) {
		if (tree[j].parent == 0&&tree[j].weight < iMin) {
			iMin = tree[j].weight;
			iPos = j;
		}
	}
	tree[iPos].parent = 1;
	return iPos;
}
void HuffmanTree::_Select(int i, int &elem1, int &elem2)
{
	elem1 = _MinWeight(i);
	elem2 = _MinWeight(i);
	if (elem2 < elem1) {
		int swap = 0;
		swap = elem1;
		elem1 = elem2;
		elem2 = swap;
	}
}
void HuffmanTree::HuffmanCoding()
{
	int iParent = 0, iChild = 0;
	int iStart = 0;
	char*pcBuf = new char[num];
	HC = new char*[num + 1];
	pcBuf[num - 1] = '\0';
	for (int i = 1; i <= num; i++) {
		iStart = num - 1;
		iChild = i;
		iParent = tree[iChild].parent;;
		while (iParent != 0) {		
			if (tree[iParent].lchild == iChild) {
				pcBuf[--iStart] = '0';
			}
			else {
				pcBuf[--iStart] = '1';
			}
			iChild = iParent;
			iParent = tree[iChild].parent;
		}
		HC[i] = new char[num - iStart];
		HC[i][num - iStart - 1] = '\0';
		for (int j = iStart; j < num- 1; j++) {
			HC[i][j-iStart] = pcBuf[j];
		}
	}
	delete[] pcBuf;
	pcBuf = NULL;
}
void HuffmanTree::HuffmanCoding1()
{
	int iLength = 2 * num - 1;
	int iPos = iLength, iCurs = 0;
	char *pcBuf = new char[num - 1];
	HC = new char*[num + 1];
	for (int i = 1; i < iLength + 1; i++) {
		tree[i].weight = 0;
	}
	while (iPos != 0) {
		if (tree[iPos].weight == 0) {
			tree[iPos].weight = 1;
			if (tree[iPos].lchild != 0) {
				pcBuf[iCurs++] = '0';
				iPos = tree[iPos].lchild;
			}
			else {
				HC[iPos] = new char[iCurs + 1];
				HC[iPos][iCurs] = '\0';
				for (int j = 0; j < iCurs; j++) {
					HC[iPos][j] = pcBuf[j];
				}
			}
		}
		else if (tree[iPos].weight == 1) {
			tree[iPos].weight = 2;
			if (tree[iPos].rchild != 0) {
				pcBuf[iCurs++] = '1';
				iPos = tree[iPos].rchild;
			}
		}
		else {
			tree[iPos].weight = 0;
			iCurs--;
			iPos = tree[iPos].parent;
		}
	}
	delete[] pcBuf;
	pcBuf = NULL;
}
void HuffmanTree::Create(char*FileName)
{
	FILE *pF = NULL;
	char arrcBuf[MAX_BUF_SIZE];
	char *pcBuf = arrcBuf;
	int iElem1 = 0, iElem2 = 0;
	if (fopen_s(&pF, FileName, "r")) {
		cout << "Can not open file." << endl;
		exit(0);
	}
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	num = atoi(pcBuf);
	tree = new HTNode[2 * num];
	fgets(pcBuf, MAX_BUF_SIZE, pF);
	for (int i = 1; pcBuf != NULL&&i <= num; i++) {
		tree[i].weight = atoi(pcBuf);
		tree[i].lchild = tree[i].rchild = tree[i].parent = 0;	
		pcBuf = strchr(pcBuf, ' ');
		if (pcBuf != NULL) {
			pcBuf += 1;
		}

	}
	for (int i = num + 1; i < 2 * num; i++) {
		_Select(i - 1,iElem1,iElem2);
		tree[iElem1].parent = i;
		tree[iElem2].parent = i;
		tree[i].lchild = iElem1;
		tree[i].rchild = iElem2;
		tree[i].weight = tree[iElem1].weight + tree[iElem2].weight;
	}
}
void HuffmanTree::Print()
{
	for (int i = 1; i <= num; i++) {
		cout << HC[i] << endl;
	}
}