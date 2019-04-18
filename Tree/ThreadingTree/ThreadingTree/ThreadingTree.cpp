// ThreadingTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#define FILENAME "ThreadingTree.txt"
#define FILENAME1 "ThreadingTree1.txt"
#define FILENAME2 "ThreadingTree2.txt"
using namespace std;

int main()
{
	BiThrTree H, T;
	T.CreateBiThrTree(FILENAME); // ���������������
	H.InOrderThreading(T); // ����������Ĺ����У�����������������
	printf("�������(���)����������:\n");
	H.InOrderTraverse_Thr(visit); // �������(���)����������
	printf("\n");
	H.DestroyBiThrTree(); // ��������������
	T.CreateBiThrTree(FILENAME); // ���������������T
	H.PreOrderThreading(T); // ����������Ĺ����У�����������������
	printf("�������(���)����������:\n");
	H.PreOrderTraverse_Thr(visit);
	H.DestroyBiThrTree(); // ��������������
	T.CreateBiThrTree(FILENAME); // ���������������T
	H.PostOrderThreading(T); // �ں�������Ĺ����У�����������������
	H.DestroyBiThrTree(); // ��������������
    return 0;
}

