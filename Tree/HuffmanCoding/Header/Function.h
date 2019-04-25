#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
typedef char **HuffmanCode;

class HTNode {
public:
	unsigned int weight;
	unsigned int parent, lchild, rchild;
public:
	HTNode();
};

class HuffmanTree {
private:
	HTNode *tree;
	HuffmanCode HC;
	int *piWeight;
	int num;
	int _MinWeight(int i);
	void _Select(int i,int &elem1,int &elem2);
public:
	HuffmanTree();
	~HuffmanTree();
	void Print();
	void Create(char*FileName);
	void HuffmanCoding();
	void HuffmanCoding1();
};
#endif