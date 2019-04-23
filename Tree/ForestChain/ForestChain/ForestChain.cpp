// ForestChain.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

#define FILENAME "ForestChain.txt"
#define FILENAME1 "ForestChain1.txt"
using namespace std;

int main()
{
	int i;
	CSTree T, p;
	Node*q = NULL;
	TElemType e, e1;
	printf("���������,���շ�? %d(1:�� 0:��) ����Ϊ%c�������Ϊ%d\n", T.TreeEmpty(), T.Root(),T.TreeDepth());
	T.CreateTree(FILENAME);
	printf("������T��,���շ�? %d(1:�� 0:��) ����Ϊ%c�������Ϊ%d\n", T.TreeEmpty(), T.Root(), T.TreeDepth());
	printf("�ȸ�������T:\n");
	T.PreOrderTraverse(visit);
	printf("\n��������޸ĵĽ���ֵ,��ֵ: ");
	cin >> e >> e1;
	T.Assign(e, e1);
	printf("��������޸ĺ����T:\n");
	T.PostOrderTraverse(visit);
	printf("\n%c��˫����%c,������%c,��һ���ֵ���%c\n", e1, T.Parent(e1), T.LeftChild(e1), T.RightSibling(e1));
	printf("������p:\n");
	p.CreateTree(FILENAME1);
	printf("���������p:\n");
	p.LevelOrderTraverse(visit);
	printf("\n����p�嵽��T�У�������T��p��˫�׽�� �������: ");
	cin >> e >> i;
	q = T.Point(e);
	T.InsertChild(q, i, p);
	printf("���������T:\n");
	T.LevelOrderTraverse(visit);
	printf("\nɾ����T�н��e�ĵ�i��������������e i: ");
	cin >> e >> i;
	q = T.Point(e);
	T.DeleteChild(q, i);
	printf("���������T:\n", e, i);
	T.LevelOrderTraverse(visit);
	printf("\n");
	T.DestroyTree();
	return 0;
}

