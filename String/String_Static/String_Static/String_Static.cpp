// String_Static.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#include "iostream"
using namespace std;
int main()
{
	int i, j;
	Status k;
	char s, c[MAX_STR_LEN + 1];
	SString t, s1, s2;
	printf("�����봮s1: ");
	gets_s(c);
	k = s1.StrAssign(c);
	if (!k)
	{
		printf("��������MAX_STR_LEN(=%d)\n", MAX_STR_LEN);
		exit(0);
	}
	printf("����Ϊ%d ���շ� %d(1:�� 0:��)\n", s1.StrLength(), s1.StrEmpty());
	s2.StrCopy(s1);
	printf("����s1���ɵĴ�Ϊ");
	s2.StrPrint();
	printf("�����봮s2: ");
	gets_s(c);
	k = s2.StrAssign(c);
	if (!k)
	{
		printf("��������MAX_STR_LEN(%d)\n", MAX_STR_LEN);
		exit(0);
	}
	i = s1.StrCompare(s2);
	if (i<0)
		s = '<';
	else if (i == 0)
		s = '= ';
	else
		s = '>';
	printf("��s1%c��s2\n", s);
	k = s1.Concat(s2 , t);
	printf("��s1���Ӵ�s2�õ��Ĵ�tΪ");
	t.StrPrint();
	if (k == FALSE)
		printf("��t�нض�\n");
	s1.ClearString();
	printf("��Ϊ�մ���,��s1Ϊ");
	s1.StrPrint();
	printf("����Ϊ%d ���շ� %d(1:�� 0:��)\n", s1.StrLength(), s1.StrEmpty());
	printf("��t���Ӵ�,�������Ӵ�����ʼλ��,�Ӵ�����: ");
	cin >> i >> j;
//	scanf_s("%d,%d", &i,&j);
	k = t.SubString(s2, i, j);
	if (k==OK)
	{
		printf("�Ӵ�s2Ϊ");
		s2.StrPrint();
	}
	printf("�Ӵ�t�ĵ�pos���ַ���,ɾ��len���ַ���������pos,len: ");
	cin >> i >> j;	
	t.StrDelete(i, j);
	printf("ɾ����Ĵ�tΪ");
	t.StrPrint();
	i = s2.StrLength() / 2;
	s2.StrInsert(t,i);
	printf("�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t��,��s2Ϊ\n", i);
	s2.StrPrint();
	i = s2.Index(t, 1);
	printf("s2�ĵ�%d����ĸ���t��һ��ƥ��\n", i);
	s2.SubString(t, 1, 1);
	printf("��tΪ");
	t.StrPrint();
	t.Concat(t,s1);
	printf("��s1Ϊ");
	s1.StrPrint();
	k = s2.Replace( t, s1);
	if (k) // �滻�ɹ�
	{
		printf("�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ���,��s2Ϊ");
		s2.StrPrint();
	}
	s2.DestroyString(); // ���ٲ���ͬ���
	return 0;
}

