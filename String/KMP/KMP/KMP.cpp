// KMP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
using namespace std;

int main()
{
	int i, *p;
	SString s1, s2; // �Խ̿����㷨4.8֮�ϵ�����Ϊ��
	s1.StrAssign("aaabaaaab");
	printf("����Ϊ");
	s1.StrPrint();
	s2.StrAssign("aaaab");
	printf("�Ӵ�Ϊ");
	s2.StrPrint();
	s2.GetNext(); // �����㷨4.7�����next���飬����p��
	printf("�Ӵ���next����Ϊ");
	s2.PrintNext();
	i = s1.Index_KMP(s2, 1); // �����㷨4.6��ô�s2��s1���״�ƥ���λ��i
	if (i)
		printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n", i);
	else
		printf("�������Ӵ�ƥ�䲻�ɹ�\n");
	s2.GetNextval(); // �����㷨4.8�����next���飬����p��
	printf("�Ӵ���nextval����Ϊ");
	s2.PrintNext();
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n", s1.Index_KMP(s2, 1));
	return 0;
}

