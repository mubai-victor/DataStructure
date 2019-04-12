// TreeDoubleChain.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
using namespace std;

int main()
{
	int i;
	Tree T, c;
	BiTNode*p = NULL;
	TElemType e1, e2;
	printf("����ն�������,���շ� %d(1:�� 0:��)�������=%d\n", T.BiTreeEmpty(), T.BiTreeDepth());
	e1 = T.Root();
	if (e1 != Nil)
		printf("�������ĸ�Ϊ:%c\n", e1);
	else
		printf("���գ��޸�\n");
	T.CreateBiTree("TreeDoubleChain.txt");
	printf("������������,���շ� %d(1:�� 0:��) �������=%d\n", T.BiTreeEmpty(), T.BiTreeDepth());
	e1 = T.Root();
	if (e1 != Nil)
		printf("�������ĸ�Ϊ%c\n", e1);
	else
		printf("���գ��޸�\n");
	printf("����ݹ����������:\n");
	T.InOrderTraverse(visit);
	printf("\n����ݹ����������:\n");
	T.PostOrderTraverse(visit);
	//printf("\n�������������:\n");
	//T.LevelOrderTraverse(visit);
	printf("\n������һ������ֵ: ");
	cin >> e1;
	p = T.Point(e1); // pΪe1��ָ��
	printf("����ֵΪ%c\n", T.Value(p));
	printf("���ı�˽���ֵ����������ֵ: ");
	cin >> e2; // ��һ��%*c�Ե��س�����Ϊ����CreateBiTree()��׼��
	T.Assign(p, e2);
	printf("�������������:\n");
	T.LevelOrderTraverse(visit);
	e1 = T.Parent(e2);
	if (e1 != Nil)
		printf("%c��˫����%c\n", e2, e1);
	else
		printf("%cû��˫��\n", e2);
	e1 = T.LeftChild(e2);
	if (e1 != Nil)
		printf("%c��������%c\n", e2, e1);
	else
		printf("%cû������\n", e2);
	e1 = T.RightChild(e2);
	if (e1 != Nil)
		printf("%c���Һ�����%c\n", e2, e1);
	else
		printf("%cû���Һ���\n", e2);
	e1 = T.LeftSibling(e2);
	if (e1 != Nil)
		printf("%c�����ֵ���%c\n", e2, e1);
	else
		printf("%cû�����ֵ�\n", e2);
	e1 = T.RightSibling(e2);
	if (e1 != Nil)
		printf("%c�����ֵ���%c\n", e2, e1);
	else
		printf("%cû�����ֵ�\n", e2);
	printf("����һ��������Ϊ�յĶ�����c:\n");
	c.CreateBiTree("TreeDoubleChain1.txt");
	printf("����ݹ����������c:\n");
	c.PreOrderTraverse(visit);
	printf("\n�������������c:\n");
	c.LevelOrderTraverse(visit);
	printf("��c�嵽��T��,��������T����c��˫�׽�� cΪ��(0)����(1)����: ");
	cin >> e1 >> i;
	p = T.Point(e1); // p��T����c��˫�׽��ָ��
	T.InsertChild(p, i, c.Point(c.Root()));
	printf("����ݹ����������:\n");
	T.PreOrderTraverse(visit);
	printf("\n����ǵݹ����������:\n");
	T.InOrderTraverse1(visit);
	printf("ɾ������,�������ɾ��������˫�׽�� ��(0)����(1)����: ");
	cin >> e1 >> i;
	p = T.Point(e1);
	T.DeleteChild(p, i);
	printf("����ݹ����������:\n");
	T.PreOrderTraverse(visit);
	printf("\n����ǵݹ����������(��һ�ַ���):\n");
	T.InOrderTraverse2(visit);
	T.DestroyBiTree();
	return 0;
}

