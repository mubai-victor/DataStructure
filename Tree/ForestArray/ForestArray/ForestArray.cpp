// ForestArray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
using namespace std;
#define FILENAME	"ForestArray.txt"
#define FILENAME1	"ForestArray1.txt"

int main()
{
	int i;
	PTree T, p;
	TElemType e, e1;
	printf("���������,���շ�? %d(1:�� 0:��)����Ϊ%c�������Ϊ%d\n", T.TreeEmpty(), T.Root(),T.TreeDepth());
	T.CreateTree(FILENAME);
	printf("������T��,���շ�? %d(1:�� 0:��)����Ϊ%c�������Ϊ%d\n", T.TreeEmpty(), T.Root(),T.TreeDepth());
	printf("���������T:\n");
	T.TraverseTree(visit);
	printf("��������޸ĵĽ���ֵ,��ֵ: ");
	cin >> e >> e1;
	T.Assign(e, e1);
	printf("��������޸ĺ����T:\n");
	T.TraverseTree(visit);
	printf("%c��˫����%c,������%c,��һ���ֵ���%c\n", e1, T.Parent(e1), T.LeftChild(e1),T.RightSibling(e1));
	printf("������p:\n");
	p.InitTree();
	p.CreateTree(FILENAME1);
	printf("���������p:\n");
	p.TraverseTree(visit);
	printf("����p�嵽��T�У�������T��p��˫�׽��,�������: ");
	cin >> e >> i;
	T.InsertChild(e, i, p);
	T.Print();
	printf("ɾ����T�н��e�ĵ�i��������������e i: ");
	cin >> e >> i;
	T.DeleteChild(e, i);
	T.Print();
	return 0;
}

