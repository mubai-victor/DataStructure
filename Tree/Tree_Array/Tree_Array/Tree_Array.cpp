// Tree_Array.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Test.h"
#include "Function.h"
using namespace std;

int main()
{
	Status i;
	int j;
	position p;
	TElemType e;
	Tree T, s;
	T.CreateBiTree("Tree_Array.txt");
	cout << "������������,���շ� " << T.BiTreeEmpty() << "(1:�� 0:��) �������=" << T.BiTreeDepth()
		<< endl;
	i = T.Root(e);
	if (i)
		cout << "�������ĸ�Ϊ" << e << endl;
	else
		cout << "���գ��޸�" << endl;
	cout << "�������������:" << endl;
	T.LevelOrderTraverse(visit);
	cout << "�������������:" << endl;
	T.InOrderTraverse(visit);
	cout << "�������������:" << endl;
	T.PostOrderTraverse(visit);
	cout << "��������޸Ľ��Ĳ�� �������: ";
	cin >> p.level >> p.order;
	e = T.Value(p);
	cout << "���޸Ľ���ԭֵΪ" << e << "��������ֵ: ";
	cin >> e;
	T.Assign(p, e);
	cout << "�������������:" << endl;
	T.PreOrderTraverse(visit);
	cout << "���" << e << "��˫��Ϊ" << T.Parent(e) << ",���Һ��ӷֱ�Ϊ";
	cout << T.LeftChild(e) << "," << T.RightChild(e) << ",�����ֱֵܷ�Ϊ";
	cout << T.LeftSibling(e) << "," << T.RightSibling(e) << endl;
	cout << "����������Ϊ�յ���s:" << endl;
	s.CreateBiTree("Tree_Array1.txt");
	cout << "��s�嵽��T��,��������T����s��˫�׽�� sΪ��(0)����(1)����: ";
	cin >> e >> j;
	T.InsertChild(e, j, s);
	T.Print();
	cout << "ɾ������,�������ɾ�����������Ĳ�� ������� ��(0)����(1)����: ";
	cin >> p.level >> p.order >> j;
	T.DeleteChild(p, j);
	T.Print();
	T.ClearBiTree();
	cout << "�����������,���շ� " << T.BiTreeEmpty() << "(1:�� 0:��) �������=" << T.BiTreeDepth()
		<< endl;
	i = T.Root(e);
	if (i)
		cout << "�������ĸ�Ϊ" << e << endl;
	else
		cout << "���գ��޸�" << endl;
    return 0;
}

